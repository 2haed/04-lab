//
// Created by MrMam on 05.03.2022.
//

#include <iostream>
#include <string>
#include <include.hpp>
#include <utils.h>

int main() {
  std::string str{"A string to split"};

  split(str.c_str(), ' ');

  return 0;
}