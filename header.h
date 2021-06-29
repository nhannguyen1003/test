/* created by Nguyen Thanh Nhan 
 date 29/6/2021
 */

#ifndef HEADER_H
#define HEADER_H

#include "LinkedList.h"
#include<vector>
#include<string>

//print LL
template<typename T>
void print(SingleLinkedList<T>* head)
{
    // check head is null
    if(!head) cout<<"This LinkedList is nullptr";
    else 
    {
        SingleLinkedList<T>* p=head;
        while (p)
        {
            cout<<p->getData()<<"->";
            p=p->getNext();     
        }
        cout<<"NULL";
    }
}
    //doubly
template<typename T>
void print(DoublyLinkedList<T>* head)
{
    // check head is null
    if(!head) cout<<"This LinkedList is nullptr";
    else 
    {
        DoublyLinkedList<T>* p=head;
        while (p)
        {
            cout<<p->getData()<<"->";
            p=p->getNext();
        }
        cout<<"NULL";
    }

}

//size()
template<typename T>
int size(SingleLinkedList<T>* head)
{
    int index=0;
    while(head)
    {
        head=head->getNext();
        index++;
    }
    return index;
}
template<typename T>
int size(DoublyLinkedList<T>* head)
{
    int index=0;
    while(head)
    {
        head=head->getNext();
        index++;
    }
    return index;
}
// To insert with index i
template<typename T>
void insert(SingleLinkedList<T>* &head,T data,int idx){
    SingleLinkedList<T>* value= new SingleLinkedList<T> (data);
    if(!head)
    {
        head=value;
    }
    else{
        SingleLinkedList<T>* p=head;
        if(idx >size(head) || idx <0) return ;
        if(idx==0)   {
            value->setNext(head);
            head=value; 
        }
        else{
            while(--idx)
            {
                p=p->getNext();
            }
            value->setNext(p->getNext());
            p->setNext(value);
        }
    }
}
    //doubly
template<typename T>
void insert(DoublyLinkedList<T>* &head,T data,int idx){
    DoublyLinkedList<T>* value= new DoublyLinkedList<T> (data);
    if(!head)
    {
        head=value;
    }
    else{
        DoublyLinkedList<T>* p=head;
        if(idx >size(head) || idx <0) return ;
        if(idx==0)   {
            value->setNext(head);
            head->setPre(value);
            head=value; 
            head->setPre(nullptr);
        }
        else if(idx==size(head))
        {
             while(p->getNext())
            {
                p=p->getNext();
            }
            p->setNext(value);
            value->setNext(nullptr);
            value->setPre(p);
        }
        else{
            while(--idx)
            {
                p=p->getNext();
            }
            value->setNext(p->getNext());
            p->getNext()->setPre(value);
            p->setNext(value);
            value->setPre(p);
        }
    }
}
// remove with index i
template<typename T>
void removeLL(SingleLinkedList<T>*& head,int idx){
    SingleLinkedList<T>* p=head;
    if(idx==0)
    {
        head=p->getNext();
        delete p;
    }
    else{
        while(--idx) {
            p=p->getNext();
        }
        SingleLinkedList<T>* q=p->getNext();
        p->setNext(q->getNext());
        delete q;
    }
}
template<typename T>
void removeLL(DoublyLinkedList<T>* &head,int idx)
{
    if (idx>=size(head)) return;
    DoublyLinkedList<T>* p=head;
    if(idx==0)
    {
        head=p->getNext();
        head->setPre(nullptr);
        delete p;
    }
    else
    {
        while(--idx)
        {
            p=p->getNext();
        }
        DoublyLinkedList<T>* q=p->getNext();
        p->setNext(q->getNext());
        if (p->getNext() !=nullptr) p->getNext()->setPre(p);
        delete q;
    }
    return;
}
// push
template<typename T>
void push(SingleLinkedList<T>* &head, T data)
{
    SingleLinkedList<T>* node =new SingleLinkedList<T> (data);
    node->setNext(head);
    head=node;
}
template<typename T>
void push(DoublyLinkedList<T>* &head, T data)
{
    DoublyLinkedList<T>* node =new DoublyLinkedList<T> (data);
    node->setNext(head);
    head=node;
}
template<typename T>
void pop(SingleLinkedList<T>* &head, T data)
{
    SingleLinkedList<T>* p= head;
    head=head->getNext();
    delete p;
}
template<typename T>
void pop(DoublyLinkedList<T>* &head, T data)
{
    DoublyLinkedList<T>* p=head;
    head=head->getNext();
    head->setPre(nullptr);
    delete p;
}
// reverse
template<typename T>
void reverse(SingleLinkedList<T>* &head)
{
    SingleLinkedList<T>* current= head;
    SingleLinkedList<T>* next= nullptr;
    SingleLinkedList<T>* prev= nullptr;
    while (current)
    {
        next=current->getNext();
        current->setNext(prev);
        current=next;
        prev=current;
    }
    head=prev;
}
template<typename T>
void reverse(DoublyLinkedList<T>* &head)
{
    DoublyLinkedList<T>* current= head;
    DoublyLinkedList<T>* temp= nullptr;
    DoublyLinkedList<T>* next= head->getNext();
    while (current)
    {
        /* code */
        current->setNext(temp);
        current->setPre(next);
        temp=current;
        current=next;
        if (next)
        next=next->getNext();
    }
    head=temp;
}









#endif