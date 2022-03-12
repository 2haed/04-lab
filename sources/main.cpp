//
// Created by MrMam on 05.03.2022.
//

#include <iostream>

char* operator=()(const char*){

}

int main() {
  char** values = new char*[4];
  values[0] = "halo";
  std::cout << "Hallo!";
  return 0;
}