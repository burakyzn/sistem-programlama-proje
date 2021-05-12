#include "./libfdr/jrb.h"
#include "jsonparser.h"
#include "encoder.h"
#include "decoder.h"

int main(int   argc,  
         char *argv[])
{
  JRB tree;
  JRB tmp;

  if (argc == 4){
    if (strcmp(argv[1], "-e") == 0){
      tree = parse_json_file(1); 
      encode_file(tree, argv[2], argv[3]);
      jrb_free_tree(tree);
    } else if (strcmp(argv[1], "-d") == 0) {
      tree = parse_json_file(0);
      decode_file(tree, argv[2], argv[3]);
      jrb_free_tree(tree);
    } else {
       printf("Dogru komut girilmedi.\n");    
    }
  } else {
    printf("Yeterli arguman girilmedi.\n");
  }
  return 0;
}
