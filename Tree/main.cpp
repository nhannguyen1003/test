#include"header.h"


int main()
{
    Node<int>* bT=nullptr;
    Insert(bT,5);
    Insert(bT,10);
    Insert(bT,15);
    Insert(bT,3);
    Insert(bT,6);
    Insert(bT,1);
    printPreOrder(bT);


    return 0;
}