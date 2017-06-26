Status test_init_default_returns_nonNULL(char* buffer, int length)
{
   MY_STRING hString = NULL;

   hString = my_string_init_default();

   if(hString == NULL)
   {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
                   "my_string_init_default returns NULL", length);
      return FAILURE;
   }
   else
   {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCCESS;
   }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;

   hString = my_string_init_default();

   if(my_string_get_size(hString) != 0)
   {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
                   "Did not receive 0 from get_size after init_default\n", length);
   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
                   , length);
   }

   my_string_destroy(&hString);
   return status;
}

Status test_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_get_capacity(hString) != 7) {
    status = FAILURE;
    printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
    strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n"
	    "Did not recieve 7 from get_capacity after init_default\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_handle_set_to_NULL_after_string_destroy(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  my_string_destroy(&hString);
  if (hString != NULL) {
    strncpy(buffer, "test_handle_set_to_NULL_after_string_destroy\n"
	    "handle is not NULL after string_destroy", length);
    status = FAILURE;
  }
  else {
    strncpy(buffer, "test_handle_set_to_NULL_after_string_destroy\n", length);
    status = SUCCESS;
  }
  return status;
}

Status test_init_c_string_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("abc");
  if(hString == NULL) {
    strncpy(buffer, "test_init_c_string_returns_nonNULL\n"
	    "my_string_init_c_string returns NULL", length);
    status = FAILURE;
  }
  else {
    strncpy(buffer, "test_init_c_string_returns_nonNULL\n", length);
    status = SUCCESS;
  }
  my_string_destroy(&hString);
  return status;
}

Status test_get_size_on_init_c_string_returns_string_length(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("abcdefghijklmnopqrstuvwxyz");
  if(my_string_get_size(hString) != 26) {
    status = FAILURE;
    printf("Expected a size of 26 but got %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_get_size_on_init_c_string_returns_string_length"
	    "Did not recieve string length from get_size after init_c_string\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_get_size_on_init_c_string_returns_string_length\n",
	    length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_get_capacity_on_init_c_string_returns_string_length_plus_one(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("abcdefghijklmnopqrstuvwxyz");
  if(my_string_get_capacity(hString) != 27) {
    status = FAILURE;
    printf("Expected a capacity of 27 but got %d\n", my_string_get_capacity(hString));
    strncpy(buffer, "test_get_capacity_on_init_c_string_returns_string_length_plus_one"
	    "Did not recieve string length plus one from get_capacity after init_c_string\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_get_capacity_on_init_c_string_returns_string_length_plus_one\n",
	    length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_string_extraction_reads_correct_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  FILE* fp;
  fp = fopen("simple.txt", "r");
  if (fp == NULL) {
    status = FAILURE;
    printf("Failed to open file\n");
    strncpy(buffer, "test_string_extraction_reads_correct_string\n"
	    "cannot open file: string_extraction could not be tested\n", length);
  }
  hString = my_string_init_default();
  my_string_extraction(hString, fp);
  if (strcmp("The", my_string_c_str(hString)) != 0) {
    status = FAILURE;
    printf("Incorrect string read; \"%s\" was read instead of \"The\" from \"test_file.txt\"\n", my_string_c_str(hString));
    strncpy(buffer, "test_string_extraction_reads_correct_string\n"
	    "string_extraction read incorrect string\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_string_extraction_reads_correct_string\n", length);
  }
  fclose(fp);
  my_string_destroy(&hString);
  return status;
}

Status test_string_insertion_returns_success_on_successful_write(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  FILE* fp;
  fp = fopen("simple2.txt", "r");
  if (fp == NULL) {
    status = FAILURE;
    printf("Failed to open file\n");
    strncpy(buffer, "test_string_insertion_returns_success_on_successful_write\n"
	    "cannot open file: string_extraction could not be tested\n", length);
  }
  hString = my_string_init_c_string("The quick brown fox jumped over the lazy dogs.");
  if (!my_string_insertion(hString, fp)) {
    status = FAILURE;
    strncpy(buffer, "test_string_insertion_returns_success_on_successful_write\n"
	    "string_extraction returned failure\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_string_insertion_returns_success_on_successful_write\n", length);
  }
  fclose(fp);
  my_string_destroy(&hString);
  return status;
}

Status test_push_back_returns_success_pushing_char_on_empty_default_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if (!my_string_push_back(hString, 'A')) {
    status = FAILURE;
    strncpy(buffer, "test_push_back_returns_success_pushing_char_on_empty_default_string\n"
	    "push_back returned failure\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_push_back_returns_success_pushing_char_on_empty_default_string\n",
	    length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_push_back_returns_success_pushing_char_on_full_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("The quick brown fox jumped over the lazy dogs");
  if (!my_string_push_back(hString, '.')) {
    status = FAILURE;
    strncpy(buffer, "test_push_back_returns_success_pushing_char_on_empty_default_string\n"
	    "push_back returned failure\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_push_back_returns_success_pushing_char_on_full_string\n",
	    length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_push_back_doubles_string_capacity_on_resize(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int init_capacity;
  hString = my_string_init_c_string("The quick brown fox jumped over the lazy dogs");
  init_capacity = my_string_get_capacity(hString);
  my_string_push_back(hString, '.');
  if (my_string_get_capacity(hString) != init_capacity * 2) {
    status = FAILURE;
    printf("push_back changed capacity from %d to %d, which is not double\n", init_capacity, my_string_get_capacity(hString));
    strncpy(buffer, "test_push_back_doubles_string_capacity_on_resize\n"
	    "push_back did not double string capacity\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_push_back_doubles_string_capacity_on_resize\n", length);
  }
  my_string_destroy(&hString);
  return status;
}


Status test_push_back_increments_size_by_one(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int init_size;
  hString = my_string_init_c_string("The quick brown fox jumped over the lazy dogs");
  init_size = my_string_get_size(hString);
  my_string_push_back(hString, '.');
  if (my_string_get_size(hString) != init_size + 1) {
    status = FAILURE;
    printf("push_back changed size from %d to %d, which is not one greater\n", init_size, my_string_get_size(hString));
    strncpy(buffer, "test_push_back_increments_size_by_one\n"
	    "push_back did not double string capacity\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_push_back_increments_size_by_one\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_pop_back_returns_success_on_non_empty_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("The quick brown fox jumped over the lazy dogs.");
  if (!my_string_pop_back(hString)) {
    status = FAILURE;
    strncpy(buffer, "test_pop_back_returns_success_on_non_empty_string\n"
	    "pop_back returned failure\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_pop_back_returns_success_on_non_empty_string\n",
	    length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_pop_back_decrements_size_by_one(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int init_size;
  hString = my_string_init_c_string("The quick brown fox jumped over the lazy dogs.");
  init_size = my_string_get_size(hString);
  my_string_pop_back(hString);
  if (my_string_get_size(hString) != init_size - 1) {
    status = FAILURE;
    printf("Expected size after pop_back to be %d, but it was %d\n", init_size - 1, my_string_get_size(hString));
    strncpy(buffer, "test_pop_back_decrements_size_by_one\n"
	    "pop_back did not decrement size by one\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_pop_back_decrements_size_by_one\n", length);
  }
  my_string_destroy(&hString);
  return status;
}


Status test_pop_back_returns_failure_on_empty_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if (my_string_pop_back(hString)) {
    status = FAILURE;
    strncpy(buffer, "test_pop_back_returns_failure_on_empty_string\n"
	    "pop_back returned success\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_pop_back_returns_failure_on_empty_string\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_string_empty_returns_true_on_empty_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if (!my_string_empty(hString)) {
    status = FAILURE;
    strncpy(buffer, "test_string_empty_returns_true_on_empty_string\n"
	    "string_empty returned false on empty string\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_string_empty_returns_true_on_empty_string\n", length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_string_empty_returns_false_on_non_empty_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("The quick brown fox jumped over the lazy dogs.");
  if (my_string_empty(hString)) {
    status = FAILURE;
    strncpy(buffer, "test_string_empty_returns_false_on_non_empty_string\n"
	    "string_empty returned true on non-empty string\n", length);
  }
  else {
    status = SUCCESS;
    strncpy(buffer, "test_string_empty_returns_false_on_non_empty_string\n", length);
  }
  my_string_destroy(&hString);
  return status;
}


