#ifndef Structure_H
#define Structure_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class DynamicArray{
    int size;
    int capacity;
    int* storage;
    public:
    DynamicArray()
    {
        capacity=10;
        size=0;
        storage= new int [capacity];
    
    }
    DynamicArray(int capacity)
    {
        this->capacity= capacity;
        size=0;
        storage= new int [capacity];
    }
    ~DynamicArray() 
        { delete [] storage;}
    void setCapcity(int);
    void ensureCapcity(int);
    void pack();
    void trim();

    void rangeCheck(int);
    void set(int, int );
    int get(int);
    void removeAt(int);
    void insertAt(int,int);
    void print();
};
//some func to declare
    void DynamicArray::setCapcity(int cap)
    {
        int* newStorage= new int[cap];
        memcpy(newStorage,storage,sizeof(int)*size);
        capacity=cap;
        delete storage;
        storage=newStorage;
    }
    void DynamicArray::ensureCapcity(int minCapacity)
    {
        if(minCapacity>capacity)
        {
            int newCapacity= (capacity*3)/2 +1;
            if( newCapacity<minCapacity)
                newCapacity=minCapacity;
            setCapcity(newCapacity);
        }
    }
    void DynamicArray::pack()
    {
        if(size<=capacity/2)
        {
            int newCapcity=(size*3)/2+1;
            setCapcity(newCapcity);
        }
    }
    void DynamicArray::trim()
    {
        int newCapacity= size;
        setCapcity(newCapacity);
    }
    void DynamicArray:: rangeCheck(int index){
        if(index<0 || index>= size)
            throw "Out of range\n";
    }
    void DynamicArray::set(int index,int value)
    {
        rangeCheck(index);
        *(storage+index)=value;
    }
    int  DynamicArray::get(int index)
    {
        rangeCheck(index);
        return *(storage+index);
    }
    void DynamicArray::insertAt(int idx, int value)
    {
        if(idx< 0 || idx > size)
            throw "Out of bounds!";
        ensureCapcity(size+1);
        int moveCount= size-idx;
        if (moveCount!=0)
        {
            memmove(storage+idx+1,storage+idx,sizeof(int)*moveCount);
        }
        storage[idx]=value;
        size++;
    }
    void DynamicArray::removeAt(int idx)
    {
        rangeCheck(idx);
        int moveCount=size-idx-1;
        if( moveCount>0)
            memmove(storage+idx,storage+(idx+1),sizeof(int)*moveCount);
        size--;
        pack();
    }
    void DynamicArray::print()
    {
        for(int i=0;i<size;i++)
            cout<<storage[i]<<' ';
    }
     


#endif