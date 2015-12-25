#include <stdio.h>
#include "linked_list.h"

void test_new_node();
void test_add_node();
void test_print_list();
void test_index_of();
void test_list_length();
void test_remove_node();


int main(int argc, char** argv) {
   test_new_node();
   test_print_list();
   test_add_node();
   test_index_of();
   test_list_length();
   test_remove_node();
}

node_t *get_list() {
   node_t *head=NULL;
   head = new_node(0);

   for (int i=1; i<10; i++) {
      add_node(head, new_node(i));
   }

   return head;
}

void test_new_node() {
   node_t *node;

   node = new_node(7);

   if (node->value == 7) {
      printf("test_new_node: new node success\n");
   } else {
      printf("test_new_node: new node failed\n");
   }
}

void test_print_list() {
   node_t *head=NULL, *mid=NULL, *tail=NULL;

   head = new_node(1);
   mid  = new_node(2);
   tail = new_node(3);

   head->next = mid;
   mid->next = tail;
   tail->next = NULL;

   print_list(head);
}

void test_add_node() {
   int test_success=0;
   node_t *head=NULL, *curr=NULL;
   head = get_list();

   curr = head;
   for (int i=0; i<10; i++) {
      if(curr->value != i) {
         test_success = 1; 
      }
   }

   if (test_success) {
      printf("test_add_node: success\n");
   } else {
      printf("test_add_node: failure\n");
   }
}

void test_index_of() {
   node_t *nodes[20];
   int test_success = 1;

   for (int i=0; i<20; i++) {
      nodes[i] = new_node(i);      
      if (i > 0)
         add_node(nodes[0], nodes[i]);
   }

   for (int i=0; i<20; i++) {
      if (index_of(nodes[0], nodes[i]) != i) {
         test_success = 0;
         break;
      }
   }

   if (test_success) {
      printf("test_index_of: success\n");
   } else {
      printf("test_index_of: failure\n");
   }
}

void test_list_length() {
   node_t *head = NULL;
   head = get_list();

   if (list_length(head) == 10) 
      printf("test_list_lenght: success\n");
   else
      printf("test_list_length: failure\n");
}

void test_remove_node() {
   node_t *nodes[20];
   int init_len = 0, final_len = 0;

   for (int i=0; i<20; i++) {
      nodes[i] = new_node(i);      
      if (i > 0)
         add_node(nodes[0], nodes[i]);
   }

   init_len = list_length(nodes[0]);
   final_len = list_length(remove_node(nodes[0], nodes[10]));

   if (init_len == 20 && final_len == 19) {
      printf("test_remove_node: success\n");
   } else {
      printf("test_remove_node: failure\n");
   }

}




