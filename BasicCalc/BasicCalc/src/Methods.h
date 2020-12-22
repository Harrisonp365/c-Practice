/*#include "Token.h"
#include "Token_stream.h"
#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

Token_stream ts; // provides get() and putback()

double expression();   // read and evaluate a Expression

double term();   // read and evaluate a Term

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
        cout << result << expression << "\n";
    }
    catch (exception& e)
    {
        cerr << e.what() << "\n";
        cleanUpMess();
    }
}
*/