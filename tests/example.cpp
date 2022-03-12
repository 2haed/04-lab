#include <gtest/gtest.h>
#include <include.hpp>

TEST(Task1, Middle) {
  // базовый сценарий
  int* v1 = new int[7]{11, 2, 36, 47, 5, 53, 56};
  auto result = mean(v1, 7);
  EXPECT_NEAR(result, 30, std::numeric_limits<double>::epsilon());
  delete[] v1;
  // отрицательные коэффициенты
  int* v2 = new int[7]{-11, -2, -36, -47, -5, -53, -56};
  result = mean(v2, 7);
  EXPECT_NEAR(result, -30, std::numeric_limits<float>::epsilon());
  delete[] v2;
  // положительные и отрицательные коэффициенты
  int* v3 = new int[7]{5, -3, -5, 47, -40, 3, 0};
  result = mean(v3, 7);
  EXPECT_NEAR(result, 1, std::numeric_limits<float>::epsilon());
  delete[] v3;
  // вектор из одного элемента
  int* v4 = new int[1]{456};
  result = mean(v4, 1);
  EXPECT_NEAR(result, 456, std::numeric_limits<float>::epsilon());
  delete[] v4;
}

TEST(Task2, MinimunAndMaximum) {
  std::vector<int> v = {1, 2, 3, 4, 5, 0};
  auto pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, 0, std::numeric_limits<float>::epsilon());
  EXPECT_NEAR(pair.max, 5, std::numeric_limits<float>::epsilon());

  v = {-1, -2, -3, -4, -5, 0}
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, -5, std::numeric_limits<float>::epsilon());
  EXPECT_NEAR(pair.max, 0, std::numeric_limits<float>::epsilon());
  // массив из одинаковых элементов
  v = {1, 1, 1, 1, 1, 1};
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, 1, std::numeric_limits<float>::epsilon());
  EXPECT_NEAR(pair.max, 1, std::numeric_limits<float>::epsilon());

  // массив из одного элемента
  v = {15};
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, 15, std::numeric_limits<float>::epsilon());
  EXPECT_NEAR(pair.max, 15, std::numeric_limits<float>::epsilon());

  // пустой массив
  v = {};
  pair = min_max(v.data(), v.size());
  EXPECT_NEAR(pair.min, std::numeric_limits<float>::min(), std::numeric_limits<float>::epsilon());
  EXPECT_NEAR(pair.max, std::numeric_limits<float>::max(), std::numeric_limits<float>::epsilon());
}

TEST(Task3, Argmax) {
  // базовый сценарий
  std::vector<int> v1 = {11, 2, 36, 47, 5, 53, 56};
  auto index = argmax(v1.data(), v1.size());
  EXPECT_EQ(index.min, 1);
  EXPECT_EQ(index.max, 6);
  // отрицательные коэффициенты
  int* v2 = new int[7]{-11, -2, -36, -47, -5, -53, -56};
  index_max = argmax(v2, 7);
  EXPECT_EQ(index_max, 1);
  delete[] v2;
  // положительные и отрицательные коэффициенты
  int* v3 = new int[7]{5, -3, -5, 47, -40, 3, 0};
  index_max = argmax(v3, 7);
  EXPECT_EQ(index_max, 3);
  delete[] v3;
  // массив из одинаковых элементов
  int* v5 = new int[7]{5, 5, 5, 5, 5, 5, 5};
  index_max = argmax(v5, 7);
  EXPECT_EQ(index_max, 0);
  delete[] v5;
  // вектор из одного элемента
  int* v4 = new int[1]{456};
  index_max = argmax(v4, 1);
  EXPECT_EQ(index_max, 0);
  delete[] v4;
  // пустой вектор
  int* v6 = new int[0]{};
  index_max = argmax(v6, 0);
  EXPECT_EQ(index_max, -1);
  delete[] v6;
}

TEST(Task4, Sort) {
  // базовый сценарий
  std::vector<float> v1 = {11, 2, 36, 47, 5, 53, 56};
  std::vector<float> res_v1 = {2, 5, 11, 36, 47, 53, 56};
  sort(v1);
  EXPECT_EQ(v1, res_v1);
  // отрицательные коэфиициенты
  std::vector<float> v2 = {-11, -2, -36, -47, -5, -53, -56};
  std::vector<float> res_v2 = {-56, -53, -47, -36, -11, -5, -2};
  sort(v2);
  EXPECT_EQ(v2, res_v2);
  // положительные и отрицательные коэфиициенты
  std::vector<float> v3 = {5, -3, -5, 47, -40, 3, 0};
  std::vector<float> res_v3 = {-40, -5, -3, 0, 3, 5, 47};
  sort(v3);
  EXPECT_EQ(v3, res_v3);
  // вектор из одного элемента
  std::vector<float> v4 = {456};
  std::vector<float> res_v4 = {456};
  sort(v4);
  EXPECT_EQ(v4, res_v4);
  // пустой вектор
  std::vector<float> v5 = {};
  std::vector<float> res_v5 = {};
  sort(v5);
  EXPECT_EQ(v5, res_v5);
}

TEST(Task5, RemoveFirstNegativeElement) {
  // базовый сценарий
  int removed_element = 0;
  int size = 7;
  int* v1;
  v1 = new int[size]{11, -2, 36, -47, 5, 53, 56};
  int* result1 = new int[6]{11, 36, -47, 5, 53, 56};
  bool test = remove_first_negative_element(v1, size, removed_element);
  PRINT_ARRAY(v1,size);
  EXPECT_TRUE(compare_arrays(v1, result1, size, 6));
  EXPECT_EQ(test, true);
  EXPECT_EQ(removed_element, -2);
  // только неотрицательные элементы
  size = 7;
  int* v2 = new int[size]{11, 2, 0, 47, 5, 53, 56};
  int* result2 = new int[7]{11, 2, 0, 47, 5, 53, 56};
  test = remove_first_negative_element(v2, size, removed_element);
  EXPECT_TRUE(compare_arrays(v2, result2, size, 7));
  EXPECT_EQ(test, false);
  EXPECT_EQ(removed_element, 0);
  // один отрицательный элемент
  size = 1;
  int* v3 = new int[1]{-111};
  int* result3 = new int[0]{};
  test = remove_first_negative_element(v3, size, removed_element);
  EXPECT_TRUE(compare_arrays(v3, result3, size, 0));
  EXPECT_EQ(test, true);
  EXPECT_EQ(removed_element, -111);
  // пустой массив
  size = 0;
  int* v4 = new int[size]{};
  int* result4 = new int[0]{};
  test = remove_first_negative_element(v4, size, removed_element);
  EXPECT_TRUE(compare_arrays(v4, result4, size, 0));
  EXPECT_EQ(test, false);
  EXPECT_EQ(removed_element, 0);
}

TEST(Task6, Replace) {
  std::string newString1 = replace("Can you can a can as a canner can can a can?", "can", "cAN");
  std::string result1 = "Can you cAN a cAN as a cANner cAN cAN a cAN?";
  EXPECT_EQ(result1, newString1);

  std::string newString2 = replace("can cancan cancancan cancancancan", "c", "C");
  std::string result2 = "Can CanCan CanCanCan CanCanCanCan";
  EXPECT_EQ(result2, newString2);

  std::string newString3 = replace("     ", " ", "T");
  std::string result3 = "TTTTT";
  EXPECT_EQ(result3, newString3);

  std::string newString4 = replace("", "can", "cAN");
  std::string result4 = "";
  EXPECT_EQ(result4, newString4);
}

TEST(Task7, Split) {
  // базовый случай
  std::string str1 = "Hello! Do you like programming?";
  std::vector<std::string> result1 = {"Hello!", "Do", "you", "like", "programming?"};
  std::vector<std::string> v1 = split(str1, ' ');
  EXPECT_EQ(result1, v1);
  // строка не содержит пробелов
  std::string str2 = "Hello!";
  std::vector<std::string> result2 = {"Hello!"};
  std::vector<std::string> v2 = split(str2, ' ');
  EXPECT_EQ(result2, v2);
  // строка пустая
  std::string str3 = "";
  std::vector<std::string> result3 = {};
  std::vector<std::string> v3 = split(str3, ' ');
  EXPECT_EQ(result3, v3);
  // строка состоит только из пробельного символа
  std::string str4 = " ";
  std::vector<std::string> result4 = {};
  std::vector<std::string> v4 = split(str4, ' ');
  EXPECT_EQ(result4, v4);
  // строка не пустая, но не содержит разделительного символа
  std::string str5 = "Hello! Do you like programming?";
  std::vector<std::string> result5 = {"Hello! Do you like programming?"};
  std::vector<std::string> v5 = split(str5, '.');
  EXPECT_EQ(result5, v5);
  // в роли разделителя не пробел
  std::string str6 = "Hello!.Do.you.like.programming?";
  std::vector<std::string> result6 = {"Hello!", "Do", "you", "like", "programming?"};
  std::vector<std::string> v6 = split(str6, '.');
  EXPECT_EQ(result6, v6);
}

TEST(Task8, Join) {
  std::vector<std::string> arr1 = {"Can", "you", "can", "a", "can", "as",  "a", "canner", "can", "can", "a", "can?"};
  std::string str1 = join(arr1, " ");
  std::string result1 = "Can you can a can as a canner can can a can?";
  EXPECT_EQ(result1, str1);

  std::vector<std::string> arr2 = {"Hello!", "Do", "you", "like", "programming?"};
  std::string str2 = join(arr2, " ");
  std::string result2 = "Hello! Do you like programming?";
  EXPECT_EQ(result2, str2);

  std::vector<std::string> arr3 = {""};
  std::string str3 = join(arr3, " ");
  std::string result3 = "";
  EXPECT_EQ(result3, str3);

  std::vector<std::string> arr4 = {"Can", "you", "can", "a", "can", "as",  "a", "canner", "can", "can", "a", "can?"};
  std::string str4 = join(arr4, "...");
  std::string result4 = "Can...you...can...a...can...as...a...canner...can...can...a...can?";
  EXPECT_EQ(result4, str4);
}