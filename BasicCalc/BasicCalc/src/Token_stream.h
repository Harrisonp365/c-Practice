#pragma once
#include "Token.h"

//const char GLOBAL_CONST_VAR = 0xFF;

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