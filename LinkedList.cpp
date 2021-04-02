//Linked List Project - C 
//Team: Tüske Zsuzsanna, Benkovits Marcell, László Csaba, Farádi Bálint
//This project is public. Source: github --> faradibalint/LinkedList-Project
//Starting Date: 2021.04.01
#include <iostream>

using namespace std;

struct element
{
    int data;
    element *next; 
};

class LList
{
private:
    element *first, *last;
public:
    LList()
    {
        first = NULL;
        last = NULL;
    }
    void fillup(int q[], int m) ///lista feltöltése tömbből
    {

        //m: tomb elemeinek szama, e: elozo, j: jelenlegi
        element* e= new element;
        e->data=q[0];
        first = e;
        for(int i=1;i<m;i++)
        {
            element* j= new element;
            j->data=q[i];
            e->next = j;
            e=j;
        }
        e->next=NULL;
        last=e;
    }
    void beforenewelement(int q) ///új elem beszúrása a lista elejére "a fej elé"
    {
        element* elso = new element;
        elso->data = q;
        elso->next = NULL;

        if(first==NULL)
        {
            first = elso;
            last = elso;
        }
        else
        {
            elso->next = first->next;
            first->next = elso;
            elso->data = first->data;
            first->data = q;
        }   
    }
    void afternewelement(int q) ///új elem beszúrása a lista végére 
    {
        element* elso = new element;
        elso->data = q;
        elso->next = NULL;

        if(first==NULL)
        {
            first = elso;
            last = elso;
        }
        else
        {
            last->next=elso;
            last=elso;
        }
    }
    void insidenewelement(int q) ///új elem beszúrása a listába
    {

    }
    void arrangednewelement(int q) ///új elem beszúrása rendezett listába
    {

    }
    void firstdelete() ///az első elem törlése
    {

    }
    void lastdelete() ///az utolsó elem törlése
    {

    }
    void insidedelete(int q) ///köztes elem törlése
    {

    }
    void specifiedsearch(int q) ///megadott elem keresése
    {
        element* n = first;
        int m=1;
        while(n->data!=q && n!=last)
        {
            m=m+1;
            n=n->next;
        }
        if (n->data==q)
        {
        cout<<"A keresett elem a(z) "<<m<<". helyen talalhato."<<endl;
        }
        else
        {
        cout<<"ERROR: A lista nem tartalmazza a megadott elemet."<<endl;
        }
    }
    void specifiedmodify(int q) ///megadott elem módosítása
    {
        cout<<"Adja meg az uj szamot: ";
        int a;
        cin>>a;
        element* n = first;
        while(n->data!=q && n!=last)
        {
            n=n->next;
        }
        if (n->data==q)
        {
        n->data=a;
        cout<<"A modositas sikeresen lezajlott."<<endl;
        }
        else
        {
        cout<<"ERROR: A lista nem tartalmazza a modositando elemet."<<endl;
        }
    }
    void elementswitch(int q,int p) ///két szomszédos elem cseréje
    {

    }
    void listreverse() /// a lista megfordítása
    {
        if (first==NULL)
        {
            cout<<"ERROR: A lista nem tartalmaz elemeket."<<endl;
        }
        else if (first==last)
        {
            cout<<"ERROR: A lista egy elemu, a megforditas nem vegezheto el."<<endl;
        }
        else
        {
            element* n = first;
            int a=1;
            do
            {
                n=n->next;
                a=a+1;
            } while (n!=last);

            int szamok[a];

            element* o = first;
            do
            {
                szamok[a]=o->data;
                a=a-1;
                o=o->next;
            } while (o!=NULL);

            a=a+1;
            element* p = first;
            do
            {
                p->data=szamok[a];
                a=a+1;
                p=p->next;
            } while (p!=NULL);
        }
    }
    void outlist() /// a lista elemeinek kilistázása
    {
        element* n = first;
        if(first!=NULL)
        {
            while(n!=NULL)
            {
                cout<<n->data<<endl;
                n=n->next;
            }
        }
        else
        {
            cout<<"A lista nem tartalmaz elemeket."<<endl;
        }
    }
    void quantity() /// a lista elemeinek darabszáma
    {
        element* n = first;
        int m=1;
        if(first!=NULL)
            {
                while(n!=last)
                {
                m=m+1;
                n=n->next;
                }
            cout<<"A lista "<<m<< " darab elemmel rendelkezik."<<endl;
            }
        else
        {
            cout<<"A lista nem tartalmaz elemeket."<<endl;
        }
    }
    void deletelist() ///a lista törlése
    {
      cout<<"A lista sikeresen torlodott."<<endl;
      delete this;
    }
 
};

int main(){
    LList lista;

    lista.listreverse();

    lista.beforenewelement(3);
    lista.listreverse();

    lista.afternewelement(4);
    lista.afternewelement(5);
    lista.beforenewelement(2);
    lista.afternewelement(6);
    lista.beforenewelement(1); 

    lista.listreverse();
    lista.outlist();

    lista.fillup({},5);


    
    
    
     

    
    return 0;
}