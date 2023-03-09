#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *node1 = new struct node;
    node1->data = data;
    node1->left = node1->right = NULL;
    return node1;
}

void insert(int data, struct node *root){
    struct node *prev;
    while(root != NULL){
        prev = root;
        if(data == root->data){
            printf("given data is already inserted in the table");
            return;
        }
        else if(data <root->data){
            root = root->left;
        }
        else{ // (data>root->data)
            root = root->right;
        }
    }
    root = newNode(data);
    if(root->data < prev->data){
        prev->left = root;
    }
    else { // root->data > prev->data
        prev->right = root;
    }
}

void inorder(struct node *root){
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
}
int main(){
    struct node *root = newNode(23);
    return 0;

}
