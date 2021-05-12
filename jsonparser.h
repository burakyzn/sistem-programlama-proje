#ifndef _JSONPARSER_H_ 
#define _JSONPARSER_H_ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libfdr/jrb.h"
#include "./libfdr/fields.h"

typedef struct lastIndexStruct {
  int lastValue;
} *LV;

extern JRB   parse_json_file(int   p_parse_option);
extern char *find_key_or_val(char *p_word,
                             int key_or_value,
                             LV isLast);

#endif
