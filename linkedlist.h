#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
   char *name;
   char *lastname;
   int phone;
   char *email;
};

struct Node
{
   struct Data data;
   struct Node *next;
};

struct Node *find_by_phonenum(int phonenum, struct Node *first, struct Node *last);
struct Node *find_by_name(char *name, struct Node *first, struct Node *last);
struct Node *find_by_email(char *email, struct Node *first, struct Node *last);
struct Node *find_by_lastname(char *lastname, struct Node *first, struct Node *last);
struct Node *get_at_pos(struct Node *first, struct Node *last, int );

void init_list(struct Node **first, struct Node **last);

void add_to_list_end(struct Data data, struct Node *first, struct Node *last);
void add_to_list_at_pos(struct Data data, struct Node *first, struct Node *last, int pos);

void remove_from_list_at_pos(struct Node *first, struct Node *last, int pos);
void wipe_list(struct Node *first, struct Node *last);

void print_list(struct Node *first, struct Node *last);
#endif
