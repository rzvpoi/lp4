/*
STIVA
Program prin care se implementeaza o stiva cu n elem de tip intreg
si se efectueaza operatiile de: inserare si de extragere a elementelor
in stiva, de accesare a elementului din varf si se
afiseaza numarul de elemente ramase in stiva dupa extragerea
unui element;
*/

#include<iostream>
#include<conio.h>
#include<iomanip>
#define nmax 50

using namespace std;

typedef int stiva[nmax];

stiva S;

int baza, info, varf=-1;

// Inserarea elem intr-o stiva

void inselem(stiva S, int &info, int &varf)
{
    if(varf>=nmax)
        cout << "Stiva este plin\n";
    else
        S[++varf]=info;
}

// accesarea elementului din varful stivei
int varfelem(stiva S, int &varf)
{
    return(S[varf]);
}

// Extragerea elementelor dintr-o stiva

int extelem(stiva S, int &varf)
{
    if(varf<0)
        cout<<"Stiva este vida\n";
    else
        return(S[varf-1]);
}

// Parcurgerea si afisarea elementelor din stiva

void afisare_stiva()
{
    int i,nr=0;
    if(varf==0)
        cout << "\n Stiva este vida";
    else
    {
        cout << "\n Afisare continut stiva: \n";
        for(i=varf;i>=1;i--)
        {
            cout << " | "<<setw(4)<<S[i]<<" | \n";
            cout << "|---|\n";
            nr++;
        }

        cout << "baza "<<S[0]<<'\n';
        nr++;
    }
    
    cout << "In stiva sunt acum "<<nr<<" elemente"<<endl;

}

int main()
{
    int n,info, i;
    cout<<"Se introduce nr de elemente de inserat in stiva "; cin>>n;
    cout<<"Se introduc numerele ce se vor insera in stiva \n";
    for(i=0;i<n;i++)
    {
        cin>>info;
        inselem(S, info, varf);
    }

    afisare_stiva();
    cout<<"\n Elem din varful stivei este: "<<varfelem(S, varf)<<endl;
    cout<<endl<<"Se afiseaza stiva dupa ce s-a extras un elem: ";
    extelem(S, varf);
    afisare_stiva();
    return 0;
}