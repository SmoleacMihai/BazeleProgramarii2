#include <iostream>

using namespace std;

int countVowels(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 5;
    cout << "\n"
         << &n << "\n";
    int *ptr = &n;
    cout << ptr << endl;
    return 0;
}
