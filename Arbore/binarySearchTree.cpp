
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Node
{
    int inf;
    Node *left;
    Node *right;
};

Node *newNode(int data);
bool isEmpty(Node *root);
void inserare(Node *&root, int value);
Node *creare(Node *&root);
void RSD(Node *root);
void SRD(Node *root);
void SDR(Node *root);
int maxValue(Node *root);
int minValue(Node *root);
bool searchValue(Node *root, int value);
void afisareNivel(Node *root, int currentLevel, int necessaryLevel);
int inaltimeArbore(Node *root);

int main()
{
    Node *root = NULL;
    cout << "Incepem crearea arborelui" << endl;
    creare(root);
    int optiune, valoare;
    do
    {
        system("cls");
        cout << "1 - Inserarea unei valori" << endl;
        cout << "2 - Parcurgerea arborelui in preordine" << endl;
        cout << "3 - Parcurgerea arborelui in inordine" << endl;
        cout << "4 - Parcurgerea arborelui in postordine" << endl;
        cout << "5 - Valoarea maxima din arbore" << endl;
        cout << "6 - Valoarea minima din arbore" << endl;
        cout << "7 - Cautarea unei valori" << endl;
        cout << "8 - Afisarea valorilor pe un anumit nivel" << endl;
        cout << "9 - Inaltimea ABC" << endl;
        cout << "0 - Iesire" << endl;
        cout << "\n\tOptiunea aleasa -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            cout << "Valoarea de inserat: ";
            cin >> valoare;
            inserare(root, valoare);
            break;
        case 2:
            cout << "Parcurgerea arborelui in preordine: ";
            RSD(root);
            break;
        case 3:
            cout << "Parcurgerea arborelui in inordine: ";
            SRD(root);
            break;
        case 4:
            cout << "Parcurgerea arborelui in postordine:";
            SDR(root);
            break;
        case 5:
            cout << "Valoarea maxima din arbore: " << maxValue(root);
            break;
        case 6:
            cout << "Valoarea minima din arbore: " << minValue(root);
            break;
        case 7:
            cout << "Valoarea de cautat: ";
            cin >> valoare;
            (searchValue(root, valoare)) ? cout << "Valoarea " << valoare << " este prezenta in ABC" : cout << "Valoarea " << valoare << " nu este prezenta in ABC";
            break;
        case 8:
            cout << "Nivelul dorit: ";
            cin >> valoare;
            afisareNivel(root, 0, valoare);
            break;
        case 9:
            cout << "Inaltimea arborelui: " << inaltimeArbore(root);
            break;
        default:
            exit(0);
        }
        _getch();
    } while (optiune != 0);
    return 0;
}

Node *newNode(int data)
{
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->inf = data;
    newElement->left = NULL;
    newElement->right = NULL;
}

bool isEmpty(Node *root)
{
    return root == NULL;
}

void inserare(Node *&root, int value)
{
    if (isEmpty(root))
    {
        root = newNode(value);
        return;
    }
    if (root->inf == value)
    {
        cout << "Aceasta valoare deja este in arbore" << endl;
        return;
    }
    if (root->inf > value)
    {
        if (root->left != NULL)
        {
            inserare(root->left, value);
        }
        else
        {
            root->left = newNode(value);
            return;
        }
    }
    else if (root->inf < value)
    {
        if (root->right != NULL)
        {
            inserare(root->right, value);
        }
        else
        {
            root->right = newNode(value);
            return;
        }
    }
}

Node *creare(Node *&root)
{
    int nr;
    cout << "Valoarea: ";
    cin >> nr;
    if (nr != 0)
    {
        inserare(root, nr);
        while (nr != 0)
        {
            cout << "Valoarea: ";
            cin >> nr;
            if (nr == 0)
                break;
            inserare(root, nr);
        }
    }
}

void RSD(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        cout << root->inf << " ";
        RSD(root->left);
        RSD(root->right);
    }
}

void SRD(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        SRD(root->left);
        cout << root->inf << " ";
        SRD(root->right);
    }
}

void SDR(Node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    else
    {
        SDR(root->left);
        SDR(root->right);
        cout << root->inf << " ";
    }
}

int maxValue(Node *root)
{
    if (isEmpty(root))
    {
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->inf;
}

int minValue(Node *root)
{
    if (isEmpty(root))
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->inf;
}

bool searchValue(Node *root, int value)
{
    if (isEmpty(root))
        return false;
    if (root->inf == value)
        return true;
    else if (value < root->inf)
        searchValue(root->left, value);
    else if (value > root->inf)
        searchValue(root->right, value);
}

void afisareNivel(Node *root, int currentLevel, int necessaryLevel)
{
    if (!isEmpty(root))
    {
        if (currentLevel == necessaryLevel)
        {
            cout << root->inf << " ";
        }
        afisareNivel(root->left, currentLevel + 1, necessaryLevel);
        afisareNivel(root->right, currentLevel + 1, necessaryLevel);
    }
}

int inaltimeArbore(Node *root)
{
    if (isEmpty(root))
        return -1;
    int lHeight = inaltimeArbore(root->left);
    int rHeight = inaltimeArbore(root->right);
    return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
}
