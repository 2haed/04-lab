//
// Created by MrMam on 12.03.2022.
//

#ifndef TEMPLATE_UTILS_H
#define TEMPLATE_UTILS_H

#include <iostream>

namespace utils {
using size_t = unsigned long long;
struct int_pair {
  int min, max;
};

struct double_pair {
  double min, max;
};

struct string_array {
  const char** str;
  size_t size;
};
}

#endif  // TEMPLATE_UTILS_H
