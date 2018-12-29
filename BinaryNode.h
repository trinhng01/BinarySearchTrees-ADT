// Node for a binary tree
// Created by Frank M. Carrano and Tim Henry.
// Modified by Trinh Nguyen

//  CIS 22C-02Y
//  M/W 1:30 - 3:20
//  Professor Delia Gârbacea
//  Trinh Nguyen
//  February 26, 2017
//  Homework #4
//  IDE: Xcode

#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode
{
private:
    ItemType              item;         // Data portion
    BinaryNode<ItemType>* leftPtr;		// Pointer to left child
    BinaryNode<ItemType>* rightPtr;		// Pointer to right child
    
public:
    // constructors
    BinaryNode() { leftPtr = 0; rightPtr = 0; }
    BinaryNode(const ItemType & anItem) { item = anItem; leftPtr = 0; rightPtr = 0; }
    BinaryNode(const ItemType & anItem,
               BinaryNode<ItemType>* left,
               BinaryNode<ItemType>* right) {item = anItem; leftPtr = left; rightPtr = right;}
    // accessors
    void setItem(const ItemType & anItem) {item = anItem;}
    void setLeftPtr(BinaryNode<ItemType>* left) {leftPtr = left;}
    void setRightPtr(BinaryNode<ItemType>* right) {rightPtr = right;}
    
    // mutators
    ItemType getItem()	 {return item;}
    BinaryNode<ItemType>* getLeftPtr() const  {return leftPtr;}
    BinaryNode<ItemType>* getRightPtr() const {return rightPtr;}

    bool isLeaf() const {return (leftPtr == 0 && rightPtr == 0);}};

#endif
