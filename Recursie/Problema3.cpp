// Să se calculeze recursive produsul elementelor unui vector
#include <iostream>

using namespace std;

int P(int a[], unsigned n)
{
    if (n == 1) return a[0];
    else return (a[n - 1] * P(a, n - 1));
}

int main(){
    unsigned n;
    cout << "Number of elements : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = (rand() % 10) - 5;
    }
    cout << "The array : ";
    for (int i = 0; i < n; i++){
        cout << "\na[" << i + 1 << "]=" << a[i];
        }
    cout << "\nProduct of elements in array : " << P(a, n);
    return 0;
}