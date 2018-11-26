//
// Created by Gabriel Abarca Aguilar on 23/11/18.
//

#ifndef TECMEDIAFILESYSTEM_AVLTREE_H
#define TECMEDIAFILESYSTEM_AVLTREE_H

#include "VideoFile.h"

enum Color {RED, BLACK};


struct Node {

    VideoFile data = NULL;
    bool color;
    Node *left, *right, *parent;

    //Constructor
    Node(VideoFile data){
        this->data = data;
        left = right = parent = NULL;
    }
};

class RBTree {
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    RBTree() {root = NULL;}
    void insert(const VideoFile &n);
    void inorder();
    void levelOrder();
};


#endif //TECMEDIAFILESYSTEM_AVLTREE_H
