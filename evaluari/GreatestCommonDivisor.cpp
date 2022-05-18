#include <iostream>

using namespace std;
int GreatestDivisor(int n1, int n2)
{
    if (n1 == 0)
        return n2;

    if (n2 == 0)
        return n1;

    if (n1 == n2)
        return n1;

    if (n1 > n2)
        return GreatestDivisor(n1 - n2, n2);
    return GreatestDivisor(n1, n2 - n1);
}

int main()
{
    int n1, n2;
    cout << "n1 = ";
    cin >> n1;
    cout << "n2 = ";
    cin >> n2;
    int Divizor = GreatestDivisor(n1, n2);
    cout << "Divizorul cel mai mare este " << Divizor;
    return 0;
}