#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "input.h"


int main()
{
  struct Node *f, *l;
  init_list(&f, &l);
  input_data(f, l);
  print_list(f, l);
  printf("\n\n\n\n");
  printf("%s", get_at_pos(f, l, 0)->data.name);
  return 0;
}
