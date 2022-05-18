/* De la tastatură se introduce un număr natural N. Să se elaboreze un program care
elimină cifrele impare dintr-un număr și afișează numărul obținut.*/
#include <iostream>
using namespace std;

bool Odd(int nr){
   return (nr % 2 != 0);
}

void OddRemover(int &n){
    int digit = n % 10;
    if(n == 0)return;
    
    if(Odd(digit)&&(n != 0)){
        n = n / 10;
        OddRemover(n);
    }
    else
    {
        n = n / 10;
        OddRemover(n);
        cout << digit;
    }
    return;
}
int main(){
    int n;
    cout << "Dati un numar "; 
    cin >> n;
    OddRemover(n);
    return 0;
}