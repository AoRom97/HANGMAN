#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);

//

Status test_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_handle_set_to_NULL_after_string_destroy(char* buffer, int length);

//

Status test_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_c_string_returns_string_length(char* buffer, int length);
Status test_get_capacity_on_init_c_string_returns_string_length_plus_one(char* buffer, int length);

//

Status test_string_extraction_returns_success_on_succressful_read(char* buffer, int length);

//

Status test_string_insertion_returns_success_on_successful_write(char* buffer, int length);

//

Status test_push_back_returns_success_pushing_char_on_empty_default_string(char* buffer, int length);
Status test_push_back_returns_success_pushing_char_on_full_string(char* buffer, int length);
Status test_push_back_doubles_string_capacity_on_resize(char* buffer, int length);
Status test_push_back_increments_size_by_one(char* buffer, int length);

//

Status test_pop_back_returns_success_on_non_empty_string(char* buffer, int length);
Status test_pop_back_decrements_size_by_one(char* buffer, int length);
Status test_pop_back_returns_failure_on_empty_string(char* buffer, int length);

//

Status test_string_empty_returns_true_on_empty_string(char* buffer, int length);
Status test_string_empty_returns_false_on_non_empty_string(char* buffer, int length);




