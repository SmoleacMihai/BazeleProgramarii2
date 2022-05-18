#include <iostream>

using namespace std;
int SumaCifrelor(int n)
{
    if (n == 0)
        return 0;
    return (n % 10 + SumaCifrelor(n / 10));
}
int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int Suma = SumaCifrelor(n);
    cout << "Suma ciferelor numarului " << n << " este " << Suma;
    return 0;
}