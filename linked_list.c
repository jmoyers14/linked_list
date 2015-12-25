#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node_t* new_node(int value) {
   node_t *new_node;

   new_node = malloc (sizeof(node_t));
   new_node->value = value;
   new_node->next  = NULL;

   return new_node;
}

void add_node(node_t *head, node_t *node) {
   node_t *curr = head;

   while (curr->next) {
      curr = curr->next;
   }

   curr->next = node;
}

int index_of(node_t *head, node_t *node) {
   int index    = 0;
   node_t *curr = NULL; 
   curr = head;

   while(curr) {
      if (curr == node) {
         return index; 
      }
      curr = curr->next;
      index++;
   }

   return -1;
}

node_t *remove_node(node_t* head, node_t* node) {
   node_t *curr = NULL, *prev = NULL;
   prev = curr = head;

   if (node == head) {
      curr = head->next;
      delete_node(head);
      return curr;
   }

   while (curr) {
      if (curr == node) {
         prev->next = curr->next; 
         delete_node(curr);
      }
      prev = curr;
      curr = curr->next;
   }

   return head;
}

void delete_node(node_t *node) {
   if (node) {
      free(node);
   }
}

void delete_list(node_t *head) {
   node_t *curr=NULL;
   curr = head;

   while(curr) {
      head = curr;
      curr = head->next;
      delete_node(head);
   }
}

void print_list(node_t *head) {
   node_t *curr = NULL;
   curr = head;
   while (curr) {
      printf("%d", curr->value);
      curr = curr->next; 
   }
   printf("\n");
}

int list_length(node_t *head) {
   int count = 0;
   while(head) {
      count++;
      head = head->next;
   }
   return count;
}

