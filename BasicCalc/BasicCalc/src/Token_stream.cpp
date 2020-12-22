/*#include "Token.h"
#include "Token_stream.h"
#include "Methods.h"
#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';

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
        error("Bad Token");
    }
}
*/

