#include <iostream>

using namespace std;

void PrintMenu(){
    cout << "\n\nAlegeti operatia:\n\n";
    cout << "1 - Sa se verifice apartenenta unui element la un vector X: Vector\n";
    cout << "2 - Sa se afiseze recursiv elementele unui vector\n";
    cout << "3 - Sa se afiseze invers recursiv continutul unui vector.\n";
    cout << "4 - Sa se inverseze recursiv continutul unui vector.\n";
    cout << "* - Exit\n\n";
}

bool find(int a[], unsigned sizeOfArray, int valueToFind)
{
    if (sizeOfArray == 0) return false;
    else if (sizeOfArray == 1) return (a[0] == valueToFind);
    else
    {
        if (a[sizeOfArray - 1] == valueToFind) return true;
        else
        {
           return find(a, sizeOfArray - 1, valueToFind);
        }
    }
}

void printElements(int x[], int sizeArray)
{
    if (1 == sizeArray)
    {
        cout << x[0] << ", ";
        return;
    }
    printElements(x, sizeArray - 1);
    cout << x[sizeArray - 1] << ", ";
}

void printElementsReverse(int x[], int sizeArray)
{
    if (1 == sizeArray)
    {
        cout << x[0] << ", ";
        return;
    }
        cout << x[sizeArray - 1] << ", ";
        printElementsReverse(x, sizeArray - 1);

}

void reverseArray(int x[], int indexLeft, int indexRight)
{   
    if (indexLeft < indexRight){
        swap(x[indexLeft], x[indexRight]);
        reverseArray(x, indexLeft + 1, indexRight - 1);   
    }
}

int main(){
    int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int choice, toFind;
    int firstElement = x[0];
    int sizeArray = 20;
    bool found;
    menu:
    PrintMenu();
    cout << "Operatia alesa: "; cin >> choice;
    cout << "\n";
    switch (choice)
    {
    case 1:
        cout << "Indicai elementul: ";
        cin >> toFind;
        if(find(x, sizeArray, toFind)) cout << "Elementul " << toFind << " apartine vectorului x[1..20]";
        else cout << "Elementul " << toFind << " nu apartine vectorului x[1..20]";
        goto menu;

    case 2:
        printElements(x, sizeArray);
        goto menu;

    case 3:
        printElementsReverse(x, sizeArray);
        goto menu;

    case 4:
        reverseArray(x, 0, sizeArray - 1);
        printElements(x, sizeArray);
        goto menu;

    default:
        break;
    }
    return 0;
}