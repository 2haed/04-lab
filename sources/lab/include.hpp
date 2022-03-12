#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <utils.h>
using namespace utils;

double mean(const int* arr, int size);
int_pair argmax(const int* arr, int size);
float_pair min_max(const int* array, int size);
void sort(int* array, int size);
bool remove_first_negative_element(const int** vec, int size, int& removed_element);
char* replace(const char* str, const char* old, const char* new_string);
char** split(const char*, char sep);
char* join(const char**, const char* sep);


#endif // INCLUDE_EXAMPLE_HPP_
