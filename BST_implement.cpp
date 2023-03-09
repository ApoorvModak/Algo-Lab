#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *NewNode(int data){
    struct node *node1 = new struct node;
    node1->data = data;
    node1->left = NULL;
    node1->right = NULL;
    return node1;
}

bool insert(int value, struct node *root){
    struct node *prev;
    struct node *ptr;
    while(root != NULL){
        prev = root;
        if(value == root->data){
            return false;
        }
        else if(value < root->data){
            root = root->left;
        }
        else{ //(value  is = root->data)
            root = root->right;
        }
    }
    root = NewNode(value);
    if(prev->data > root->data){
        prev->left = root;
    }
    else{
        prev->right = root;
    }
    return true;
}

void inorder(struct node *root){
    if(root != NULL){
        //base case that is if it is a leaf node
        inorder(root->left);
        printf("%d, ",root->data);
        inorder(root->right); 
    }
} 
// wrong function
struct node *search(struct node *root, int data){
    //base cases
    if (root = NULL){
        printf("given element is not present");
        return NULL;
    }
    else if(root->data == data){
        return root;
    }
    else if(data < root->data){
        root = root->left;
    }
    else{ //(data > root->data)
        root = root->right;
    }
    return NULL;
}

struct node *Delete(struct node *root, int data){
    // search for the node to be deleted:
    if(root == NULL){
        printf("given element absent");
        return NULL;
    }
}

int main(){
    struct node *root = NewNode(9);
    insert(15,root);
    insert(4,root);
    insert(50,root);
    insert(37,root);
    insert(14,root);
    printf("%d, %d \n", root->right->left->data, root->right->right->left->data);
    inorder(root);
    return 0; 
}

