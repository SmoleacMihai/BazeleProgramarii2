#include <iostream>
#include <string.h>

using namespace std;

// struct Carte
// {
//     string culoare;
//     int age;
// };

struct node
{
    char culoare[6];
    struct node *next;
};

bool isEmpty(node *nod)
{
    return nod == NULL;
}

char randomColor(char color[6])
{
    int randomBit = rand() % 2;
    if (randomBit)
        strcpy(color, "Rosu");
    else
        strcpy(color, "Negru");
}

void PrintList(node *nod)
{
    while (nod != NULL)
    {
        cout << nod->culoare << endl;
        nod = nod->next;
    }
}

int main()
{
    node *head = NULL;
    int n = 0;
    char color[6];
    char curentColor[6];
    int rosu = 0, negru = 0;
    // for (int i = 1; i <= 32; i++, rosu++, negru++)
    // {
    //     if (rosu < 16)
    //         strcpy(curentColor, "Rosu");
    //     else
    //         strcpy(curentColor, "Negru");
    //     node *nod = new node;
    //     strcpy(nod->culoare, curentColor);
    //     nod->next = head;
    //     head = nod;
    // }
    // create a list with equally random distributed colors
    for (int i = 1; i <= 32; i++)
    {
        randomColor(color);
        node *nod = new node;
        strcpy(nod->culoare, color);
        nod->next = head;
        head = nod;
    }

    PrintList(head);

    return 0;
}