//Linked List Project - C 
//Team: Tüske Zsuzsanna, Benkovits Marcell, László Csaba, Farádi Bálint
//This project is public. Source: github --> faradibalint/LinkedList-Project
//Starting Date: 2021.04.01
#include <iostream>
#include <conio.h>

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
            elso->next = first;
            first = elso;
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
        element* elso = new element;
        elso->data = q;
        elso->next = NULL;

        if(first==NULL)
        {
            first = elso;
            last = elso;
        }
        else if (first==last)
        {
            first->next = elso;
            last = elso;
        }
        else
        {
            elso->next = first->next;
            first->next = elso;
        }
    }
    void arrangednewelement(int q) ///új elem beszúrása rendezett listába
    {
        ///megnézzük hogy rendezett e a lista --> elvileg ez a rész működik
        bool rendezett = true;
        element* n = first->next;
        int x = first->data;
        if(first!=NULL)
        {
            while(n!=NULL && rendezett==true)
            {
                if (x>n->data)
                {
                    rendezett = false;
                }
                x=n->data;
                n=n->next;
            }
            ///hogyha rendezett akkor megkeressük hogy hova kell berakni a cuccot és berakjuk oda.
            if (rendezett)
            {
                element* y = first->next; 
                element* z = first; 
                bool kisebbe=false;

                while(!kisebbe && y!=NULL)
                {
                    
                    if(q<first->data)
                    {
                        kisebbe=true;
                        this->beforenewelement(q);
                    }
                    
                    else if(q>last->data)
                    {
                        kisebbe=true;
                        this->afternewelement(q);
                    }
                    
                    else
                    {
                        if (q<y->data)
                        {
                            element* elem = new element();
                            elem->data = q;
                            elem->next = y;
                            z->next = elem;
                            kisebbe=true;
                        }
                        else
                        {
                            y = y->next;
                            z = z->next;
                        }
                    }
                }
            }
            else 
            {
                cout<<"ERROR: A lista rendezetlen. A rendezeshez hasznalja az arrange() fuggvenyt."<<endl;
            }
            
        }
        else
        {
            cout<<"ERROR: A lista ures."<<endl;
        }
    }
    void firstdelete() ///az elsõ elem törlése
    {
        if(first!=NULL)
        {
            element* Pelso=first;
            first=first->next;
            delete Pelso;
            cout<<"Az elso elemet toroltuk."<<endl;
        }
        else
        {
            cout<<"A lista ures."<<endl;
        }
    }
    void lastdelete() ///az utolsó elem törlése
    {
       if(first!=NULL)
        {
            element* Utolso=last;
            element* n = first;
            while(n->next!=last){
                n=n->next;
            }
            last=n;
            last->next=NULL;
            delete Utolso;
            cout<<"Az utolso elemet toroltuk."<<endl;
        }
        else
        {
            cout<<"A lista ures."<<endl;
        } 
    }
    void insidedelete(int q) ///köztes elem törlése
    {
        if (q=1)
        {
            cout<<"ERROR: Nem torolheti ki az elso vagy utolso elemet ezzel a funkcioval. Hasznalja a firstdelete() vagy lastdelete() funkciokat."<<endl; 
        }
        else
        {
        element * n = first;
        element * deleting;
        int a=2;
        if (first!=NULL && this->subquantity()>=q)
        {
          while(a!=q){
            n=n->next;
            a=a+1;
        }  
        deleting = n->next;
        if (deleting!=last)
        {
             n->next = deleting->next;
             delete deleting;
        }else {
            cout<<"ERROR: Nem torolheti ki az elso vagy utolso elemet ezzel a funkcioval. Hasznalja a firstdelete() vagy lastdelete() funkciokat."<<endl;        }
       
        }else{
            cout<< "ERROR: A lista nem tartalmazza a megadott elemet, vagy ures." <<endl;
        }
    
        }
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
    void elementswitch(int q) ///két szomszédos elem cseréje --> az első elem sorszámát kell megadni -->ezt cseréljük az utánalévővel
    {
        if (first!=NULL && q!=0 && q<this->subquantity()){
        element* n = first;
        int a=1;
        while(a!=q){
            n = n->next;
            a=a+1;
        }
        int temporary = n->data;
        n->data = n->next->data;
        n->next->data = temporary;
        }else{
            cout<<"ERROR: Hibas bemenet/A lista nem tartalmaz elemeket."<<endl;
        }
     
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
    int subquantity(){
        element* n = first;
        int m=1;
        if(first!=NULL)
            {
                while(n!=last)
                {
                m=m+1;
                n=n->next;
                }
            return m;
            }
        else
        {
            return 0;
        }
    }
    void arrange() ///a lista sorrendbe rendezése
    {
        if (first==NULL)
        {
            cout<<"ERROR: A lista nem tartalmaz elemeket."<<endl;
        }
        else if (first==last)
        {
            cout<<"ERROR: A lista egy elemu, a sorba rendezes nem vegezheto el."<<endl;
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
            int rszamok[a];
            int w=a;
            int voltmar=0;
            int temp=0;

            for (int i=w;i>=1;i--)
            {
                rszamok[i]=0;
            }
            element* o = first;
            do
            {
                szamok[a]=o->data;
                a=a-1;
                o=o->next;
            } while (o!=NULL);

            for (int i=w; i>0; i--)
            {
                for (int j=w; j>0; j--)
                {
                    if ((rszamok[i]==0 && i==w) || (rszamok[i]==0 && szamok[j]!=voltmar))
                    {
                        rszamok[i]=szamok[j];
                        temp=j;
                    }
                    else if (rszamok[i]<szamok[j] && i==w)
                    {
                        rszamok[i]=szamok[j];
                        voltmar=szamok[j]+1;
                        temp=j;
                    }
                    else if (rszamok[i]<szamok[j] && szamok[j]!=voltmar)
                    {
                        rszamok[i]=szamok[j];
                        temp=j;
                    }
                    else if (rszamok[i+1]==szamok[j] && szamok[j]!=voltmar)
                    {
                        rszamok[i]=szamok[j];
                        temp=j;
                    }
                }
                szamok[temp]=voltmar;   
            }

            int u=1;
            element* s = first;
            s->data=rszamok[u];
            do
            {
                s=s->next;
                u=u+1;
                s->data = rszamok[u];
            } while (s!=last);
        }
    }
};

int main(){
    bool vanelista = false; 
    cout<<"WELCOME IN THE LINKED LIST PROJECT!"<<endl;
    cout<<"_____________________________________"<<endl;
    while(!vanelista){   
        cout<<"There is no list created. Do you want to create a linked list?"<<endl;
        cout<<"y/n?"<<endl;
        char beker;
        beker = _getch();
        if(beker=='y'){
            system("cls");
            cout<<"List successfully created!"<<endl;
            vanelista=true;
        }else if(beker=='n'){
            cout<<"Closing program."<<endl;
            return 0;
        }else{
            cout<<"Wrong answer! Try again."<<endl;
        }
    }
    LList lista;
    while(vanelista){
    cout<<"_____________________________________"<<endl;
    cout<<"List methods:"<<endl;
    cout<<"1.Fill list from array"<<endl
    <<"2.Insert new element before head"<<endl
    <<"3.Insert new element inside the list"<<endl
    <<"4.Insert new element at the end of the list"<<endl
    <<"5.Insert new element into arranged list"<<endl
    <<"6.Delete first element"<<endl
    <<"7.Delete last element"<<endl
    <<"8.Delete element from inside the list"<<endl
    <<"9.Search for a specific element"<<endl
    <<"10.Modify specific element"<<endl
    <<"11.Switch neighbour elements"<<endl
    <<"12.Reverse list"<<endl
    <<"13.Show list's elements"<<endl
    <<"14.Show number of elements of list"<<endl
    <<"15.Delete list"<<endl
    <<"16.Arrange list"<<endl;
    cout<<"_____________________________________"<<endl;
    cout<<"Type method's number to execute"<<endl;
    cout<<"Number:";
    int movement;
    cin>>movement;
    if (movement==1){
        cout<<"Fill list from array"<<endl;
        cout<<"Give the array's size: ";
        int size;
        cin>>size;
        cout<<"------------------------"<<endl<<"Give the elements"<<endl;
        int array[size];
        for (int i=0;i<size;i++){
            cin>>array[i];
        }
        lista.fillup(array,size);
        cout<<"List successfully filled!"<<endl;
    }else if(movement==2){
        cout<<"Insert new element before head"<<endl;
        cout<<"Give the element: ";
        int elemement;
        cin>>elemement;
        lista.beforenewelement(elemement);
        cout<<"Element successfully pushed"<<endl;
    }else if(movement==3){
        cout<<"Insert new element inside the list"<<endl;
        cout<<"Give the element: ";
        int elemement3;
        cin>>elemement3;
        lista.insidenewelement(elemement3);
        cout<<"Element successfully pushed"<<endl;
    }else if(movement==4){
        cout<<"Insert new element at the end of the list"<<endl;
        cout<<"Give the element: ";
        int elemement2;
        cin>>elemement2;
        lista.afternewelement(elemement2);
        cout<<"Element successfully pushed"<<endl;
    }else if(movement==5){
        cout<<"Insert new element into arranged list"<<endl;
        cout<<"Give the element: ";
        int elemement1;
        cin>>elemement1;
        lista.arrangednewelement(elemement1);
        cout<<"Element successfully pushed"<<endl;
    }else if(movement==6){
        cout<<"Delete first element"<<endl;
        lista.firstdelete();
        cout<<"Element successfully deleted!"<<endl;
    }else if(movement==7){
        cout<<"Delete last element"<<endl;
        lista.lastdelete();
        cout<<"Element successfully deleted"<<endl;
    }else if(movement==8){
        cout<<"Delete element from inside the list"<<endl;
        cout<<"Which element do you want to delete?"<<endl;
        int elemement6;
        cin>>elemement6;
        lista.insidedelete(elemement6);
        cout<<"Element successfully deleted"<<endl;
    }else if(movement==9){
        cout<<"Search for a specific element"<<endl;
        cout<<"Give the element: ";
        int elemement7;
        cin>>elemement7;
        lista.specifiedsearch(elemement7);
    }else if(movement==10){
        cout<<"Modify specific element"<<endl;
        cout<<"Give the element: ";
        int elemement8;
        cin>>elemement8;
        lista.specifiedmodify(elemement8);
    }else if(movement==11){
        cout<<"Switch neighbour elements"<<endl;
        cout<<"Give the first element: ";
        int elemement9;
        cin>>elemement9;
        lista.elementswitch(elemement9);
        cout<<"Elements successfully switched"<<endl;
    }else if(movement==12){
        cout<<"Reverse list"<<endl;
        lista.listreverse();
        cout<<"Method successfully done!"<<endl;
    }else if(movement==13){
        cout<<"Show list's elements"<<endl;
        lista.outlist();
        cout<<"Method successfully done!"<<endl;
    }else if(movement==14){
        cout<<"Show number of elements of list"<<endl;
        lista.quantity();
        cout<<"Method successfully done!"<<endl;
    }else if(movement==15){
        cout<<"Delete list"<<endl;
        lista.deletelist();
        cout<<"Method successfully done!"<<endl;
        vanelista=false;
    }else if(movement==16){
        cout<<"Arrange list"<<endl;
        lista.arrange();
        cout<<"Method successfully arranged!"<<endl;
    }
    }
    return 0;
}