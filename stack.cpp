#include<iostream>
using namespace std;


struct node{
    int data;
    struct node *next;
};

int isEmpty(struct node *top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node *top){
    return 0;
}

struct node *push(struct node *top,  int val){
    if(isFull(top)){
        cout << "stack overflow" << endl;
    }
    else{
        struct node *newnode = new struct node;
        newnode->data = val;
        newnode->next = top;
        top = newnode;
        return top;
    }
    return NULL;
}

int pop(struct node **top){
    if(isEmpty((*top))){
        cout << "stack underflow" << endl;
    }
    else{
        struct node *ptr = (*top);
        (*top) = (*top)->next;
        int data = ptr->data;
        free(ptr);
        return data;
    }
}


void linked_list_traversal(struct node *f){

    cout << "elements of the linked list are : " << endl;
    while(f != NULL){
        cout << f->data << ", ";
        f = f->next;
    }
}




int main(){

    struct node *top = NULL;
    top = push(top, 75);
    top = push(top, 7);
    top = push(top, 5);
    top = push(top, 79);
    cout << pop(&top);
    top = push(top, 72);
    top = push(top, 21);
    cout << pop(&top);
    top = push(top, 100);


    linked_list_traversal(top);

    return 0;
}