#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrb.h"
#include "fields.h"
#include "jsonparser.h"

int main()
{
  JRB tree;
  JRB tmp;

  tree = parse_json_file();

  printf("\n------------------- Agac --------------------\n\n");
  jrb_traverse(tmp, tree) {
    printf("%-40s %2s\n", tmp->key.s, tmp->val.s);
  }
  printf("\n---------------------------------------------\n\n");

  jrb_free_tree(tree);
  return 0;
}