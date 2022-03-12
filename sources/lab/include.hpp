#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <utils.h>
using namespace utils;

double mean(const int* arr, int size);
int_pair argmax(const int* arr, int size);
double_pair min_max(const int* array, int size);
void sort(int* array, int size);
bool remove_first_negative_element(const int** vec, int size, int& removed_element);
char* replace(const char* str, const char* old, const char* new_string);
string_array split(const char*, char sep);
char* join(const string_array&, const char* sep);


#endif // INCLUDE_EXAMPLE_HPP_
