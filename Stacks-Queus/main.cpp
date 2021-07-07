#include "stack.h"

int main(int argc,char* argv[])
{
    int val;
    Stack<int>* myStack=new Stack<int>();
    myStack->Push(5);
    myStack->Push(6);
    myStack->Push(10);
    myStack->Print2Console();
    myStack->Pop(val);
    printf("wtf %d",val);
    delete myStack;
}