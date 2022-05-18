#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
using namespace std;
struct dataCalendaristica
{
    int zi;
    int luna;
    int an;
};

struct angajat
{
    string nume;
    string prenume;
    dataCalendaristica dataNasterii;
    string telefon;
    string postulOcupat;
    string stagiu;
    int salariuPeOra;
    int oreLucrateZi;
    int ziLucratePeLuna;
    int salariuLunar;
};

struct nod
{
    angajat inf;
    nod *next;
    nod *prev;
};

void createList(nod *&x, nod *&sant2)
{
    ifstream readFile;
    readFile.open("info.txt", ios::in);
    if (!readFile)
    {
        cout << "No such file";
    }
    else
    {
        while (!readFile.eof())
        {
            x = sant2;
            readFile >> x->inf.nume;
            readFile >> x->inf.prenume;
            readFile >> x->inf.dataNasterii.zi;
            readFile >> x->inf.dataNasterii.luna;
            readFile >> x->inf.dataNasterii.an;
            readFile >> x->inf.telefon;
            readFile >> x->inf.postulOcupat;
            readFile >> x->inf.stagiu;
            readFile >> x->inf.salariuPeOra;
            readFile >> x->inf.oreLucrateZi;
            readFile >> x->inf.ziLucratePeLuna;
            x->inf.salariuLunar = x->inf.salariuPeOra * x->inf.oreLucrateZi * x->inf.ziLucratePeLuna;
            sant2 = new nod();
            sant2->prev = x;
            x->next = sant2;
        }
    }
    readFile.close();
};

void printAngajat(nod *x)
{
    cout << "\nNume: " << x->inf.nume << endl;
    cout << "Prenume: " << x->inf.prenume << endl;
    cout << "Ziua de nastere: " << x->inf.dataNasterii.zi << endl;
    cout << "Luna de nastere: " << x->inf.dataNasterii.luna << endl;
    cout << "Anul nasterii: " << x->inf.dataNasterii.an << endl;
    cout << "Telefon de contact: " << x->inf.telefon << endl;
    cout << "Postul ocupat: " << x->inf.postulOcupat << endl;
    cout << "Stagiu: " << x->inf.stagiu << endl;
    cout << "Salariul pe ora: " << x->inf.salariuPeOra << endl;
    cout << "Ore lucrate intro zi: " << x->inf.oreLucrateZi << endl;
    cout << "Zi lucrate intro luna: " << x->inf.ziLucratePeLuna << endl;
    cout << "Salariu lunar: " << x->inf.salariuLunar << endl;
}

int numarAngajati(nod *x, nod *sant1, nod *sant2)
{
    x = sant1->next;
    int numberOfEmployee = 0;
    while (x != sant2)
    {
        ++numberOfEmployee;
        x = x->next;
    }
    return numberOfEmployee;
}

int findMax(nod *x, nod *sant1, nod *sant2)
{
    x = sant1->next;
    int max = 0;
    nod *adresa;
    while (x != sant2)
    {
        if (x->inf.salariuLunar > max)
        {
            max = x->inf.salariuLunar;
            adresa = x;
        }

        x = x->next;
    }
    printAngajat(adresa);
    return max;
}

int experienceClassification(nod *x, nod *sant1, nod *sant2, string stagiu)
{
    x = sant1->next;
    nod *adresa;
    while (x != sant2)
    {
        if(x->inf.stagiu == "Incepator")
            printAngajat(x);
        x = x->next;
    }
    return 0;
}

int lunaDeNastereAngajatiNumar(nod *x, nod *sant1, nod *sant2, int luna)
{
    x = sant1->next;
    int count = 0;
    nod *adresa;
    while (x != sant2)
    {
        if (x->inf.dataNasterii.luna == luna)
            count++;
        x = x->next;
    }
    return count;
}

void insertAngajat(nod *&x, nod *&sant2)
{
    int more = 1, number;
    string sir;
    ofstream writeFile("angajatOUT.txt");
        while (more)
        {
            x = sant2;
            cout << "\nNumele: ";
            cin >> sir;
            writeFile << sir << "\n";
            cout << "Prenumele:";
            cin >> sir;
            writeFile << sir<< "\n";
            cout << "Ziua de nastere: ";
            cin >> number;
            writeFile << number<< "\n";
            cout << "Luna de nastere: ";
            cin >> number;
            writeFile << number<< "\n";
            cout << "Anul nasterii: ";
            cin >> number;
            writeFile << number<< "\n";
            cout << "Telefon de contact: ";
            cin >> sir;
            writeFile << sir<< "\n";
            cout << "Postul ocupat: ";
            cin >> sir;
            writeFile << sir<< "\n";
            cout << "Stagiu: ";
            cin >> sir;
            writeFile << sir<< "\n";
            cout << "Salariul pe ora: ";
            cin >> number;
            writeFile << number<< "\n";
            cout << "Ore lucrate intro zi: ";
            cin >> number;
            writeFile << number<< "\n";
            cout << "Zi lucrate intro luna: ";
            cin >> number;
            writeFile << number<< "\n";
            x->inf.salariuLunar = x->inf.salariuPeOra * x->inf.oreLucrateZi * x->inf.ziLucratePeLuna;
            writeFile.close();
            sant2 = new nod();
            sant2->prev = x;
            x->next = sant2;
            cout << "\nMai adaugam ?(orice - da, nu - 0)";
            cin >> more;
        }
    writeFile.close();

}

void deleteAngajat(){
return;
}

int main()
{
    int chose, luna;
    nod *sant1 = new nod();
    nod *sant2 = new nod();
    nod *x = new nod();
    sant1->next = sant2;
    sant2->prev = sant1;

    // cin >> Sant1.nume;
    // cin >> Sant1.prenume;
    // cin >> Sant1.dataNasterii.zi;
    // cin >> Sant1.dataNasterii.luna;
    // cin >> Sant1.dataNasterii.an;
    // cin >> Sant1.telefon;
    // cin >> Sant1.postulOcupat;
    // cin >> Sant1.stagiu;
    // cin >> Sant1.salariuPeOra;
    // cin >> Sant1.oreLucrateZi;
    // cin >> Sant1.ziLucratePeLuna;

    // Sant1->nume = "";
    // Sant1->prenume = "";
    // Sant1->dataNasterii.zi = ;
    // Sant1->dataNasterii.luna = ;
    // Sant1->dataNasterii.an = ;
    // Sant1->telefon = "";
    // Sant1->postulOcupat = "";
    // Sant1->stagiu = ; // ani
    // Sant1->salariuPeOra = ;
    // Sant1->oreLucrateZi = ;
    // Sant1->ziLucratePeLuna = ;

    do
    {
        system("cls");
        createList(x, sant2);
        cout << "\n0.\t Iesiti din meniu\n";
        cout << "1.\t Calculati numarul angajatilor\n";
        cout << "2.\t Determinati angajatul cu salariul lunar maxim\n";
        cout << "3.\t Afisati grupele de angajati dupa stagiul acestora\n";
        cout << "4.\t Determinati numarul angajatilor nascuti in luna dorita\n";
        cout << "5.\t Adaugati un angajat\n";
        cout << "6.\t Excludeti un angajat\n";
        cout << "\n\n\tAlege (de la 0 la 6) -> ";
        cin >> chose;
        switch (chose)
        {
        case 1:
            cout << "\t Numarul angajatilor este: " << numarAngajati(x, sant1, sant2) << endl;
            break;
        case 2:
            cout << "\t Angajatul cu salariul lunar maxim este: " << findMax(x, sant1, sant2) << endl;
            break;
        case 3:
            //experienceClassification(x, sant1, sant2);
            break;
        case 4:
            cout << "\n\tAlegeti luna (1-12): ";
            cin >> luna;
            cout << "\t\n Numarul angajatilor este: " << lunaDeNastereAngajatiNumar(x, sant1, sant2, luna) << endl;
            break;
        case 5:
            insertAngajat(x, sant2);
            break;
        case 6:
            deleteAngajat();
            break;
        default:
            break;
        }
        _getch();
    } while (chose != 0);
    // cout << "Nume: " << Sant1.nume << endl;
    // cout << "Prenume: " << Sant1.prenume << endl;
    // cout << "Ziua de nastere: " << Sant1.dataNasterii.zi << endl;
    // cout << "Luna de nastere: " << Sant1.dataNasterii.luna << endl;
    // cout << "Anul nasterii: " << Sant1.dataNasterii.an << endl;
    // cout << "Telefon de contact: " << Sant1.telefon << endl;
    // cout << "Postul ocupat: " << Sant1.postulOcupat << endl;
    // cout << "Stagiu: " << Sant1.stagiu << endl;
    // cout << "Salariul pe ora: " << Sant1.salariuPeOra << endl;
    // cout << "Ore lucrate intro zi: " << Sant1.oreLucrateZi << endl;
    // cout << "Zi lucrate intro luna: " << Sant1.ziLucratePeLuna << endl;

    return 0;
}
