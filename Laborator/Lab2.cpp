#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define LMAX 50

struct person
{
    char name[LMAX];
    int age;
};

struct Node
{
    person inf;
    Node *next;
};

Node *newNode(person personInf)
{
    Node *newElement = (Node *)malloc(sizeof(struct Node));
    strcpy(newElement->inf.name, personInf.name);
    newElement->inf.age = personInf.age;
    newElement->next = NULL;
}

bool isEmpty(Node *list)
{
    return list == NULL;
}

void insert(Node *&list, person pers)
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

Node *findMinim(Node *list)
{
    int minim = list->inf.age;
    Node *min_adress = list;
    while (!isEmpty(list))
    {
        if (list->inf.age < minim)
        {
            minim = list->inf.age;
            min_adress = list;
        }
        list = list->next;
    }
    return min_adress;
}

void printList(Node *list)
{
    while (!isEmpty(list))
    {
        cout << list->inf.name << " " << list->inf.age << endl;
        list = list->next;
    }
}

void printPerson(Node *list)
{
    cout << "Name: " << list->inf.name << endl;
    cout << "Age: " << list->inf.age << endl;
}

int main()
{
    Node *person_list = NULL;
    int nr;
    person guy;
    cout << "Numarul de angajati este -> ";
    cin >> nr;

    int count = 0;
    while (count < nr)
    {
        cout << "Name: ";
        cin >> guy.name;
        cout << "Age: ";
        cin >> guy.age;
        cout << endl;
        insert(person_list, guy);
        count++;
    }
    printList(person_list);
    printf("\n\n Angajatul cu varsta minima:\n");
    printPerson(findMinim(person_list));

    return 0;
}
