// S(n) = 1 + 3 + 5 + ... + (2n - 1)

#include<iostream>
using namespace std;

int S(int n){
    if(n == 1){
        return 1;
    }else{
        return 2*n - 1 + S(n - 1);
    }
}

int main(){
    int n;
    cout << "Input a number : ";
    cin >> n;
    cout << "The sum of first "<< n << " numbers is : " << S(n);
    return 0;
}
