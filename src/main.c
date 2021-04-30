#include "jrb.h"
#include "jsonparser.h"
#include "encoder.h"
#include "decoder.h"

int main()
{
  JRB tree;
  JRB tmp;

  // tree = parse_json_file(1); // encode icin 1 yollanmali
  // encode_file(tree);

  tree = parse_json_file(0);
  decode_file(tree);

  jrb_free_tree(tree);
  return 0;
}