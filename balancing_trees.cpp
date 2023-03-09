#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

struct node {
    int key;
    struct node *parent;
    struct node *left;
    struct node *right;
};

struct node *createNode(int key){
    struct node *node1 = new struct node;
    node1->key = key;
    node1->left = NULL;
    node1->right = NULL;
    node1->parent = NULL;
    return node1;
}

struct node *insert(int key, struct node *root){
    if(root == NULL){
        root = createNode(key);
        return root;
    }
    else{ //(root != NULL):
        struct node *ptr = root;
        struct node *prev = NULL;

        while(ptr != NULL){
            prev = ptr;
            if(ptr->key == key){
                cout << "given element present in the tree" << endl;
                return root;
            }
            else if(key < ptr->key){
                ptr = ptr->left;
            }
            else{ // (x > ptr->key)
                ptr = ptr->right;
            }
        }

        ptr = createNode(key);
        if(ptr->key < prev->key){
            prev->left = ptr;
        }
        else{
            prev->right = ptr;
        }
    }
    return root;
}

bool isValidBST(struct node* root) {

    if(root == NULL){
        return true;
    }
    else {
        if(root->left != NULL){
            struct node *lft = root->left;
            while(lft->right != NULL){
                lft = lft->right;
            }
            if(lft->key >= root->key){
                return false;
            }
        }
        if(root->right != NULL){
            struct node *rgt = root->right;
            while(rgt->left != NULL){
                rgt = rgt->left;
            }
            if(rgt->key <= root->key){
                return false;
            }
        }
        return (isValidBST(root->left) and isValidBST(root->right)) ;
    }

}
void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root != NULL){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);

    }
}

int main(){

    struct node *T = NULL;
    int n, data;

    cout << "Enter n :" << endl;
    cin >> n;
    cout << "n = " << n << endl;

    // key insertion in the data
    cout << "Enter keys to insert" << endl;
    while(n > 0){
        cin >> data;
        T = insert(data,T);
        n-=1;
    }

    inorder(T);
    preorder(T);
    cout << isValidBST(T);

    return 0;
}

