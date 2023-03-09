#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};



void enque(struct node **f, struct node **r, int val){
    struct node *new_node = new struct node;

    if(new_node == NULL){
        cout << "queue is full" << endl;
    }
    else{
        new_node->data = val;
        new_node->next = NULL;
        
        if((*f) == NULL){
            (*f) = new_node;
            (*r) = new_node;
        }
        else{
            (*r)->next = new_node;
            (*r) = new_node;
        }
    }
}

int dequeue(struct node **f){

    int val = -1;
    struct node *ptr;
    if((*f) == NULL){
        cout << "queue is empty" << endl;
    }
    else{
        ptr = (*f);
        val = ptr->data;
        (*f) = (*f)->next;
        free(ptr);
    }

    return val;
}

void linked_list_traversal(struct node *f){

    cout << "elements of the linked list are : " << endl;
    while(f != NULL){
        cout << f->data << ", ";
        f = f->next;
    }
}

int main(){

    struct node *f = NULL;
    struct node *r = NULL;

    // cout << dequeue() << endl;
    enque(&f, &r, 3);
    cout << f->data << r << endl;
    enque(&f, &r, 345);
    enque(&f, &r, 45);
    enque(&f, &r, 1);
    enque(&f, &r, 7);
    cout << "the dequed element is :" << dequeue(&f) << endl;
    enque(&f, &r, 9);
    enque(&f, &r, 6);
    cout << "the dequed element is :" << dequeue(&f) << endl;
    enque(&f, &r, 41);
    enque(&f, &r, 300);
    cout << "the dequed element is :" << dequeue(&f) << endl;
    enque(&f, &r, 55);
    linked_list_traversal(f);
}