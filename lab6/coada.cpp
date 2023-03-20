/*
COADA - nu merge
Programul prin care se implementeaza o coada circulara cu 10 elemente de tip intreg
si se efectueaza opratiile de: III. Inserare a unuio element la sfarsitul cozii, IV. Acesarea
a primului element si V. Extragere a primului element din coada.
*/
#include<iostream>
#include<conio.h>

using namespace std;

typedef int coada[10];

void inselem(coada, int &, int &, int &);
int primelem(coada, int &);
int extelem(coada, int &, int &);

// Procedura prin care se realizeaza inserarea unui element la sfarsitul unei cozi

void inselem(coada C, int &info, int &ultim, int &ne)
{
    if(ne==10)
        cout << "Coada s-a umplut";
    else {
        if(ultim==10)
            ultim = -1;
        else
            ultim++;

        C[ultim]=info;
        ne++;
    }
}

// Subprogram prin care se efectueaza accesarea primului element
int primelem(coada C, int &prim)
{
    return(C[prim]);
}

// Extragerea elementelor dintr-o coada

int extelem(coada C, int &prim, int &ne)
{
    int info;
    if(prim>ne)
    {
        cout<<"Coada este vida\n";
        return 0;
    }
    else 
    {
        info=C[prim++];

        if(prim==10)
            prim=0;
        ne--;

        return(info);
    }

    getch();

}

int main()
{
    coada C;
    int i,n,info,prim=0,ultim=1,nmax=0;

    cout << "Se introduce numarul de elemente de inserat in coada";
    cin >> n;

    if(n>10)
    {
        cout << "S-a depasit numarul maxim de elemente admise in coada";
        return 1;
    } else {
        cout << "Se introduc numerele ce se vor insera in coada:\n";
        for(i=0; i<n; i++)
        {
            cin >> info;
            inselem(C, info, ultim, nmax);
        }
    }
    if(n)
        cout << "Primul element din coada este " << primelem(C,prim)<<'\n';

    cout << "Se precizeaza numarul de elemente de extras din coada: ";
    cin >> n;

    if(n>10)
    {
        cout << "S-a depasit numarul maxim de elemente admise in coada";
        return 1;
    } else {
        for(i=0; i<n; i++)
            if(nmax)
                cout<<"Elementul["<<i<<"]";

        extelem(C,prim,nmax)<<'\n';
        cout << "Numarul de elemente ramase in coada "<<(ultim-prim+1);
        return 0;
        
    }


}