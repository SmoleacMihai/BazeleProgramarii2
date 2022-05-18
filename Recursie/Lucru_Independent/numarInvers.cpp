#include <iostream>

using namespace std;

void reverseNumber(int n)
{
    if (n < 10)
    {
        cout << n;
        return;
    }
    else
    {
        cout << n % 10;
        reverseNumber(n / 10);
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    cout << "n reversat: ";
    reverseNumber(n);
    return 0;
}