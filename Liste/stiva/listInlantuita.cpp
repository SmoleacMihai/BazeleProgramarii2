#include <iostream>
using namespace std;
struct Nod
{
    int data;
    Nod *next;
};

Nod *newNode(int data)
{
    Nod *nodNou = new Nod();
    nodNou->data = data;
    nodNou->next = NULL;
    return nodNou;
}

bool isEmpty(Nod *top)
{
    return top == NULL;
}

void push(Nod *&top, int data)
{
    Nod *nodNou = newNode(data);
    nodNou->next = top;
    top = nodNou;
}

int pop(Nod *&top)
{
    if (isEmpty(top))
        return 0;
    Nod *tmp = top;
    top = top->next;
    int rezultat = tmp->data;
    delete tmp;
    return rezultat;
}

int peek(Nod *top)
{
    if (isEmpty(top))
        return 0;
    return top->data;
}

int main()
{
    Nod *top = NULL;
    int input, count = 0, product = 1;
    // se introduc numere pana se introduce 0
    // faceti stiva din valorile introduse
    // afisati stiva
    // produsul elementelor pozitive
    while (input != 0)
    {
        cin >> input;
        push(top, input);
        count++;
    };
    cout << endl;
    for (int i = 1; i <= count; i++)
    {
        if (peek(top) > 0)
            product *= peek(top);
        cout << pop(top) << endl;
    }
    cout << "Produsul elementelor stivei este: " << product;

    return 0;
}