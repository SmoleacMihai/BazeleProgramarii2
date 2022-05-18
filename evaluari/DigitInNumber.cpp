#include <iostream>

using namespace std;
// int nrDeCifre(int n, int x)
// {
//     if (n == 0)
//         return 0;
//     int digit = n % 10;
//     if (digit == x)
//         return 1 + nrDeCifre(n / 10, x);

//     return nrDeCifre(n / 10, x);
// }

// void P4()
// {
//     int Nr, B;
//     Nr = 0;
//     B = 0;
//     long int a = 5276483;
//     do
//     {
//         if ((a % 2) == 1)
//         {
//             B = B * 10 + a % 10;
//         }
//     } while (a != 0);
// }
void Imp_cifre(int n)
{
    if (n <= 0)
        return;
    int digit = n % 10;
    if (!(digit % 2 == 0))
        cout << digit;
    Imp_cifre(n / 10);
}
int main()
{
    int X, number;
    cin >> number;
    Imp_cifre(number);
    return 0;
}