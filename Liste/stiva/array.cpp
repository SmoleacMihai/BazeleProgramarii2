#include <iostream>
using namespace std;
const int LIM = 100;

bool isEmpty(int k)
{
    if (k == 0)
        return true;
    return false;
}

void push(int stiva[], int &k, int numar)
{
    k = k + 1;
    stiva[k] = numar;
}

int peek(int stiva[], int k)
{
    return stiva[k];
}

int pop(int stiva[], int &k)
{
    int rezultat = peek(stiva, k);
    k = k - 1;
    return rezultat;
}

int size(int k)
{
    return k;
}

int main()
{
    int stiva[LIM], k = 0, input;
    do
    {
        cin >> input;
        push(stiva, k, input);
    } while (input != 0);

    cout << pop(stiva, k);
    cout << pop(stiva, k);
    cout << pop(stiva, k);
    cout << pop(stiva, k);
    cout << pop(stiva, k);
    return 0;
}