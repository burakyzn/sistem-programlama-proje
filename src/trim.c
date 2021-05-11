#include "trim.h"
#include <string.h>
#include <ctype.h>

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