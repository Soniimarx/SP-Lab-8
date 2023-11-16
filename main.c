
#include <stdio.h>
#include <stdlib.h>



typedef struct node {
  int val;
  struct node *next;
} node_t;

void create_linked_list (node_t **head, int values, int n){
  //Create a new node for the first element in the list
  node_t *new_node = malloc(sizeof(node_t));
  new_node->val = values[0];
  new_node->next = NULL;
  
  //Set the head of the list to the new node
  *head = new_node;

  for(int i = 1; i<n; i++){
    node_t *next_node = malloc(sizeof(node_t));
    next_node->val = values[i];
    next_node->next = NULL;

    //Append the new node to the end of the list.
    (*head)->next = next_node;
    *head = next_node;
  }
}

void print_linked_list(node_t *head){
  node_t *current = head;
  while (current != NULL){
    printf("%d\n", current->val);
    current = current->next;
  }
}

node_t *pop_first(node_t **head){
  if (*head == NULL){
    return NULL;
  }
  node_t *temp = *head;
  *head = (*head)->next;
  temp->next = NULL;

  return temp;
}

void push(node_t **head, int value){
  node_t *new_node = malloc(sizeof(node_t));
  new_node->val = value;
  new_node->next = *head;
  *head = new_node;
}
