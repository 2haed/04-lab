#include <gtest/gtest.h>
#include <include.hpp>

TEST(Task1, Middle) {
  // базовый сценарий
  std::vector<int> v = {11, 2, 36, 47, 5, 53, 56};
  auto result = mean(v.data(), v.size());
  EXPECT_NEAR(result, 30, std::numeric_limits<double>::epsilon());
  // отрицательные коэффициенты
  v = {-11, -2, -36, -47, -5, -53, -56};
  result = mean(v.data(), v.size());
  EXPECT_NEAR(result, -30, std::numeric_limits<double>::epsilon());
  // положительные и отрицательные коэффициенты
  v = {5, -3, -5, 47, -40, 3, 0};
  result = mean(v.data(), v.size());
  EXPECT_NEAR(result, 1, std::numeric_limits<double>::epsilon());
  // вектор из одного элемента
  v = {456};
  result = mean(v.data(), v.size());
  EXPECT_NEAR(result, 456, std::numeric_limits<double>::epsilon());
  v = {};
  result = mean(v.data(), v.size());
  EXPECT_EQ(result, 0);
}

TEST(Task2, MinimunAndMaximum) {
  std::vector<int> v = {1, 2, 3, 4, 5, 0};
  auto pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, 0, std::numeric_limits<double>::epsilon());
  EXPECT_NEAR(pair.max, 5, std::numeric_limits<double>::epsilon());

  v = {-1, -2, -3, -4, -5, 0};
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, -5, std::numeric_limits<double>::epsilon());
  EXPECT_NEAR(pair.max, 0, std::numeric_limits<double>::epsilon());
  // массив из одинаковых элементов
  v = {1, 1, 1, 1, 1, 1};
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, 1, std::numeric_limits<double>::epsilon());
  EXPECT_NEAR(pair.max, 1, std::numeric_limits<double>::epsilon());

  // массив из одного элемента
  v = {15};
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, 15, std::numeric_limits<double>::epsilon());
  EXPECT_NEAR(pair.max, 15, std::numeric_limits<double>::epsilon());

  // пустой массив
  v = {};
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, std::numeric_limits<double>::min(), std::numeric_limits<double>::epsilon());
  EXPECT_NEAR(pair.max, std::numeric_limits<double>::max(), std::numeric_limits<double>::epsilon());
}

TEST(Task3, Argmax) {
  std::vector<int> v = {11, 2, 36, 47, 5, 53, 56};
  auto index = argmax(v.data(), v.size());
  EXPECT_EQ(index.min, 1);
  EXPECT_EQ(index.max, 6);
  // отрицательные коэффициенты
  v = {-11, -2, -36, -47, -5, -53, -56};
  index = argmax(v.data(), v.size());
  EXPECT_EQ(index.max, 1);
  EXPECT_EQ(index.min, 6);
  // положительные и отрицательные коэффициенты
  v = {5, -3, -5, 47, -40, 3, 0};
  index = argmax(v.data(), v.size());
  EXPECT_EQ(index, 3);
  // массив из одинаковых элементов
  v = {5, 5, 5, 5, 5, 5, 5};
  index = argmax(v.data(), v.size());
  EXPECT_EQ(index, 0);
  // вектор из одного элемента
  v = {456};
  index = argmax(v.data(), v.size());
  EXPECT_EQ(index, 0);
  // пустой вектор
  v = {};
  index = argmax(v.data(), v.size());
  EXPECT_EQ(index, -1);
}

TEST(Task4, Sort) {
  // базовый сценарий
  std::vector<int> v = {11, 2, 36, 47, 5, 53, 56};
  std::vector<int> res_v = {2, 5, 11, 36, 47, 53, 56};
  sort(v.data(), v.size());
  EXPECT_EQ(v, res_v);
  // отрицательные коэфиициенты
  v = {-11, -2, -36, -47, -5, -53, -56};
  res_v = {-56, -53, -47, -36, -11, -5, -2};
  sort(v.data(), v.size());
  EXPECT_EQ(v, res_v);
  // положительные и отрицательные коэфиициенты
  v = {5, -3, -5, 47, -40, 3, 0};
  res_v = {-40, -5, -3, 0, 3, 5, 47};
  sort(v.data(), v.size());
  EXPECT_EQ(v, res_v);
  // вектор из одного элемента
  v = {456};
  res_v = {456};
  sort(v.data(), v.size());
  EXPECT_EQ(v, res_v);
  // пустой вектор
  v = {};
  res_v = {};
  sort(v.data(), v.size());
  EXPECT_EQ(v, res_v);
}

TEST(Task5, RemoveFirstNegativeElement) {
  // базовый сценарий
  int removed_element = 0;
  std::vector<int> v = {11, -2, 36, -47, 5, 53, 56};
  const int* data = v.data();
  std::vector<int> result = {11, 36, -47, 5, 53, 56};
  bool test = remove_first_negative_element(&data, v.size(), removed_element);
  EXPECT_EQ(v, result);
  EXPECT_EQ(test, true);
  EXPECT_EQ(removed_element, -2);
  // только неотрицательные элементы
  v = {11, 2, 0, 47, 5, 53, 56};
  data = v.data();
  result = {11, 2, 0, 47, 5, 53, 56};
  test = remove_first_negative_element(&data, v.size(), removed_element);
  EXPECT_EQ(v, result);
  EXPECT_EQ(test, false);
  EXPECT_EQ(removed_element, 0);
  // один отрицательный элемент
  v = {-111};
  data = v.data();
  result = {};
  test = remove_first_negative_element(&data, v.size(), removed_element);
  EXPECT_EQ(v, result);
  EXPECT_EQ(test, true);
  EXPECT_EQ(removed_element, -111);
  // пустой массив
  v = {};
  data = v.data();
  result = {};
  test = remove_first_negative_element(&data, v.size(), removed_element);
  EXPECT_EQ(v, result);
  EXPECT_EQ(test, false);
  EXPECT_EQ(removed_element, 0);
}

TEST(Task6, Replace) {
  std::string str = replace("Can you can a can as a canner can can a can?", "can", "cAN");
  std::string result = "Can you cAN a cAN as a cANner cAN cAN a cAN?";
  EXPECT_EQ(result, str);

  str = replace("can cancan cancancan cancancancan", "c", "C");
  result = "Can CanCan CanCanCan CanCanCanCan";
  EXPECT_EQ(result, str);

  str = replace("     ", " ", "T");
  result = "TTTTT";
  EXPECT_EQ(result, str);

  str = replace("", "can", "cAN");
  result = "";
  EXPECT_EQ(result, str);
}

TEST(Task7, Split) {
  // базовый случай
  std::string str = "Hello! Do you like programming?";
  std::vector<const char*> result = {"Hello!", "Do", "you", "like", "programming?"};
  string_array v{};
  auto data = split(str.c_str(), ' ');
  EXPECT_EQ(result, v);
  // строка не содержит пробелов
  str = "Hello!";
  result = {"Hello!"};
  v = split(str.c_str(), ' ');
  EXPECT_EQ(result, v);
  // строка пустая
  str = "";
  result = {};
  v = split(str.c_str(), ' ');
  EXPECT_EQ(result, v);
  // строка состоит только из пробельного символа
  str = " ";
  result = {};
  v = split(str.c_str(), ' ');
  EXPECT_EQ(result, v);
  // строка не пустая, но не содержит разделительного символа
  str = "Hello! Do you like programming?";
  result = {"Hello! Do you like programming?"};
  v = split(str.c_str(), '.');
  EXPECT_EQ(result, v);
  // в роли разделителя не пробел
  str = "Hello!.Do.you.like.programming?";
  result = {"Hello!", "Do", "you", "like", "programming?"};
  v = split(str.c_str(), '.');
  EXPECT_EQ(result, v);
}

TEST(Task8, Join) {
  std::vector<const char*> arr = {"Can", "you", "can", "a", "can", "as",  "a", "canner", "can", "can", "a", "can?"};
  std::string str = join(string_array{arr.data(), arr.size()}, " ");
  std::string result = "Can you can a can as a canner can can a can?";
  EXPECT_EQ(result, str);

  arr = {"Hello!", "Do", "you", "like", "programming?"};
  str = join(string_array{arr.data(), arr.size()}, " ");
  result = "Hello! Do you like programming?";
  EXPECT_EQ(result, str);

  arr = {""};
  str = join(string_array{arr.data(), arr.size()}, " ");
  result = "";
  EXPECT_EQ(result, str);

  arr = {"Can", "you", "can", "a", "can", "as",  "a", "canner", "can", "can", "a", "can?"};
  str = join(string_array{arr.data(), arr.size()}, "...");
  result = "Can...you...can...a...can...as...a...canner...can...can...a...can?";
  EXPECT_EQ(result, str);
}