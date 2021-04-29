#include "jrb.h"
#include "jsonparser.h"
#include "encoder.h"

int main()
{
  JRB tree;
  JRB tmp;

  tree = parse_json_file();
  encode_file(tree);

  jrb_free_tree(tree);
  return 0;
}