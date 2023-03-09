#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int key;
    int balance_factor;
    struct node *left;
    struct node *right;
};

struct node *createNode(int key){
    struct node *node1 = new struct node;                                                                               
    node1->key = key;
    node1->left = NULL;
    node1->right = NULL;
    node1->balance_factor =0;
    return node1;
}


int get_height(struct node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return max(get_height(root->left), get_height(root->right)) +1 ;
    }
}

struct node *r_rot(struct node *root){

    struct node *temp;
    struct node *new_node;

    temp = root->left->right;
    new_node = root->left;
    new_node->right = root;
    root->left = temp;

    return new_node;

}

struct node *l_rot(struct node *root){

    struct node *temp;
    struct node *new_node;
    
    temp = root->right->left;
    new_node = root->right;
    new_node->left = root;
    root->right = temp;

    return new_node;
}

int get_balance_factor(struct node *root){

    return (get_height(root->left) - get_height(root->right));

}


struct node *insert(int key, struct node *root){
    if(root == NULL){
        return (createNode(key));
    }
    
    if(key < root->key){
        root->left = insert(key, root->left);
    }
    else if(key > root->key){
        root->right = insert(key, root->right);
    }

    root->balance_factor = get_balance_factor(root);

    // left left
    if(root->balance_factor > 1 and key < root->left->key){
        root = r_rot(root);
    }

    // right right
    if(root->balance_factor < -1 and key > root->left->key){
        root = l_rot(root);
    }

    // left right
    if(root->balance_factor > 1 and key > root->left->key){
        root->left = l_rot(root->left);
        root = r_rot(root);
    }

    // right left
    if(root->balance_factor < -1 and key < root->left->key){
        root->right = r_rot(root->right);
        root = l_rot(root);
    }

    return root;
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

    preorder(T);
    // cout << endl;
    // T = l_rot(r_rot(T));
    // cout << endl;
    // preorder(T);
    cout << T->left->key;
    cout << T->right->key;
    
}


