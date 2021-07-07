#ifndef Stack_H
#define Stack_H

#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

template<class T>
struct Node{
    T data;
    Node<T> *next;

};
template<class T>
class Stack{
    public:
    Stack();
    ~Stack();
    void Push(T dataIn);
    int Pop (T &dataOut);
    int GetStackTop(T & dataOut);
    void Clear();
    int IsEmpty();
    int GetSize();
    Stack<T>* Clone();
    void Print2Console();
    private:
    Node<T>* top;
    int count;
};

template<class T>
Stack<T>:: Stack(){
    top=nullptr;
    count=0;
}

template<class T>
Stack<T>::~Stack()
{
    this->Clear();
}

template<class T>
void Stack<T>:: Push(T dataIn)
{
    Node<T> *pNew=new Node<T>();
    pNew->data=dataIn;
    pNew->next=this->top;
    this->top=pNew;
    this->count++;
}

template<class T> 
int Stack<T>::Pop(T &dataOut)
{
    if(this->GetSize()==0) return 0;
    Node<T> *del=this->top;
    dataOut=this->top->data;
    this->top=del->next;
    this->count--;
    delete del;
    return 1;
 }
 
template<class T>
int Stack<T>::GetStackTop(T &dataOut)
{
    if(this->GetSize()==0)
        return 0;
    dataOut=this->top->data;
    return 1;
}

template<class T>
void Stack<T>:: Clear()
{
    Node<T>* temp;
    while(this->top!=NULL) {
        temp=temp->next;
        this->top=this->top->next;
        delete temp;
    }
    this->count=0;
}

template<class T>
int Stack<T>:: IsEmpty(){
    return !(top);
}

template<class T>
void Stack<T>::Print2Console()
{
    Node<T> * ptr=this->top;
    while (ptr)
    {
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    cout<<endl;
}
template<class T>
int Stack<T>::GetSize(){
    int count=0;
    Node<T>* ptr= this->top;

    while(ptr!=nullptr) 
    {
        count++;
        ptr=ptr->next;
    }
    return  count;
}

#endif