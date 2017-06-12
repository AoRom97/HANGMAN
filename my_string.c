#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <string.h>
#include <ctype.h>


struct my_string
{
  int size;
  int capacity;
  char* data;

};
typedef struct my_string My_string;


MY_STRING my_string_init_default(void)
{
  My_string* pMy_string = (My_string*) malloc(sizeof(My_string));
  if (pMy_string != NULL)
    {
      pMy_string->size = 0;
      pMy_string->capacity = 7;
      pMy_string->data = (char*)malloc(sizeof(char) *pMy_string->capacity);
    	if (pMy_string->data  == NULL)
	{
		printf("Data could not be allocated");		
		free(pMy_string);
		pMy_string = NULL;
    	}
    }
  return pMy_string;
}

void my_string_destroy(MY_STRING* phmy_string)
{
  My_string* pMy_string = (My_string*) *phmy_string;
  free(pMy_string->data);
  free(pMy_string); 
  phmy_string = NULL;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  My_string* pMy_string = (My_string*) malloc(sizeof(My_string));
  if (pMy_string != NULL)
    {
      int x;
      x = strlen(c_string);
      pMy_string->size = x;
      pMy_string->capacity = x + 1;
	pMy_string->data = (char*)malloc(sizeof(char)* pMy_string->capacity);
      if( pMy_string->data == NULL);
      {
	free(pMy_string);
	pMy_string = NULL;
      }
    }
  return (MY_STRING) pMy_string;
}


int my_string_get_size(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;
  return pMy_string->size;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;
  return pMy_string->capacity;
}

int my_string_compare(MY_STRING hleft_string, MY_STRING hRight_string)
{
  int x = strcmp(hleft_string, hRight_string);
  if (x == 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}


//



Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string* pMy_string = (My_string*) hMy_string;	//cast to the known type
	while (!(isspace(fp))) //ignore leading whitespaces & stopping condition: EOF or read one non-whitespace
	{
		fscanf(fp,"%s", pMy_string->data); //read all characters excluding white spaces
		pMy_string->size = strlen(pMy_string->data);			
		if (pMy_string->size >= pMy_string->capacity)
		{
			My_string* temp = pMy_string;
			temp->data = (char*)malloc(sizeof(char)*pMy_string->capacity * 2);
			if (temp->data == NULL)
			{
				printf("Data could not be allocated.\n");
				free(temp);
				exit(1);
			}
			pMy_string = temp;
		}
		pMy_string->capacity *= 2;
		
	return SUCCESS;
	}	
	
	
  return FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_string* pMy_string = (My_string*) hMy_string; // cast to the known type
	for (int i = 0 ; i != pMy_string->size - 1; i++)
	{
		printf("%s", pMy_string->data); //outputs the characters contained	
	}		

  return FAILURE;
}



//

Status my_string_push_back(MY_STRING hMy_string, char item)
{
 My_string* pMy_string = (My_string*) hMy_string;
 if (pMy_string->size >= pMy_string->capacity)
	{
	  char* temp = (char*)malloc(sizeof(char) *pMy_string->capacity * 2);
	  if (temp == NULL)
		{
		  printf("Data could not be allocated\n");
		  return FAILURE;
		}
	  int i;
	  for (i = 0; i <= pMy_string->size; i++)
		{
		  temp[i] = pMy_string->data[i];
		}
	 pMy_string->data = temp;
	 pMy_string->capacity *= 2;
	}
  
 pMy_string->data[pMy_string->size] = item;
 pMy_string->size += 1;
 return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
 My_string* pMy_string = (My_string*) hMy_string;
 if (my_string_empty(pMy_string))
 {
  return FAILURE;
 }
 pMy_string->size--;
 return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string* pMy_string = (My_string*) hMy_string;
  return &(pMy_string->data[index]);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
 My_string* phResult = (My_string*) hResult;
 My_string* phAppend = (My_string*) hAppend;
 
  int i;
  Status status;
 for (i = 0; i <= strlen(hAppend); i++)
  { 
    status = my_string_push_back(phResult, phAppend->data[i]);
  }
  phResult->data[phResult->size] = '\0';
  

 return status;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
 My_string* pMy_string = (My_string*) hMy_string;
 return (Boolean) (pMy_string->size == 0);
}











