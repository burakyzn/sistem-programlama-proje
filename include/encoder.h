#ifndef _ENCODER_H_ 
#define _ENCODER_H_ 

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libfdr/jrb.h"
#include "../libfdr/fields.h"

/*
@description : Parametre olarak kelime-sifre eslerini tasiyan agaci alir ve bu agaci
kullanarak giris_metin içerisindeki kelimelerin sifreli hallerini cikis_metin 
dosyasi olarak verir.
@author: Burak YAZAN - G171210395
@param: p_tree - kelime-sifre eslerini tasiyan agac
*/
extern void encode_file(JRB     p_tree,
                        char   *p_inputFileName,
                        char   *p_outputFileName);

#endif