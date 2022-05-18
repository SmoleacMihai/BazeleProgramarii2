#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define LMAX 50

struct consumator
{
    char name[LMAX];
    int Telefon;
};

struct Node
{
    consumator inf;
    Node *next;
};

Node *newNode(consumator consumatorInf)
{
    Node *newElement = (Node *)malloc(sizeof(struct Node));
    strcpy(newElement->inf.name, consumatorInf.name);
    newElement->inf.Telefon = consumatorInf.Telefon;
    newElement->next = NULL;
}

bool isEmpty(Node *list)
{
    return list == NULL;
}

void insert(Node *&list, consumator pers)
{
    Node *newElement = newNode(pers);
    if (isEmpty(list))
    {
        list = newElement;
        return;
    }
    else
    {
        Node *l = list;
        while (!isEmpty(l->next))
        {
            l = l->next;
        }
        l->next = newElement;
    }
}

// Node *findMinim(Node *list)
// {
//     int minim = list->inf.Telefon;
//     Node *min_adress = list;
//     while (!isEmpty(list))
//     {
//         if (list->inf.Telefon < minim)
//         {
//             minim = list->inf.Telefon;
//             min_adress = list;
//         }
//         list = list->next;
//     }
//     return min_adress;
// }

Node *searchByName(Node *list)
{
    char name[LMAX];
    cout << "\n\nIntroduceti numele: ";
    cin >> name;
    while (!isEmpty(list))
    {
        if (strcmp(list->inf.name, name) == 0)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

void deleteNode(Node *&list, Node *node)
{
    if (isEmpty(list))
    {
        return;
    }
    if (list == node)
    {
        list = list->next;
        return;
    }
    Node *l = list;
    while (l->next != node)
    {
        l = l->next;
    }
    l->next = node->next;
    free(node);
}

void printList(Node *list)
{
    while (!isEmpty(list))
    {
        cout << list->inf.name << " " << list->inf.Telefon << endl;
        list = list->next;
    }
}

void printconsumator(Node *list)
{
    cout << "Name: " << list->inf.name << endl;
    cout << "Telefon: " << list->inf.Telefon << endl;
}

int main()
{
    Node *consumator_list = NULL;
    int nr;
    char nume[21];
    consumator guy;
    cout << "Numarul de angajati este -> ";
    cin >> nr;

    int count = 0;
    while (count < nr)
    {
        cout << "Name: ";
        cin >> guy.name;
        cout << "Telefon: ";
        cin >> guy.Telefon;
        cout << endl;
        insert(consumator_list, guy);
        count++;
    }

    printList(consumator_list);

    Node *temp = searchByName(consumator_list);
    deleteNode(consumator_list, temp);

    cout << "\n\nLista dupa stergerea persoanei: \n";
    printList(consumator_list);
    // printf("\n\n Angajatul cu varsta minima:\n");
    // printconsumator(findMinim(consumator_list));

    return 0;
}
