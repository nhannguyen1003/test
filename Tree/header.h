#ifndef tree_H
#define tree_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node() :left(nullptr),right(nullptr),data(0) {}
    Node(Node<T>* l,Node<T>* r,T data) :left(l),right(r),data(data) {}
};

template<class T>
class BinaryTree{
    public:
    Node<T>* root;
    BinaryTree() : root(nullptr) {}
    BinaryTree(Node<T>* root) :root(root) {}
};
    void printPreOrder(Node<int>* root);
    void printInOrder(Node<int>* root);
    void printPostOrder(Node<int>* root);
    void printBf(Node<int>* root);
    int min(Node<int>* root);
    int max(Node<int>* root);
    void insert(Node<int>* root,int n_data);
    void remove(Node<int>* root,int data);
    Node<int>* search(Node<int>* root,int data);
    /*print expression tree*/
    void printPreOrderExp(Node<string>* root) ;
    void printInOrderExp(Node<string>* root);
    void printPostOrderExp(Node<string>* root);

//print
// preOrder traversal
void printPreOrder(Node<int>* root)
{
    if (root!=nullptr)
    {
    cout<<root->data<<' ';
    printPreOrder(root->left);
    printPreOrder(root->right);
    }
    return;
}
void printPostOrder(Node<int>* root)
{
    if (root!=nullptr){

        printPostOrder(root->left);
        printPostOrder(root->right);
        cout<<root->data<<' ';
    }
}

void printInOrder(Node<int>* root)
{
    if (root !=nullptr)
    {
    printInOrder(root->left);
    cout<<root->data<<' ';
    printInOrder(root->right);
    }

}
/* we must have class queue to solve this problem
    To solve this problem we creat new enqueu to save node FIFO
    enqueue in left right

    while currentNode not null do
    process(currentNode)
    if currentNode->left not null then
        enqueue(bfQueue, currentNode->left)
    end
    if currentNode->right not nul then
        enqueue(bfQueue, currentNode->right)
    end
    if not emptyQueue(bfQueue) then
        currentNode = dequeue(bfQueue)
    else
        currentNode = NULL
    end
    end
    dequeue left*/
void printBf(Node<int>* root)
{
    if(root !=nullptr)
    {

    }
}

void printPreOrderExp(Node<string>* root)
{
    if (root!=nullptr)
    {
        cout<<root->data;
        printPreOrderExp(root->left);
        printPreOrderExp(root->right);
    }

}

void printPostOrderExp(Node<string>* root)
{
    if (root!=nullptr)
    {
        printPostOrderExp(root->left);
        printPostOrderExp(root->right);
        cout<<root->data;
    }
}

void printInOrderExp(Node<string>* root)
{
    if(root!=nullptr)
    {
        if( root->data =="+" 
          || root->data=="-"
          || root->data=="*"
          || root->data=="/" ) cout<<root->data;
        else{
            cout<<"(";
            printInOrderExp(root->left);
            cout<<root->data;
            printInOrderExp(root->right);
            cout<<")";
        }
    }
}
int min(Node<int>* root)
{
    if(root->left==nullptr) return root->data;
    return min(root->left);
}
int max(Node<int>* root)
{
    if(root->right==nullptr) return root->data;
    return max(root->right);
}


Node<int>* search(Node<int>* root,int data)
{
    if(root==nullptr) return nullptr;
    if(data < root->data) search(root->left,data);
    else if (data>root->data) search(root->right,data);
     return root;
}
Node<int>* IterativeSearch(Node<int>* root,int target)
{
    while (root!=nullptr && root->data!= target)
    {
        if(root->data >target) root=root->right;
        else root=root->left;
    }
    return root;
}
//insert 
void IterativeInsert(Node<int>*& root,int n_data){
    if (root==nullptr)
    {
        root=new Node<int>(nullptr,nullptr,n_data);
    }
    else {
        Node<int>* p=root;
        Node<int>* parent;
        while (p!=nullptr)
        {
            parent=p;
            if(n_data<root->data) p=p->left;
            else p=p->right;
        }
        if(n_data>parent->data) parent->right=new Node<int>(nullptr,nullptr,n_data);
        else parent->left=new Node<int> (nullptr,nullptr,n_data);
    }
}
void Insert(Node<int>* &root,int n_data)
{
    if(root==nullptr)
    {
        root=new Node<int>(nullptr,nullptr,n_data);
    }
    else
    {
        if(n_data>root->data) Insert(root->right,n_data);
        else Insert(root->left,n_data);

    }
}


#endif 