#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int data;
  struct linkedl *next;
} linkedl;

struct linkedl *newnode(int value){
  linkedl *node = (linkedl*)malloc(sizeof(linkedl));
  node->data = value;
  node->next = NULL;
}

int printlinked(linkedl *root){
  while(root!=NULL){
    printf("%d\n", root->data);
    root = root->next;
  }
}



int main(){
  linkedl *node1 = NULL;
  node1 = (linkedl*)malloc(sizeof(linkedl));
  node1->data = 1;
  linkedl *node2 = NULL;
  node2 = (linkedl*)malloc(sizeof(linkedl));
  node2->data = 2;
  linkedl *node3 = NULL;
  node3 = (linkedl*)malloc(sizeof(linkedl));
  node3->data = 3;
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;
  printlinked(node1);
  return 0;
}
