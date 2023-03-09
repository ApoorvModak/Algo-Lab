#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
    int value;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode *createNode(int value){
    treeNode *result = malloc(sizeof(treeNode));
    if (result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    
}