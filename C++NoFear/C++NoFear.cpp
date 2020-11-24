// C++NoFear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int rand_0toN1(int n);
void draw_a_card();

const char* suits[4] = { "hearts", "diamonds", "spades", "clubs" };

const char *ranks[13] = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};

int main()
{
    int n, i;

    srand(time(NULL));
    
    while (1)
    {
        cout << "Enter number of cards to draw";
        cout << "(0 to exit)";
        cin >> n;

        if (n == 0)
            break;
        for (i = 1; i <= n; i++)
            draw_a_card();
    }
    return 0;
}


void draw_a_card()
{
    int r;
    int s;

    int card;

    card = rand_0toN1(52); //get rand number from 0 - 51
    r = card % 13;
    s = card / 13;

    r = rand_0toN1(13);
    s = rand_0toN1(4);
    cout << ranks[r] << " of " << suits[s] << endl;
}

int rand_0toN1(int n)
{
    return rand() % n;
}