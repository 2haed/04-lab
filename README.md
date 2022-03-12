## Лабораторная работа 4

### Теоретическая справка
#### TODO: Переписать теорию
**Ссылки**
* Ссылки, как и указатели, являются сложной для понимания частью языка.
* Если информации на лекциях было недостаточно или вы что-то упустили, то воспользуйтесь [ссылкой](http://cppstudio.com/post/429/)
* Пример работы со ссылками - https://github.com/bmstu-iu8-cpp/cpp-beginner-2017/tree/master/lab5

**Функции и разделение кода на файлы**
* Функция — средство языка, которое позволяет в разы сократить объем вашего кода, внести в него ясность для других программистов (и проверяющего в частности), реализовать более сложные алгоритмы и создать универсальное средство решения для типовых задач.

Ниже можете ознакомиться с полезными ссылками:
* что такое функции и для чего они нужны - http://cppstudio.com/post/396/
* разделение исходного кода на файлы - https://metanit.com/cpp/tutorial/3.8.php
* Примеры кода, которые окончательно внесут ясность - https://github.com/bmstu-iu8-cpp/cpp-beginner-2017/tree/master/lab5

**Объявление и определение функции**
Чем определение функции отличается от её объявления? Объявление функции сообщает нам лишь о типе её возвращаемого значения,
количсетве аргументов и их типе, а также о том, что в коде мы должны встретить её реализацию. Перед использованием функции мы ВСЕГДА
должны её объявить. Определение функции — это сам код функции, алгоритм. [Подробнее](https://metanit.com/cpp/tutorial/3.1.php)

**Передача аргументов по ссылкам**
* Ссылки используются в С++ повсеместно, поэтому необходимо разобраться в принципе их использования. По ссылкам
  передаются переменные в функции, чтобы изменять сам объект, а не его копию. Ссылки позволяют избежать
  нежелательного копирования.
* Зачем все таки передавать аргументы по ссылке - https://metanit.com/cpp/tutorial/3.3.php

**Константные ссылки**
* Константные ссылки мы используем для того, чтобы избежать ненужного копирования аргумента, но при этом не изменить
  его значение. Дело в том, что функция, как мы уже знаем, работает не с самим аргументом, а с его копией, если передача
  аргумента идет по значению. Как следствие, возникает дополнительное копирование, которого мы стремимся избежать. Если аргумент
  не должен быть изменен в теле функции, а копировать его нецелесообразно, используем константные ссылки.
* Читаем на эту тему подробнее [тут](http://alenacpp.blogspot.com/2005/09/const-1.html)

### Инструкция
- Прототипы функции должны быть вынесены в `include.hpp` файл.
- Все `.cpp` файлы добавить в `CMakeLists.txt`
- Все необходимо объявить в `namespace utils`. Вы потом их будете использовать.

Подробнее о составлении `CMakeLists.txt` (для интересующихся) можно почитать [тут](https://habr.com/post/155467/).

### Задание
1. Необходимо реализовать функцию, которая определяет арифметическое среднее в массиве.
   Прототип функции:
```cpp
float mean(const int* array, int size);
```

### Примечание перед следующими задачами:
Для удобства были реализованы две структуры __pair.
Их можно найти в файле [utils.h](sources/utils/utils.h)
```c++
struct int_pair {
    int min, max;
};

struct double_pair {
    double min, max;
};
```

2. Необходимо реализовать функцию, которая определяет индекс максимального и минимального элемента в массиве. Прототип функции:
```c++
int_pair min_max_args(const int* array, int size);
```
4. Необходимо реализовать функцию, которая определяет максимум и минимум в массиве.
   Прототип функции:
```cpp
double_pair min_max(const int* array, int size);
```
Если массив пуст, функция должна вернуть `min` и `max` из `std::numeric_limits`.
Об этом можно почитать [тут](https://en.cppreference.com/w/cpp/types/numeric_limits).

3. Необходимо реализовать функцию, которая сортирует по убыванию входной массив.
   Стандартными функциями для сортировки массива пользоваться нельзя!
   Прототип функции:
```cpp
void sort(int* array, int size);
```

4. Необходимо реализовать функцию `remove_first_negative_element`, которая удаляет первый отрицательный элемент массива.
   Прототип функции:
```cpp
bool remove_first_negative_element(const int** vec, int size, int& removed_element);
```
Функция возвращает `true` если удалось удалить элемент, а `false` если не удалось.
Значение удаленного элемента помещать в `removed_element`, если удаление не произошло то инициализировать `removed_element` нулем.

5. Необходимо реализовать функцию, которая подсчитывает длину C-style строки. Такие строки обычно являются `char*` и заканчиваются терминирующим нулём `\0`
```c++
size_t strlen(const char* str);
```

6. Необходимо реализовать функцию, которая заменяет в строке все вхождения подстроки на новую строку.
   Можно пользоваться функцией `std::string::find`, о которой можно почитать [тут](https://ru.cppreference.com/w/cpp/string/basic_string/find).
```cpp
char* replace(const char* str, const char* old, const char* new_string);
```
Пример:
```cpp
char* newString = replace("Can you can a can as a canner can can a can?", "can", "cAN");
std::cout << newString; // "Can you cAN a cAN as a cANner cAN cAN a cAN?"
```

### Примечание перед следующими задачами:
Для удобства можете реализовать структуру `string_array` в файле [utils.h](sources/utils/utils.h)
*(И вообще, почаще их используйте)*
```c++
struct string_array {
    char** str;
    size_t size;
};
```

6. Необходимо реализовать функцию `split`, которая делит строку по заданному символу.
```cpp
string_array split(const char*, char sep);
```
Пример:
```cpp
string_array arr = split("Can you can a can as a canner can can a can?", ' ');
// arr.str == {"Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?"};
// arr.size == 12
```
Если строка состоит только из символов, которые указаны вторым аргументом, функция должна вернуть пустой вектор.

7. Необходимо реализовать функцию, которая соединяет массив строк в одну строку.
```cpp
char* join(const string_array& arr, const char* sep);
```
Пример:
```cpp
// arr == {"Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?"};
std::string str = join({arr, 12}, " ");
// str == "Can you can a can as a canner can can a can?"
```