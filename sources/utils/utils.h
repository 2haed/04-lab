//
// Created by MrMam on 12.03.2022.
//

#ifndef TEMPLATE_UTILS_H
#define TEMPLATE_UTILS_H

namespace utils {
  struct int_pair {
    int min, max;
  };

  struct float_pair {
    float min, max;
  };

// TODO: функцию можно переписать под структуры массивов, советую это сделать. Но тогда придётся переписать тесты)0
bool compare_arrays(const int* lhs, const int* rhs, int lsize, int rsize) {
  if (lsize != rsize) {
    return false;
  }
  for (auto i = 0; i < lsize; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

void print_array(const int* arr, int size);

}
#define PRINT_ARRAY(arr, size) std::cout << #arr << ": "; utils::print_array(arr, size);

#endif  // TEMPLATE_UTILS_H
