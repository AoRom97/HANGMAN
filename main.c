#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <string.h>

int main (int argc, char * argv[])
{
  MY_STRING hMy_string1 = NULL;
  MY_STRING hMy_string2 = NULL;
  
  hMy_string1 = my_string_init_default();
  hMy_string2 = my_string_init_default();

  my_string_push_back(hMy_string1,'B');
  my_string_push_back(hMy_string1,'l');
  my_string_push_back(hMy_string1,'u');
  my_string_push_back(hMy_string1,'e');

  my_string_push_back(hMy_string2,'C');
  my_string_push_back(hMy_string2,'a');
  my_string_push_back(hMy_string2,'t');

  my_string_concat(hMy_string1, hMy_string2);

  // printf("%s\n", hMy_string1->data);
  
 

  
  my_string_destroy(&hMy_string1);
  my_string_destroy(&hMy_string2);
  return 0;
}
