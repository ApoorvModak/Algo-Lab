#include<iostream>
#include<math.h>
using namespace std;

struct node{
    int a;
    int b;
    int c;
};

void swap(struct node * A, struct node * B){

    struct node * temp = new struct node;
    temp->a = A->a;
    temp->b = A->b;
    temp->c = A->c;

    A->a = B->a;
    A->b = B->b;
    A->c = B->c;

    B->a = temp->a;
    B->b = temp->b;
    B->c = temp->c;

    free(temp);
}

// minheap[0] intentionally left blank, so that index of an element and size i.e no. of elements in heap is equal
// also since minheap[0] is blank, indexing starts at 1
// for ith element, parent is int(i/2), children are 2i and 2i+1

void insert(struct node * minheap[], int size, int a, int b){

    // cout << "inside the insert function  " << a << endl;

    // adding element to the end of array
    minheap[size+1]->a = a;
    minheap[size+1]->b = b;
    minheap[size+1]->c = pow(a,3) + pow(b, 3);
    size++;

    int i = size;
    // up percolation of element => order log(n)
    while(i > 1){
        if(minheap[i/2]->c > minheap[i]->c){
            swap(minheap[i/2], minheap[i]);
            i = i/2;
        }
        else{
            break;
        }
    }
}

struct node * remove_min(struct node * minheap[], int size){

    struct node *popped_tripple = new struct node;
    popped_tripple->a = minheap[1]->a;
    popped_tripple->b = minheap[1]->b;
    popped_tripple->c = minheap[1]->c;

    swap(minheap[1], minheap[size]);
    size--;

    // down percolatio of the leaf node added swapped with popped root
    int i = 1;
    while(2*i +1 <= size){
        if(minheap[2*i]->c < minheap[2*i +1]->c){
            if(minheap[2*i]->c < minheap[i]->c){
                swap(minheap[i], minheap[2*i]);
                i = 2*i;
            }
            else{
                break;
            }
        }
        else{
            if(minheap[2*i +1]->c < minheap[i]->c){
                swap(minheap[i], minheap[2*i +1]);
                i = 2*i +1;
            }
            else{
                break;
            }
        }
    }
    // loop breaks with either element placed in its correct position, or a position which has just one child
    // which might be smaller than our element
    // if one child is present but 2i+1 child is absent
    if(2*i <= size){
        if(minheap[2*i]->c < minheap[i]->c){
            swap(minheap[i], minheap[2*i]);
            i = 2*i;
        }
    }
    
    return popped_tripple;
}

void buildheap(struct node * minheap[], int n){

    for(int i =0; i < n; i++){
        minheap[i] = new struct node;
        minheap[i]->a = 0;
        minheap[i]->b = 0;
        minheap[i]->c = 0;
    }
}

void ramanujan(struct node * minheap[], int n){

    // struct node * minheap[n];
    // buildheap(minheap, n);
    
    int size = 0;

    // cout << "in the ramanujan function  " << minheap << "  " << n << "  " << size << endl;

    // populating tuples with (i,0,i^3)
    for(int i =0; i <= n; i++){
        insert(minheap, size++, i, 0);
    }

    // for(int i =0; i <= n; i++){
    //     struct node *ptr = remove_min(minheap, size--);
    //     cout << ptr->a << "," << ptr->b << "," << ptr->c << endl;
    // }

    // cout << "done inserting elements" << endl;
    // cout << size;

    // set of operations till heap gets empty
    int prev_ramanujan = 0;

    while(size > 0){
        struct node * popped_tripple = remove_min(minheap, size--);

        // checking for ramanujan number
        if(popped_tripple->c == minheap[1]->c){
            if(popped_tripple->b != minheap[1]->a){
                // it is a ramanujan number
                // displaying it
                if(prev_ramanujan != popped_tripple->c){
                    cout << minheap[1]->c << "  (" << minheap[1]->a << "," << minheap[1]->b << ")  (" << popped_tripple->a << "," << popped_tripple->b << ")" << endl;
                    prev_ramanujan = popped_tripple->c;
                }

            }
            // else it is just duplication where a and b are interchanged
        }

        if(popped_tripple->b < n){
            insert(minheap, size++, popped_tripple->a, (popped_tripple->b + 1));
        }
    }
}

int main(){
    int n ;
    cin >> n;

    struct node * minheap[n+5];
    buildheap(minheap, (n+5));

    // cout << minheap << endl;

    ramanujan(minheap, n);
    
    // int size =0;
    // insert(minheap, size++, 0, 2);
    // insert(minheap, size++, 1, 2);
    // insert(minheap, size++, 2, 2);
    // insert(minheap, size++, 1, 1);
    // insert(minheap, size++, 0, 3);
    // insert(minheap, size++, 0, 0);

    // remove_min(minheap, size--);
    // remove_min(minheap, size--);
    // remove_min(minheap, size--);

    

    // for(int i =1; i<=5; i++){
    //     cout << minheap[i]->a << "  " << minheap[i]->b << "  " << minheap[i]->c << endl;
    // }

}