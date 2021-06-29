#include "header.h"

using namespace std;

int main()
{
    SingleLinkedList<int>* SLL=new SingleLinkedList<int>(1);
   /* print(SLL);
    cout<<endl;
    int tmp;
    while(cin>>tmp)
    {
    SingleLinkedList<int>* SLL1=new SingleLinkedList<int> (tmp);
    insertSLL(SLL,SLL1,size(SLL));
    }
    print(SLL);
    */
    //
    int tmp;
    DoublyLinkedList<int> * LL=new DoublyLinkedList<int>(0);
    while(cin>>tmp)
    {
        insert(LL,tmp,0);
    }
    print(LL);cout<<endl;
    removeLL(LL,6);
    removeLL(LL,0);
    print(LL);cout<<endl;
    reverse(LL);
    print(LL);
}