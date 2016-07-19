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

/*void delete_given_key(linkedl **head, int key){
  linkedl *temp = *head, *prev;
  temp = *head;
  head_next = *head->next;
  if (*head->data == key){
    *head = *head->next;
  }
  else if (*head->next->data == key){
    free(head_next);
    *head->next = NULL;
  }
  else {
    while (*head != NULL && *head->next->data != key){
      if (*head_next->next->data == key){
        head_next->next = head_next->next->next;
        free (head_next->next);
      }
      *head = *head->next;
    }
  }
}*/

int linked_list_length_iterative (linkedl *head){
  int count = 0;
  if (head == NULL){
    printf("Linked List is empty");
  }
  else {
    while (head != NULL){
      count++;
      head = head->next;
    }
  }
  printf("%d\n", count);
  return count;
}

int linked_list_length_recursive (linkedl *head){
  if (head == NULL){
    return 0;
  }
  else {
    return 1 + linked_list_length_recursive(head->next);
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
  //insert_start(&node1, 5);
  insert_end(node1, 6);
  insert_middle(node2, 7);
  printlinked(node1);
  linked_list_length_iterative(node1);
  int count = 0;
  count = linked_list_length_recursive(node1);
  printf("%d\n", count);
  return 0;
}
