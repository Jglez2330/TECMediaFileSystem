//
// Created by Gabriel Abarca Aguilar on 23/11/18.
//

#ifndef TECMEDIAFILESYSTEM_AVLTREE_H
#define TECMEDIAFILESYSTEM_AVLTREE_H

#include <bits/stdc++.h>
#include "VideoFile.h"

enum Color {RED, BLACK};

class Node {

public:
    VideoFile * data = nullptr;
    Color color;
    Node *left, *right, *parent;
    //Constructor
    Node(VideoFile* data){
        this->data = data;
        left = right = parent = NULL;
        color = RED;
    }
    // returns pointer to uncle
    Node *uncle() {
        // If no parent or grandparent, then no uncle
        if (parent == NULL or parent->parent == NULL)
            return NULL;

        if (parent->isOnLeft())
            // uncle on right
            return parent->parent->right;
        else
            // uncle on left
            return parent->parent->left;
    }

    // check if node is left child of parent
    bool isOnLeft() { return this == parent->left; }

    // returns pointer to sibling
    Node *sibling() {
        // sibling null if no parent
        if (parent == NULL)
            return NULL;

        if (isOnLeft())
            return parent->right;

        return parent->left;
    }

    // moves node down and moves given node in its place
    void moveDown(Node *nParent) {
        if (parent != NULL) {
            if (isOnLeft()) {
                parent->left = nParent;
            } else {
                parent->right = nParent;
            }
        }
        nParent->parent = parent;
        parent = nParent;
    }

    bool hasRedChild() {
        return (left != NULL and left->color == RED) or
               (right != NULL and right->color == RED);
    }
};

class RBTree {
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);

    //Delete Methods
    void leftRotate(Node *x);
    void rightRotate(Node *x);
    void swapColors(Node *x1, Node *x2);
    void swapValues(Node *u, Node *v);
    void fixRedRed(Node *x);
    Node *successor(Node *x);
    Node *BSTreplace(Node *x);
    void deleteNode(Node *v);
    void fixDoubleBlack(Node *x);
    Node* search(std::string n);
public:
    RBTree() {root = NULL;}
    void insert(VideoFile *);
    void inorder();
    void levelOrder();
    void deleteValue(std::string);
    VideoFile * getValue(std::string);

};


#endif //TECMEDIAFILESYSTEM_AVLTREE_H
