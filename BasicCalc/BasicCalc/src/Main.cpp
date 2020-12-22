//#include "Token_stream.h"
#include "std_lib_facilities.h"
//#include "Methods.h"
using namespace std;

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
    Token() :kind{ 0 } {}
    Token(char ch) :kind{ch}{}
    Token(char ch, double val) :kind(ch), value(val) {}
    Token(char ch, string n) :kind{ch}, name{n} {}
};

class Token_stream {
public:
    //const char number = '8';
    //const char quit = 'q';
    //const char print = ';';

    Token get();            // get a Token
    void putback(Token t);  // put a Token back
    void ignore(char c);    // discard characters up to and incl c

private:
    bool full{ false };      // is there a Token in the buffer?
    Token buffer = { 0 };         // where we store a 'putback' Token
};

class Variable {
public:
    string name;
    double value;
};

vector<Variable>var_table;
const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a'; // name token
const char let = 'L'; // declaration token 
const string declkey = "let"; // declaration keyword
const string prompt = "> ";
const string result = "= ";

Token_stream ts; // provides get() and putback()
double expression();   // read and evaluate a Expression
double term();   // read and evaluate a Term

bool is_declared(string var) //is var already in the table
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double define_name(string var, double val) //add var,val to var_table
{
    if (is_declared(var))error(var, "declared twice");
    var_table.push_back(Variable{ var, val });
    return val;
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name)error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')error("= missing in declaration of ", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case number:         // return the numbers value
        return t.value;  // return the number's value
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

void Token_stream::ignore(char c)
{
    //look in the buffer
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    //search input
    char ch = 0;
    while (cin >> ch)
        if (ch == c)return;
}

Token Token_stream::get()
{   //read characters from cin and compose a Token
    if (full) { //check if we already have a token ready
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch) {
    case print:
    case quit:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token{ ch };   // let each character represent itself
    case '.': // a floating point can start with a '.'
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{ number, val };
    }
    default:
        if (isalpha(ch))
        {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == declkey)return Token{ let };
            return Token{ name, s };
        }
        error("Bad Token");
    }
}

void cleanUpMess()
{
    ts.ignore(print);
}

void calculate()
{
    while (cin)
        try
        {
            cout << "Too add multipule expressions please end them with';' eg. 2+5; 8*3; \n";
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
                if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << "\n";
        }
    catch (exception& e)
    {
        cerr << e.what() << "\n";
        cleanUpMess();
    }
}

int main()
{
   try
    {
       define_name("pi", 3.1415926535);
       define_name("e", 2.7182818284);
        calculate();
        return 0;
    }

    catch (exception& e)
    {
        cerr << e.what() << "\n";
        return 1;
    }

    catch (...) {
        cerr << "exception \n";
        return 2;
    }
}

double expression()   // read and evaluate a Expression
{
    double left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double term()   // read and evaluate a Term
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '*':
            left *= term();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            int i1 = narrow_cast<int>(left); // Ensure input is of type int
            int i2 = narrow_cast<int>(primary());
            if (i2 == 0)error("%:divides by zero");
            left = i1 % i2;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}


