#ifndef _DECODER_H_ 
#define _DECODER_H_ 

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libfdr/jrb.h"
#include "./libfdr/fields.h"

/*
@description : Parametre olarak sifre-kelime eslerini tasiyan agaci alir ve bu agaci
kullanarak giris_metin içerisindeki sifrelerin kelime karsiliklarini cikis_metin 
dosyasi olarak verir.
@author: Burak YAZAN - G171210395
@param: p_tree - sifre-kelime eslerini tasiyan agac
*/
extern void decode_file(JRB     p_tree,
                        char   *p_inputFileName,
                        char   *p_outputFileName);

#endif