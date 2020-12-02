#include <iostream>

class Node {
public:
    string name;
    node* next;
    node(string aName) { name = aName; mext = nullptr; }
};
int main()
{
    std::cout << "Hello World!\n";
}