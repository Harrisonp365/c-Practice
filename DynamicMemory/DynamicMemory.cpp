#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* ptr;

public:
    String();
    String(char* s);
    String(const String& src);
    ~String();

    String& operator=(const String& src) { cpy(src.ptr); return *this; }
    String& operator=(char* s) { cpy(s); return *this; }
    String operator+(char* s);

    operator char* () { return ptr; }
    int operator==(const String& other);
    
    void cat(char* s);
    void cpy(char* s);
};

int main()
{
    String a, b, c;

    a = "I ";
    b = "really ";
    c = "love ";
    String d = a + b + c + "C++!\n";
    cout << d;

    return 0;
}

String::String() {
    ptr = new char[1];
    ptr[0] = '\0';
}

String::String(char* s) {
    int n = strlen(s);
    ptr = new char[n + 1];
    strcpy(ptr, s);
}

String::String(const String& src) {
    int n = strlen(src.ptr); //getting length of current string minus \0
    ptr = new char[n + 1]; //assigning new mem lenght for new string plus \0
    strcpy(ptr, src.ptr); // deep copy the string
}

String::~String() {
    delete[] ptr;
}

int String::operator==(const String& other) {
    return(strcmp(ptr, other.ptr) == 0);
}

String String::operator+(char* s) {
    String new_str(ptr);
    new_str.cat(s);
    return new_str;
}

void String::cpy(char* s) {
    delete[] ptr;
    int n = strlen(s);
    ptr = new char[n + 1];
    strcpy(ptr, s);
}

void String::cat(char* s) {
    int n = strlen(ptr) + strlen(s); // allocate sufficent room for new string 
    char* p1 = new char[n + 1]; // allocate sufficent room for new string 
    //Copy data to new mem block
    strcpy(p1, ptr);
    strcat(p1, s); 
    //relase old mem
    delete[] ptr;
    ptr = p1;
}