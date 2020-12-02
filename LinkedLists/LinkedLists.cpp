#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    shared_ptr<Node> next;
    Node(string aName) { name = aName; next = nullptr; }
};
int main(int argc, char *argv[])
{
    Node* root = nullptr;
    Node* p_node, * new_node;
    string a_name;

    while (true)
    {
        cout << "Enter a name (or ENTER to exit): ";
        getline(cin, a_name);
        if (a_name.empty())
            break;
        new_node = new Node(a_name);

        //if list is new or node goes at the beginning, then insert as root node else after

        if (root == nullptr || a_name < root->name)
        {
            new_node->next = root;
            root = new_node;
        }
        else
        {
            p_node = root;
            while (p_node->next && a_name > p_node->next->name)
            {
                p_node = p_node->next;
            }
            new_node->next = p_node->next;
            p_node->next = new_node;
        }
    }

    p_node = root; //print all nodes
    while (p_node)
    {
        cout << p_node->name << endl;
        p_node = p_node->next;
    }

    return 0;
}