//
// Created by Gabriel Abarca Aguilar on 23/11/18.
//

#include "RBTree.h"


/**
 * Recursive function to do level order traversal
 * @param root
 */
void inorderHelper(Node *root){
    if (root == NULL)
        return;

    inorderHelper(root->left);
    std::cout << root->data->getName() << " ";
    inorderHelper(root->right);
}
/**
 * A utility function to insert a new node with given key
   in BST
 * @param root
 * @param pt
 * @return
 */
Node* BSTInsert(Node* root, Node *pt){
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return pt;

    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}
/**
 * Does level order traversal
 * @param root
 */
void levelOrderHelper(Node *root)
{
    if (root == NULL)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        std::cout << temp->data->getName() << "  ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}
void RBTree::rotateLeft(Node *&root, Node *&pt){
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}
void RBTree::rotateRight(Node *&root, Node *&pt){
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}
void RBTree::fixViolation(Node *&root, Node *&pt){
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {

            Node *uncle_pt = grand_parent_pt->right;

            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }

            /* Case : B
               Parent of pt is right child of Grand-parent of pt */
        else
        {
            Node *uncle_pt = grand_parent_pt->left;

            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}
void RBTree::insert(VideoFile *data){
    Node *pt = new Node(data);

    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // fix Red Black Tree violations
    fixViolation(root, pt);
}
// left rotates the given node
void RBTree::leftRotate(Node *x) {
    // new parent will be node's right child
    Node *nParent = x->right;

    // update root if current node is root
    if (x == root)
        root = nParent;

    x->moveDown(nParent);

    // connect x with new parent's left element
    x->right = nParent->left;
    // connect new parent's left element with node
    // if it is not null
    if (nParent->left != NULL)
        nParent->left->parent = x;

    // connect new parent with x
    nParent->left = x;
}

void RBTree::rightRotate(Node *x) {
    // new parent will be node's left child
    Node *nParent = x->left;

    // update root if current node is root
    if (x == root)
        root = nParent;

    x->moveDown(nParent);

    // connect x with new parent's right element
    x->left = nParent->right;
    // connect new parent's right element with node
    // if it is not null
    if (nParent->right != NULL)
        nParent->right->parent = x;

    // connect new parent with x
    nParent->right = x;
}

void RBTree::swapColors(Node *x1, Node *x2) {
    Color temp;
    temp = x1->color;
    x1->color = x2->color;
    x2->color = temp;
}

void RBTree::swapValues(Node *u, Node *v) {
    VideoFile * temp;
    temp = u->data;
    u->data = v->data;
    v->data = temp;
}
Node* RBTree::search(std::string n){
    std::cout << n << std::endl;
    Node * temp = root;
    while (temp != NULL){
        std::cout << "Hola" << std::endl;
        if (n < temp->data->getName()){
            if (temp->left == NULL)
                break;
            else
                temp = temp->left;
        } else if(n == temp->data->getName()){
            break;
        }else{
            if (temp->right==NULL)
                break;
            else
                temp = temp->right;
        }
    }
    return temp;
}


// find node that do not have a left child
// in the subtree of the given node
Node * RBTree::successor(Node *x) {
    Node *temp = x;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}
void RBTree::fixRedRed(Node *x) {
    // if x is root color it black and return
    if (x == root) {
        x->color = BLACK;
        return;
    }

    // initialize parent, grandparent, uncle
    Node *parent = x->parent, *grandparent = parent->parent,
            *uncle = x->uncle();

    if (parent->color != BLACK) {
        if (uncle != NULL && uncle->color == RED) {
            // uncle red, perform recoloring and recurse
            parent->color = BLACK;
            uncle->color = BLACK;
            grandparent->color = RED;
            fixRedRed(grandparent);
        } else {
            // Else perform LR, LL, RL, RR
            if (parent->isOnLeft()) {
                if (x->isOnLeft()) {
                    // for left right
                    swapColors(parent, grandparent);
                } else {
                    leftRotate(parent);
                    swapColors(x, grandparent);
                }
                // for left left and left right
                rightRotate(grandparent);
            } else {
                if (x->isOnLeft()) {
                    // for right left
                    rightRotate(parent);
                    swapColors(x, grandparent);
                } else {
                    swapColors(parent, grandparent);
                }

                // for right right and right left
                leftRotate(grandparent);
            }
        }
    }
}
// find node that replaces a deleted node in BST
Node * RBTree::BSTreplace(Node *x) {
    // when node have 2 children
    if (x->left != NULL and x->right != NULL)
        return successor(x->right);

    // when leaf
    if (x->left == NULL and x->right == NULL)
        return NULL;

    // when single child
    if (x->left != NULL)
        return x->left;
    else
        return x->right;
}
void RBTree::deleteNode(Node *v) {
    Node *u = BSTreplace(v);

    // True when u and v are both black
    bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
    Node *parent = v->parent;

    if (u == NULL) {
        // u is NULL therefore v is leaf
        if (v == root) {
            // v is root, making root null
            root = NULL;
        } else {
            if (uvBlack) {
                // u and v both black
                // v is leaf, fix double black at v
                fixDoubleBlack(v);
            } else {
                // u or v is red
                if (v->sibling() != NULL)
                    // sibling is not null, make it red"
                    v->sibling()->color = RED;
            }

            // delete v from the tree
            if (v->isOnLeft()) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
        delete v;
        return;
    }

    if (v->left == NULL or v->right == NULL) {
        // v has 1 child
        if (v == root) {
            // v is root, assign the value of u to v, and delete u
            v->data = u->data;
            v->left = v->right = NULL;
            delete u;
        } else {
            // Detach v from tree and move u up
            if (v->isOnLeft()) {
                parent->left = u;
            } else {
                parent->right = u;
            }
            delete v;
            u->parent = parent;
            if (uvBlack) {
                // u and v both black, fix double black at u
                fixDoubleBlack(u);
            } else {
                // u or v red, color u black
                u->color = BLACK;
            }
        }
        return;
    }

    // v has 2 children, swap values with successor and recurse
    swapValues(u, v);
    deleteNode(u);
}
void RBTree::fixDoubleBlack(Node *x) {
    if (x == root)
        // Reached root
        return;

    Node *sibling = x->sibling(), *parent = x->parent;
    if (sibling == NULL) {
        // No sibiling, double black pushed up
        fixDoubleBlack(parent);
    } else {
        if (sibling->color == RED) {
            // Sibling red
            parent->color = RED;
            sibling->color = BLACK;
            if (sibling->isOnLeft()) {
                // left case
                rightRotate(parent);
            } else {
                // right case
                leftRotate(parent);
            }
            fixDoubleBlack(x);
        } else {
            // Sibling black
            if (sibling->hasRedChild()) {
                // at least 1 red children
                if (sibling->left != NULL and sibling->left->color == RED) {
                    if (sibling->isOnLeft()) {
                        // left left
                        sibling->left->color = sibling->color;
                        sibling->color = parent->color;
                        rightRotate(parent);
                    } else {
                        // right left
                        sibling->left->color = parent->color;
                        rightRotate(sibling);
                        leftRotate(parent);
                    }
                } else {
                    if (sibling->isOnLeft()) {
                        // left right
                        sibling->right->color = parent->color;
                        leftRotate(sibling);
                        rightRotate(parent);
                    } else {
                        // right right
                        sibling->right->color = sibling->color;
                        sibling->color = parent->color;
                        leftRotate(parent);
                    }
                }
                parent->color = BLACK;
            } else {
                // 2 black children
                sibling->color = RED;
                if (parent->color == BLACK)
                    fixDoubleBlack(parent);
                else
                    parent->color = BLACK;
            }
        }
    }
}
//Public
VideoFile * RBTree::getValue(std::string name){
    return search(name)->data;
}
void RBTree::deleteValue(std::string name) {
    if (root == NULL){
        //Tree is empty
    }
    Node *v = search(name) , *u;

    if (v->data->getName() != name){
        std::cout<<"Video not found"<<std::endl;
    }
    deleteNode(v);
}
void RBTree::inorder(){
    inorderHelper(root);
}
void RBTree::levelOrder(){
    levelOrderHelper(root);
}