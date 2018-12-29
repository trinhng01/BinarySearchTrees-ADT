// Binary Search Tree ADT
// Created by Frank M. Carrano and Tim Henry.
// Modified by Trinh Nguyen

//  CIS 22C-02Y
//  M/W 1:30 - 3:20
//  Professor Delia Gârbacea
//  Trinh Nguyen
//  February 26, 2017
//  Homework #4
//  IDE: Xcode

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{
private:
    // internal insert node: insert newNode in nodePtr subtree
    void _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);
    
    // internal remove node: locate and delete target node under nodePtr subtree
    BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool & success);
    
    // delete target node from tree, called by internal remove node
    BinaryNode<ItemType>* deleteNode(BinaryNode<ItemType>* targetNodePtr);
    
    // remove the leftmost node in the left subtree of nodePtr
    BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType & successor);
    
    // search for target node
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType & target) const;
    
    //find most right in tree
    BinaryNode<ItemType>* _findLargest(BinaryNode<ItemType>* root);
    
    //find most left in tree
    BinaryNode<ItemType>* _findSmallest(BinaryNode<ItemType>* root);
    
public:
    // insert a node at the correct location
    bool insert(const ItemType & newEntry);
    // remove a node if found
    bool remove(const ItemType & anEntry);
    // find a target node
    bool getEntry(const ItemType & target, ItemType & returnedItem) const;
    // find largest
    BinaryNode<ItemType>* findLargest();
    // find smallest
    BinaryNode<ItemType>* findSmallest();
};


///////////////////////// public function definitions ///////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
    if (this->rootPtr == nullptr) {
        this->rootPtr = new BinaryNode<ItemType>(newEntry);
        this->count++;
    }
    else {
        BinaryNode<ItemType>* nodePtr = new BinaryNode<ItemType>(newEntry);
        _insert(this->rootPtr, nodePtr);
    }
    return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target)
{
    bool isSuccessful = false;
    this->rootPtr = _remove(this->rootPtr, target, isSuccessful);
    return isSuccessful;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry, ItemType & returnedItem) const
{
    
    return false;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findLargest()
{
    BinaryNode<ItemType>* rootCopy;
    BinaryNode<ItemType>* ItemNode;
    rootCopy = this->rootPtr;
    ItemNode = _findLargest(rootCopy);
    return ItemNode;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findSmallest()
{
    BinaryNode<ItemType>* rootCopy;
    BinaryNode<ItemType>* ItemNode;
    rootCopy = this->rootPtr;
    ItemNode = _findSmallest(rootCopy);
    return ItemNode;
}

//////////////////////////// private functions ////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                         BinaryNode<ItemType>* newNodePtr)
{
    if (newNodePtr->getItem() < nodePtr->getItem())
    {
        if (nodePtr->getLeftPtr() != nullptr)
        {
            _insert(nodePtr->getLeftPtr(), newNodePtr);
        }
        else // until its left child is null
        {
            nodePtr->setLeftPtr(newNodePtr);
            this->count++;
        }
    }
    else if (newNodePtr->getItem() > nodePtr->getItem() || newNodePtr->getItem() == nodePtr->getItem())
    {
        if (nodePtr->getRightPtr() != nullptr)
        {
            _insert(nodePtr->getRightPtr(), newNodePtr);
        }
        else
        {
            nodePtr->setRightPtr(newNodePtr);
            this->count++;
        }
    }
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
                                                          const ItemType target,
                                                          bool & success)

{
    if (nodePtr == 0)
    {
        success = false;
        return 0;
    }
    if (nodePtr->getItem() > target)
        nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
    else if (nodePtr->getItem() < target)
        nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
    else
    {
        nodePtr = deleteNode(nodePtr);
        success = true;
    }
    return nodePtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType>* nodePtr)
{
    if (nodePtr->isLeaf())
    {
        delete nodePtr;
        nodePtr = 0;
        return nodePtr;
    }
    else if (nodePtr->getLeftPtr() == 0)
    {
        BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightPtr() == 0)
    {
        BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else
    {
        ItemType newNodeValue;
        nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType & successor)
{
    if (nodePtr->getLeftPtr() == 0)
    {
        successor = nodePtr->getItem();
        return deleteNode(nodePtr);
    }
    else
    {
        nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
        return nodePtr;
    }
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_findLargest(BinaryNode<ItemType>* root)
{
    BinaryNode<ItemType>* rootTemp;
    if (root->getRightPtr() != NULL)
    {
        rootTemp = _findLargest(root->getRightPtr());
        return rootTemp;
    }
    else
        return root;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_findSmallest(BinaryNode<ItemType>* root)
{
    BinaryNode<ItemType>* rootTemp;
    if (root->getLeftPtr() != NULL)
    {
        rootTemp = _findSmallest(root->getLeftPtr());
        return rootTemp;
    }
    else
        return root;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr,
                                                           const ItemType & target) const
{
    BinaryNode<ItemType>* pCurr;
    ItemType compareTemp;
    pCurr = nodePtr;
    
    while (pCurr != NULL)
    {
        compareTemp = pCurr->getItem();
        if (target.getStudentID() < compareTemp.getStudentID())
            pCurr = pCurr->getLeftPtr();
        else if (target.getStudentID() > compareTemp.getStudentID())
            pCurr = pCurr->getRightPtr();
        else
            return pCurr;
    }
    return pCurr;
}


#endif
