#include<iostream>
using namespace std;

struct adj_list_node{
    int vertex;
    int weight;
    struct node *next;
};
struct adj_list_node *createNode(int vertex, int weight){
    struct adj_list_node *newnode = new struct adj_list_node;
    newnode->next = NULL;
    newnode->vertex = vertex;
    newnode->weight = weight;
    return newnode;
}

struct graph{
    int num_vertices;
    struct adj_list_node *adjlist[];

};

struct graph *graph_constructor(struct graph *G){

    cin >> G->num_vertices;
    for(int i=0; i <= G->num_vertices-1; i++){
        // for each vertex, take in all the vertices that are connected to it and value of weights for the edges
        cout << "enter vertices connected to " << i << 'and respective weights of edges' << endl;
        int weight, connected_vertex;

    }


}

void enqueue(int vertex){

}

int dequeue(){
    return 0;
}

int isEmpty(){
    return 0;
}

void BFS(struct graph *G, int *visited, int start){
    for(int i = 0; i <= G->num_vertices-1; i++){
        visited[i]= 0;
    }

    // start is the node from which BFS starts
    enqueue(start);
    visited[start] = 1;
    while(!isEmpty()){
        int u = dequeue();
        struct adj_list_node *ptr = G->adjlist[u];
        while(ptr != NULL){
            int v = ptr->vertex;
            if(visited[v] != 1){
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
    
}   
int main(){

    struct graph *G;
    G = graph_constructor(G);
    
}