#include "encoder.h"
#include "trim.h"

/*
@description : Parametre olarak kelime-sifre eslerini tasiyan agaci alir ve bu agaci
kullanarak giris_metin içerisindeki kelimelerin sifreli hallerini cikis_metin 
dosyasi olarak verir.
@author: Burak YAZAN - G171210395
@param: p_tree - kelime-sifre eslerini tasiyan agac
*/
void encode_file(JRB    p_tree,
                 char  *p_inputFileName,
                 char  *p_outputFileName){
  IS  is;
  int i;
  int fd; 
  int sz;

  fd = open(p_outputFileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) { 
    perror(p_outputFileName); 
    exit(1); 
  }

  is = new_inputstruct(p_inputFileName);
  if (is == NULL) {
    exit(1);
  }

  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
      JRB node = jrb_find_str(p_tree,is->fields[i]);

      if(node == NULL){
        char *val = is->fields[i];
        val = trim(val);
        sz = write(fd, val, strlen(val));
        sz = write(fd, " ", 1);
      } else {
        char *val = node->val.s;
        val = trim(val);
        sz = write(fd, val, strlen(val));
        sz = write(fd, " ", 1);
      }
    }
  }

  close(fd);
  jettison_inputstruct(is);
  return;
}