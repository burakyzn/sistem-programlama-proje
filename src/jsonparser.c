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
  LV    isLast;

  isLast = (LV)malloc(sizeof(struct lastIndexStruct));
  isLast->lastValue = 0;

  input_struct = new_inputstruct(kilit);
  if(input_struct == NULL){
    printf("Kilit dosyasi yok.\nCikis yapiliyor.\n");
    exit(1);
  }
  
  tree = make_jrb();

  isLast->lastValue = 0;
  while (get_line(input_struct) >= 0) {
    if(input_struct->fields[0][0] == '{')
        continue;
      else if(input_struct->fields[0][0] == '}')
        break;

    if(input_struct->NF != 2)
    {
      printf("Hatalı kilit dosyası.\nCikis yapiliyor.\n");
      exit(1);
    }

    if(p_parse_option == 1){
        key = find_key_or_val(input_struct->fields[0], 0, isLast);
        val = find_key_or_val(input_struct->fields[1], 1, isLast);
      } else {
        key = find_key_or_val(input_struct->fields[1], 0, isLast);
        val = find_key_or_val(input_struct->fields[0], 1, isLast);
      }

      jrb_insert_str(tree, key, new_jval_s(val));
  }
  
  free(isLast);
  jettison_inputstruct(input_struct);
  return tree;
}

/*
@description : Parametre olarak gelen ifadeyi json tipinden temizleyip geriye döndürecektir.
@author: BERKAY ŞAHİN - G191210302
@param: p_word - suslu parantez iceren kelime bolumudur
@return: return_word - key/val bilgisini dondurur
*/
char *find_key_or_val(char *p_word, int key_or_value, LV isLast){
  char *return_word;
  int   i;
  int   lastCharIndex = strlen(p_word) - 1;
  int   error = 0;
  int   breakIndex = 0;

  if(key_or_value == 1 && p_word[lastCharIndex] == '\"')
    isLast->lastValue++;

  if(isLast->lastValue > 1)
    error = 1;

  if(p_word[0] == '\"'){
    if(key_or_value == 0){
      if(p_word[lastCharIndex - 1] != '\"' || p_word[lastCharIndex] != ':')
        error = 1;
      else
        breakIndex = lastCharIndex - 1;
    }else{
      if(isLast->lastValue == 0){
        if(p_word[lastCharIndex - 1] != '\"' || p_word[lastCharIndex] != ',')
          error = 1;
        else
          breakIndex = lastCharIndex - 1;
      }else{
        breakIndex = lastCharIndex;
      }
    }
  }else{
    error = 1;
  }

  if(error == 1){
    printf("Hatalı kilit dosyası.\nCikis yapiliyor.\n");
    exit(1);
  }

  for(i = 1; i < breakIndex; i++){
    p_word[i - 1] = p_word[i];
    if(p_word[i + 1] == '\"' && i == breakIndex - 1){
      p_word[i] = '\0';
      break;
    }
  }

  return_word = (char *) malloc(sizeof(char)*(strlen(p_word) + 1));
  strcpy(return_word, p_word);

  printf("%s\n", return_word);

  return return_word;
}
