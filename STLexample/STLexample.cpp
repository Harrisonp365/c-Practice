#include <list>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string s;
    list<string> LS;
    list<string>::iterator iter;

    while (true)
    {
        cout << "Enter string (ENTER to exit): ";
        getline(cin, s);
        if (s.size() == 0)
            break;
        LS.push_back(s);
    }
    LS.sort(); // sort and then print elements
    
    for (iter = LS.begin(); iter != LS.end(); iter++)
    cout << *iter << endl;

    return 0;
}
