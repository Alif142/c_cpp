#include "bst.h"
#include "queuetype.cpp"
#include <iostream>
using namespace std;
template <class T>
BST<T>::BST()
{
    root = NULL;
}
template <class T>
void Destroy(Node<T>* &tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
        tree = NULL;
    }
}
template <class T>
BST<T>::~BST()
{
    Destroy(root);
}
template <class T>
void BST<T>::MakeEmpty()
{
    Destroy(root);
}
template <class T>
bool BST<T>::IsEmpty()
{
    return root == NULL;
}
template <class T>
bool BST<T>::IsFull()
{
    try
    {
        Node<T>* temp = new Node<T>;
        delete temp;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class T>
int CountNodes(Node<T>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}
template <class T>
int BST<T>::Length()
{
    return CountNodes(root);
}
template <class T>
void SearchValue(Node<T>* tree, T &value, bool &found)
{
    if (tree == NULL)
        found = false;
    else if (value < tree->data)
        SearchValue(tree->left, value, found);
    else if (value > tree->data)
        SearchValue(tree->right, value, found);
    else
    {
        value = tree->data;
        found = true;
    }
}
template <class T>
void BST<T>::Search(T &value, bool &found)
{
    SearchValue(root, value, found);
}
template <class T>
void InsertValue(Node<T>* &tree, T value)
{
    if (tree == NULL)
    {
        tree = new Node<T>;
        tree->right = NULL;
        tree->left = NULL;
        tree->data = value;
    }
// Otherwise, recursively Insert the value
    else if (value < tree->data)
        InsertValue(tree->left, value); // Insert in left subtree
    else
        InsertValue(tree->right, value); // Insert in right subtree
}
template <class T>
void BST<T>::Insert(T value)
{
    InsertValue(root, value);
}
template <class T>
void DeleteValue(Node<T>* &tree, T value)
{
    if (value < tree->data)
        DeleteValue(tree->left, value);
    else if (value > tree->data)
        DeleteValue(tree->right, value);
    else
        DeleteNode(tree);
}
template <class T>
void DeleteNode(Node<T>* &tree)
{
    T data;
    Node<T>* temp = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete temp;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete temp;
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->data = data;
        DeleteValue(tree->left, data);
    }
}
template <class T>
void GetPredecessor(Node<T> *tree, T &data)
{
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    data = tree->data;
}
template <class T>
void BST<T>::Delete(T value)
{
    DeleteValue(root, value);
}
template <class T>
void PreOrder(Node<T> *tree, QueueType<T> &queue)
{
    if (tree != NULL)
    {
        queue.Enqueue(tree->data);
        PreOrder(tree->left, queue);
        PreOrder(tree->right, queue);
    }
}
template <class T>
void InOrder(Node<T> *tree, QueueType<T> &queue)
{
    if (tree != NULL)
    {
        InOrder(tree->left, queue);
        queue.Enqueue(tree->data);
        InOrder(tree->right, queue);
    }
}
template <class T>
void PostOrder(Node<T>* tree, QueueType<T> &queue)
{
    if (tree != NULL)
    {
        PostOrder(tree->left, queue);
        PostOrder(tree->right, queue);
        queue.Enqueue(tree->data);
    }
}
template <class T>
void BST<T>::GetNext(T &value, OrderType order)
{
    bool finished = false;
    switch (order)
    {
    case PRE_ORDER:
        preQue.Dequeue(value);
        if(preQue.IsEmpty())
            finished = true;
        break;
    case IN_ORDER:
        inQue.Dequeue(value);
        if(inQue.IsEmpty())
            finished = true;
        break;
    case POST_ORDER:
        postQue.Dequeue(value);
        if(postQue.IsEmpty())
            finished = true;
        break;
    }
}
template<class T>
void BST<T>::Reset(OrderType order)
{
    switch (order)
    {
    case PRE_ORDER:
        PreOrder(root, preQue);
        break;
    case IN_ORDER:
        InOrder(root, inQue);
        break;
    case POST_ORDER:
        PostOrder(root, postQue);
        break;
    }
}
template <class T>
void PrintTree(Node<T>* tree)
{
    if (tree != NULL)
    {
        PrintTree(tree->left);
        cout << tree->data << " ";
        PrintTree(tree->right);
    }
}
template <class T>
void BST<T>::Print()
{
    PrintTree(root);
}


template<class T>
void BST<T>::BuildBST(T arr[] , int start , int end){
    if (start <= end) {
        int mid = (start+end)/2; 
        Insert(arr[mid]);
        BuildBST(arr,start,mid-1);
        BuildBST(arr,mid+1,end);
    }
}


template<class T>
void BST<T>::BuildOptimalTree(){
    T arr[Length()];
    T value;
    int n = sizeof(arr)/sizeof(arr[0]);
    Reset(IN_ORDER);
    for (int i=0;i<Length();i++) {
        GetNext(value,IN_ORDER); 
        arr[i] = value;
    }
    Destroy(root);
    BuildBST(arr,0,n-1);
}



template class BST<int>;
