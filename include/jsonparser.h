#ifndef _JSONPARSER_H_ 
#define _JSONPARSER_H_ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrb.h"
#include "fields.h"

extern JRB   parse_json_file(int   p_parse_option);
extern char *find_key_or_val(char *p_word);

#endif
