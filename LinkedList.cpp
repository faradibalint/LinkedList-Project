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
    void fillup(int q[]) ///lista feltöltése tömbből 
    {

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

    }
    void outlist() /// a lista elemeinek kilistázása
    {
    
    }
    void quantity() /// a lista elemeinek darabszáma
    {

    }
    void deletelist() ///a lista törlése
    {
      
    }
    void batyusutes()
    {
        element* n = first;
        while(n!=NULL)
        {
            cout<<n->data<<endl;
            n=n->next;
        }
    }

};

int main(){
    LList lista;
    
    lista.beforenewelement(3);
    lista.afternewelement(4);
    lista.afternewelement(5);
    lista.beforenewelement(2);
    lista.afternewelement(6);
    lista.beforenewelement(1);    
    cout<<endl;
    lista.specifiedsearch(1);
    lista.specifiedsearch(2);
    lista.specifiedsearch(3);
    lista.specifiedsearch(4);
    lista.specifiedsearch(5);
    lista.specifiedsearch(6);
    lista.specifiedsearch(7);
    lista.specifiedmodify(1);
    lista.specifiedmodify(2);
    lista.specifiedmodify(3);
    lista.specifiedmodify(4);
    lista.specifiedmodify(5);
    lista.specifiedmodify(6);
    lista.specifiedmodify(7);

    lista.batyusutes();

    
    
    
     

    
    return 0;
}