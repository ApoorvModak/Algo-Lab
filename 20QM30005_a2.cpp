#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int key;
    int height;
    struct node *left;
    struct node *right;
};


struct node *createNode(int key){
    struct node *node1 = new struct node;
    node1->key = key;
    node1->left = NULL;
    node1->right = NULL;
    node1->height = 0;
    return node1;
}


struct node *insert(int x, struct node *root){
    struct node *ptr = root;
    struct node *prev = NULL;
    
    while(ptr != NULL){
        prev = ptr;
        if(ptr->key == x){
            cout << "given element present in the tree" << endl;
            return root;
        }
        else if(x < ptr->key){
            ptr = ptr->left;
        }
        else{ // (x > ptr->key)
            ptr = ptr->right;
        }
    }
    //position of the element found in the tree
    //loop exited so ptr pointing to NULL - positon of new node
    // prev pointing to a node that connects with new node
    ptr = createNode(x);
    if (prev == NULL){
        root = ptr;
    }
    else {
        if(ptr->key < prev->key){
            prev->left = ptr;
        }
        else{ // (ptr-> < prev->key)
            prev->right = ptr;
        }

    }
    

    return root;
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


void print_tree(struct node *root){
    cout << "   Preorder : ";
    preorder(root);
    cout << "\n";
    cout << "   Inorder : ";
    inorder(root);
    cout << "\n";
}


int height(struct node *root){
    //base condition1 - empty tree - height is -1
    if(root == NULL){
        return -1;
    }
    //base condtion 2 - leaf node
    else if(root->left == NULL && root->right == NULL){
        //cout << "leaf detected";
        root->height = 0;
        return 0;
    }
    else{ // the node is in middle or root node
        int left_child_height = height(root->left);
        int right_child_height = height(root->right);
        root->height = max(left_child_height,right_child_height) +1;
        return root->height;
        //cout <<"left child - " << left_child_height;
    }

}


void hrange(int k, int l, struct node *root){
    if(root != NULL){
        // in-order traversal of BST checking if height of that node is withint the range
        // visiting each node only once, so satisfies O(n)
        hrange(k,l,root->left);
        // for current root,
        if(root->height >=k && root->height <= l){
            cout << "(" << root->key << ":" << root->height <<"), ";
        }
        hrange(k,l,root->right);
    }
}


int main(){
    // innitialize T to empty BST 
    struct node *T = NULL;

    int n, data;

    // no. of keys to be inserted
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

    // printing tree :
    cout << "Traversal of created BST " << endl;
    print_tree(T);

    // printing max height
    int max_height = height(T);
    cout << "Height of all nodes computed " << endl;
    cout << "   maximum height : " << max_height << endl;

    // printing height range functon output, assuming k and l.
    int k=1, l=3; // randomly assumed
    cout << "key : height of all nodes in the range [" << k << "," << l << "]" << endl;
    hrange(k,l,T);
    //cout << T->left->height;

    return 0;
}