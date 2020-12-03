#include <iostream>
using namespace std;

#define MAX_LEVELS 10
//The goal is to move the stack to the other side. You are not allowed put a larger ring on a smaller ring

//define 3 stacks uisng arrays to contain the objects

class MyStack {
public:
    int rings[MAX_LEVELS]; //array of ring values
    int tos; //topOfStack index
    void populate(int size); //init stack
    void clear(int sizze);
    void push(int n);
    int pop();
} stacks[3];

void MyStack::populate(int size)
{
    for (int i = 0; i < size; i++)
        rings[i] = i + 1;
    tos = -1;
}

void MyStack::clear(int size)
{
    for (int i = 0; i < size; i++)
        rings[i] = 0;
    tos = size - 1;
}

void MyStack::push(int n) 
{
    rings[tos--] = n;
}

int MyStack::pop()
{
    int n = rings[++tos];
    rings[tos] = 0;
    return n;
}

void move_stacks(int src, int dest, int other, int n);
void move_a_ring(int source, int dest);
void print_stacks();
void pr_chars(int ch, int n);

int stack_size = 7;

int main()
{
    stacks[0].populate(stack_size);
    stacks[1].clear(stack_size);
    stacks[2].clear(stack_size);
    print_stacks();
    move_stacks(stack_size, 0, 2, 1);

    return 0;
}

//Move stacks and solve problem recursively  src= source stack  dest = destination stack

void move_stacks(int n, int src, int dest, int other)
{
    if (n == 1)
        move_a_ring(src, dest);
    else
    {
        move_stacks(n - 1, src, other, dest);
        move_a_ring(src, dest);
        move_stacks(n - 1, other, dest, src);
    }
}

//move a ring... pop off ring from source place on dest stack and print new state

void move_a_ring(int source, int dest)
{
    int n = stacks[source].pop(); // pop off source
    stacks[dest].push(n); //push onto dest
    print_stacks(); //show new state
}

//for each level print the ring for each of the 3 stacks

void print_stacks()
{
    int n = 0;
    for (int i = 0; i < stack_size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            n = stacks[j].rings[i];
            pr_chars(' ', 12 - n);
            pr_chars('*', 2 * n);
            pr_chars(' ', 12 - n);
        }
        cout << endl;
    }
    system("PAUSE");
}

void pr_chars(int ch, int n)
{
    for (int i = 0; i < n; i++)
        cout << (char)ch;
}