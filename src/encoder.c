#include "encoder.h"

char *ltrim(char *p_word)
{
  while(isspace(*p_word)) 
    p_word++;
    
  return p_word;
}

char *rtrim(char *p_word)
{
  char* back = p_word + strlen(p_word);
  while(isspace(*--back));
  *(back+1) = '\0';
  return p_word;
}

char *trim(char *p_word)
{
  return rtrim(ltrim(p_word)); 
}

/*
@description : Parametre olarak kelime-sifre eslerini tasiyan agaci alir ve bu agaci
kullanarak giris_metin içerisindeki kelimelerin sifreli hallerini cikis_metin 
dosyasi olarak verir.
@author: Burak YAZAN - G171210395
@param: p_tree - kelime-sifre eslerini tasiyan agac
*/
void encode_file(JRB p_tree){
  IS  is;
  int i;
  int fd; 
  int sz;

  is = new_inputstruct("giris_metin.txt");
  if (is == NULL) {
    perror("giris_metin.txt");
    exit(1);
  }

  fd = open("cikis_metin.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) { 
    perror("cikis_metin.txt"); 
    exit(1); 
  }

  while(get_line(is) >= 0) { 
    for (i = 0; i < is->NF; i++) { 
      char *val = jrb_find_str(p_tree,is->fields[i])->val.s;
      val = trim(val);
      strcat(val, " ");
      sz = write(fd, val, strlen(val));
    }
  }

  close(fd);
  jettison_inputstruct(is);
  return;
}