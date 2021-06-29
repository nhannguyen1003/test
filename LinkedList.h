#ifndef LinkedList_h
#define LinkedList_h

#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>


using namespace std;

template<typename T>
class SingleLinkedList{
    SingleLinkedList* next;
    T data;
    public:
    SingleLinkedList() :data(0),next(nullptr) {}
    SingleLinkedList(T data,SingleLinkedList* next) : data(data),next(next) {}
    SingleLinkedList(T data) : data(data),next(nullptr) {}
    T getData() 
        {
            return data;
        }
    void setData(T a)
        {
            data=a;
        }
    SingleLinkedList* getNext()
    {
        return next;
    }
    void setNext(SingleLinkedList* next)
    {
        this->next=next;
    }
    
};
template <typename T>
class DoublyLinkedList{
    DoublyLinkedList* pre;
    DoublyLinkedList* next;
    T data;
    public:
    DoublyLinkedList() :data(0),pre(nullptr),next(nullptr) {}
    DoublyLinkedList(T data) : data(data),next(nullptr),pre(nullptr) {}
    DoublyLinkedList(T data,DoublyLinkedList* pre, DoublyLinkedList* next) 
        :data(data), pre(pre), next(next) {}

    T getData() 
        {
            return data;
        }
    void setData(T a)
        {
            data=a;
        } 
    DoublyLinkedList* getPre()
    {
        return pre;
    }
    void setPre(DoublyLinkedList* pre)
    {
        this->pre=pre;
    }
    DoublyLinkedList* getNext()
    {
        return next;
    }
    void setNext(DoublyLinkedList* next)
    {
        this->next=next;
    }
};

#endif