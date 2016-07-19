#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct linkedl {
  int data;
  struct linkedl *next;
};

struct linkedl *newnode(int value){
  struct linkedl *node = (struct linkedl*)malloc(sizeof(struct linkedl));
  node->data = value;
  node->next = NULL;
}

int printlinked(struct linkedl *root){
  while(root!=NULL){
    printf("%d\n", root->data);
    root = root->next;
  }
}

void insert_start(struct linkedl **head, int temp){
  struct linkedl *new_node = (struct linkedl*)malloc(sizeof(struct linkedl));
  new_node->data = temp;
  new_node->next = *head;
  *head = new_node;
}

void insert_end(struct linkedl *head, int temp){
  struct linkedl *new_node = NULL;
  new_node = (struct linkedl*)malloc(sizeof(struct linkedl));
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

void insert_middle(struct linkedl *node_pre, int temp){
  struct linkedl *new_node = NULL;
  new_node = (struct linkedl*)malloc(sizeof(struct linkedl));
  new_node->data = temp;
  new_node->next = node_pre->next;
  node_pre->next = new_node;
}

/*void delete_given_key(struct linkedl **head, int key){
  struct linkedl *temp = *head, *prev;
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

int linked_list_length_iterative (struct linkedl *head){
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

int linked_list_length_recursive (struct linkedl *head){
  if (head == NULL){
    return 0;
  }
  else {
    return 1 + linked_list_length_recursive(head->next);
  }
}

bool search_element_iterative (struct linkedl *head, int element){
  while (head != NULL){
    if (head->data == element){
      return true;
    }
    head = head->next;
  }
  return false;
}

bool search_element_recursive (struct linkedl *head, int element){
  if (head == NULL){
    return false;
  }
  if (head->data == element) {
    return true;
  }
  return search_element_recursive (head->next, element);
}

struct linkedl *deletenode (struct linkedl **head, int key){
  //here reference is used so as to modify the pointer
  //similar to using newnode function pointer
}

void nth_node (struct linkedl *head, int nth){
  int count = 1;
  while (count != nth && head != NULL){
    head = head->next;
    count++;
  }
  printf("%d\n", head->data);
}

void print_middle_linked_list (struct linkedl *head){
  struct linkedl *double_node = head;
  struct linkedl *node = head;
  if (head != NULL && head->next != NULL){
    while (double_node != NULL && double_node->next != NULL){
      double_node = double_node->next->next;
      node = node->next;
    }
    printf("%d\n", node->data);
  }
}

int main(){
  struct linkedl *node1 = NULL;
  node1 = (struct linkedl*)malloc(sizeof(struct linkedl));
  node1->data = 1;
  struct linkedl *node2 = NULL;
  node2 = (struct linkedl*)malloc(sizeof(struct linkedl));
  node2->data = 2;
  struct linkedl *node3 = NULL;
  node3 = (struct linkedl*)malloc(sizeof(struct linkedl));
  node3->data = 3;
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;
  //insert_start(&node1, 5);
  insert_end(node1, 6);
  insert_middle(node2, 7);
  printlinked(node1);
  //linked_list_length_iterative(node1);
  //int count = 0;
  //count = linked_list_length_recursive(node1);
  //printf("%d\n", count);
  //bool value = 0;
  //bool value1 = 0;
  //value = search_element_iterative(node1, 2);
  //value1 = search_element_recursive(node1, 100);
  //printf("%d\n", value1);
  nth_node (node1, 5);
  print_middle_linked_list(node1);
  return 0;
}
