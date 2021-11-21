#include "linkedlist.h"


void init_list(struct Node **first, struct Node **last)
{
   *first = malloc(sizeof(struct Node));
   *last = malloc(sizeof(struct Node));
   (*first)->next = *last;
}

void add_to_list_end(struct Data data, struct Node *first, struct Node *last)
{
   struct Node *curr = first;
   while (curr->next != last)
   {
      curr = curr->next;
   }
   curr->next = malloc(sizeof(struct Node));
   curr->next->data = data;
   curr->next->next = last;
   /*last->data = data;
   last->next = malloc(sizeof(struct Data));
   last = last->next;*/
}

void add_to_list_at_pos(struct Data data, struct Node *first, struct Node *last, int pos)
{
   struct Node *curr = first;

   for (int i = 0; i < pos; i++)
   {
      curr = curr->next;
      if (curr == last)
         return;
   }
   struct Node *tmp = curr->next;
   curr->next = malloc(sizeof(struct Node));
   curr->next->data = data;
   curr->next->next = tmp;
}

void remove_from_list_at_pos(struct Node *first, struct Node *last, int pos)
{
   struct Node *curr = first;
   for (int i = 0; i < pos; i++)
   {
      curr = curr->next;
      if (curr == last)
         return;
   }
   struct Node *it = curr->next;
   curr->next = it->next;
   free(it);
}

void wipe_list(struct Node *first, struct Node *last)
{
   struct Node *curr = first->next;
   while (curr->next != last)
   {
      struct Node *tmp = curr;
      curr = curr->next;
      free(tmp);
   }
   first->next = last;
}

void print_list(struct Node *first, struct Node *last)
{
   struct Node *curr = first;
   while (curr->next != last)
   {

      curr = curr->next;
      printf("%s : %s : %i : %s\n", curr->data.name, curr->data.lastname, curr->data.phone, curr->data.email);
   }
}

struct Node *find_by_name(char *name, struct Node *first, struct Node *last)
{
   struct Node *curr = first;
   while (curr->next != last)
   {
      curr = curr->next;
      if(strcmp(curr->data.name, name) == 0) return curr;
   }
   return NULL;
}

struct Node *find_by_lastname(char *lastname, struct Node *first, struct Node *last)
{
   struct Node *curr = first;
   while (curr->next != last)
   {
      curr = curr->next;
      if(strcmp(curr->data.lastname, lastname) == 0) return curr;
   }
   return NULL;
}

struct Node *find_by_email(char *email, struct Node *first, struct Node *last)
{
   struct Node *curr = first;
   while (curr->next != last)
   {
      curr = curr->next;
      if(strcmp(curr->data.email, email) == 0) return curr;
   }
   return NULL;
}

struct Node *find_by_phonenum(int phonenum, struct Node *first, struct Node *last)
{
   struct Node *curr = first;
   while (curr->next != last)
   {
      curr = curr->next;
      if(strcmp(curr->data.phone, phonenum) == 0) return curr;
   }
   return NULL;
}

struct Node *get_at_pos(struct Node *first, struct Node *last, int pos) {
   struct Node *curr = first;
   for(int i = 0; i < pos; i++) {
      curr = curr->next;
   }
   return curr->next;
}
