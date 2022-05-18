// P(n) = 1 * 4 * 7 * ... * (3n-2)

#include<iostream>
using namespace std;

int P(int n){
    if(n == 1){
        return 1;
    }else{
        return (3*n - 2) * P(n - 1);
    }
}

int main(){
    int n;
    cout << "Input a number : ";
    cin >> n;
    cout << "The multiplication of first " << n <<" factors is : " << P(n);
    return 0;
}
