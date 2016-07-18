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

void insert_start(linkedl **head, int temp){
  linkedl *new_node = (linkedl*)malloc(sizeof(linkedl));
  new_node->data = temp;
  new_node->next = *head;
  *head = new_node;
}

void insert_end(linkedl *head, int temp){
  linkedl *new_node = NULL;
  new_node = (linkedl*)malloc(sizeof(linkedl));
  if (head == NULL){
    head = new_node;
    new_node->data = temp;
    new_node->next = NULL;
  }
  else {
    while(head->next!=NULL){
      head = head->next;
    }
    head->next = new_node;
    new_node->data = temp;
    new_node->next = NULL;
  }
}

void insert_middle(linkedl *node_pre, int temp){
  linkedl *new_node = NULL;
  new_node = (linkedl*)malloc(sizeof(linkedl));
  new_node->data = temp;
  new_node->next = node_pre->next;
  node_pre->next = new_node;
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
  //insert_start(&node1, 5);
  insert_end(node1, 6);
  insert_middle(node2, 7);
  printlinked(node1);
  return 0;
}
