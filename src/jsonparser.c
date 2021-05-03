#include "jsonparser.h"

/*
@description : Standart inputtan gelen dosya ismi ile kilit dosyasını açıp içerisindeki verileri 'red black tree' ağacına yerleştirecektir. 
@author: BERKAY ŞAHİN - G191210302
@return: tree - jsondan cikarilmis key-val ciftlerinin bulundugu agaci geri dondurur.
*/
JRB parse_json_file(int p_parse_option){
  JRB   tree;
  IS    input_struct;
  int   nsize;
  char *key;
  char *val;
  char *kilit = ".kilit";

  input_struct = new_inputstruct(kilit);
  if(input_struct == NULL){
    printf("Kilit dosyasi yok.\nCikis yapiliyor.\n");
    exit(1);
  }
  
  tree = make_jrb();
  
  while (get_line(input_struct) >= 0) {
    if(input_struct->fields[0][0] == '{')
        continue;
      else if(input_struct->fields[0][0] == '}')
        break;

    if(p_parse_option == 1){
        key = find_key_or_val(input_struct->fields[0]);
        val = find_key_or_val(input_struct->fields[1]);
      } else {
        key = find_key_or_val(input_struct->fields[1]);
        val = find_key_or_val(input_struct->fields[0]);
      }

      jrb_insert_str(tree, key, new_jval_s(val));
  }
  
  jettison_inputstruct(input_struct);
  return tree;
}

/*
@description : Parametre olarak gelen ifadeyi json tipinden temizleyip geriye döndürecektir.
@author: BERKAY ŞAHİN - G191210302
@param: p_word - suslu parantez iceren kelime bolumudur
@return: return_word - key/val bilgisini dondurur
*/
char *find_key_or_val(char *p_word){
  char *return_word;
  int   i;

  for(i = 1; p_word[i] != '\"'; i++){
    p_word[i - 1] = p_word[i];
    if(p_word[i + 1] == '\"'){
      p_word[i] = '\0';
      break;  
    }
  }

  return_word = (char *) malloc(sizeof(char)*(strlen(p_word) + 1));
  strcpy(return_word, p_word);

  return return_word;
}
