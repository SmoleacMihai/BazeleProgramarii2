#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAXLEN 150

using namespace std;

struct Elev
{
    int id;
    char name[MAXLEN];
    float firstAvg;
    float secondAvg;
    float infAvg;
};

struct Node
{
    Elev inf;
    Node *left;
    Node *right;
};

Node *newNode(Elev elev)
{
    Node *newElement = (Node *)malloc(sizeof(struct Node));
    newElement->inf.id = elev.id;
    strcpy(newElement->inf.name, elev.name);
    newElement->inf.firstAvg = elev.firstAvg;
    newElement->inf.secondAvg = elev.secondAvg;
    newElement->inf.infAvg = elev.infAvg;
    newElement->left = NULL;
    newElement->right = NULL;
    return newElement;
}

bool isEmpty(Node *root)
{
    return root == NULL;
}

void inserare(Node *&root, Elev elev)
{
    Node *newElement = newNode(elev);
    if (isEmpty(root))
    {
        root = newElement;
        return;
    }
    if (root->inf.id == elev.id)
    {
        cout << "Elev cu acest numar de ordine este deja in arbore" << endl;
    }
    if (root->inf.id > elev.id)
    {
        if (!isEmpty(root->left))
        {
            inserare(root->left, elev);
            return;
        }
        else
        {
            root->left = newElement;
            return;
        }
    }
    else if (root->inf.id < elev.id)
    {
        if (!isEmpty(root))
        {
            inserare(root->right, elev);
            return;
        }
        else
        {
            root->right = newElement;
            return;
        }
    }
}

void creare(Node *&root)
{
    Elev elev;
    cout << "Citim datele elevului pentru inserare" << endl;
    cout << "Numarul de ordine: ";
    cin >> elev.id;
    if (elev.id != 0)
    {
        fflush(stdin);
        cout << "Nume: ";
        gets(elev.name);
        cout << "Nota medie semestrul 1: ";
        cin >> elev.firstAvg;
        cout << "Nota medie semestrul 2: ";
        cin >> elev.secondAvg;
        elev.infAvg = (elev.firstAvg + elev.secondAvg) / 2;
        cout << "Media anuala la informatica: " << elev.infAvg << "\n\n";
        inserare(root, elev);
        while (elev.id != 0)
        {
            cout << "Numarul de ordine: ";
            cin >> elev.id;
            if (elev.id == 0)
                break;
            fflush(stdin);
            cout << "Nume: ";
            gets(elev.name);
            cout << "Nota medie semestrul 1: ";
            cin >> elev.firstAvg;
            cout << "Nota medie semestrul 2: ";
            cin >> elev.secondAvg;
            elev.infAvg = (elev.firstAvg + elev.secondAvg) / 2;
            cout << "Media anuala la informatica: " << elev.infAvg << "\n\n";
            inserare(root, elev);
        }
    }
}

void SRD(Node *root)
{
    if (isEmpty(root))
        return;
    SRD(root->left);
    cout << root->inf.id << " " << root->inf.name << " " << root->inf.firstAvg << " " << root->inf.secondAvg << " "
         << root->inf.infAvg;
    cout << endl;
    SRD(root->right);
}

Node *minValue(Node *root)
{
    Node *node = root;
    while (!isEmpty(node) && isEmpty(node->left))
    {
        node = node->left;
    }
    return node;
}

Node *deleteNode(Node *&root, int id)
{
    if (isEmpty(root))
        return root;
    if (id < root->inf.id)
        root->left = deleteNode(root->left, id);
    else if (id > root->inf.id)
        root->right = deleteNode(root->right, id);
    else
    {
        if (isEmpty(root->left))
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (isEmpty(root->right))
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = minValue(root->right);
        root->inf.id = temp->inf.id;
        strcpy(root->inf.name, temp->inf.name);
        root->inf.firstAvg = temp->inf.firstAvg;
        root->inf.secondAvg = temp->inf.secondAvg;
        root->inf.infAvg = temp->inf.infAvg;
        root->right = deleteNode(root->right, temp->inf.id);
    }
    return root;
}

Node *search(Node *root, int id)
{
    if (isEmpty(root) || root->inf.id == id)
        return root;
    if (root->inf.id < id)
        return search(root->right, id);
    return search(root->left, id);
}

void modifyAvg(Node *root, int id, float newAvg)
{
    Node *element = search(root, id);
    if (element == NULL)
        cout << "Nu exista elev cu asa un numar de ordine" << endl;
    element->inf.infAvg = newAvg;
}

void printDescending(Node *root)
{
    if (isEmpty(root))
        return;
    printDescending(root->right);
    cout << root->inf.id << " " << root->inf.name << " " << root->inf.firstAvg << " " << root->inf.secondAvg << " "
         << root->inf.infAvg;
    cout << endl;
    printDescending(root->left);
}

void printAvgBetween(Node *root, float firstAvg, float secondAvg)
{
    if (isEmpty(root))
        return;
    if (root->inf.infAvg > firstAvg && root->inf.infAvg < secondAvg)
        cout << root->inf.id << " " << root->inf.name << " " << root->inf.firstAvg << " " << root->inf.secondAvg << " "
             << root->inf.infAvg << endl;
    printAvgBetween(root->left, firstAvg, secondAvg);
    printAvgBetween(root->right, firstAvg, secondAvg);
}

void printElev(Node *root, int id)
{
    Node *element = search(root, id);
    if (element == NULL)
        cout << "Nu exista elev cu asa un numar de ordine" << endl;
    else
    {
        cout << "Nume: " << element->inf.name << endl;
        cout << "Nota medie semestrul 1: " << element->inf.firstAvg << endl;
        cout << "Nota medie semestrul 2: " << element->inf.secondAvg << endl;
        cout << "Media anuala la informatica: " << element->inf.infAvg << endl;
    }
}

void printElevs(Node *root)
{
    if (isEmpty(root))
        return;
    printElevs(root->right);
    cout << root->inf.id << " " << root->inf.name << " " << root->inf.firstAvg << " " << root->inf.secondAvg << " "
         << root->inf.infAvg;
    cout << endl;
    printElevs(root->left);
}

int main()
{
    Node *root = NULL;
    creare(root);
    int id, first, opt;
    do
    {
        system("cls");
        SRD(root);
        cout << "\n\n1. Modifica media anuala la informatica" << endl;
        cout << "2. Sterge elevul cu asa un numar de ordine" << endl;
        cout << "3. Afiseaza elevii in ordine descrescatoare" << endl;
        cout << "4. Afisarea elevilor cu mediile semestriale cuprinse intre doua valori care se citesc de la tastatura." << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiunea: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "Introduceti numarul de ordine: ";
            cin >> id;
            cout << "Introduceti media anuala la informatica: ";
            float newAvg;
            cin >> newAvg;
            modifyAvg(root, id, newAvg);
            break;
        case 2:
            cout << "Introduceti numarul de ordine: ";
            cin >> id;
            deleteNode(root, id);
            break;
        case 3:
            printDescending(root);
            break;
        case 4:
            cout << "Introduceti prima valoare: ";
            cin >> first;
            cout << "Introduceti a doua valoare: ";
            int second;
            cin >> second;
            printAvgBetween(root, first, second);
            break;
        default:
            break;
        }
        _getch();
    } while (opt);
    return 0;
}
