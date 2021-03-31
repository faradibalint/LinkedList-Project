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
            elso->next = last;
            element* n = new element();
            while(n->next!=last)
            {
                n=n->next;
            }
            n->next = elso;
            elso->data = last->data;
            last->data = q;

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

    }
    void specifiedmodify(int q) ///megadott elem módosítása
    {

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
    lista.beforenewelement(2);
    lista.afternewelement(6);    

    lista.batyusutes();
    
    
    
     

    
    return 0;
}