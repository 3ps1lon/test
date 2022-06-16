#include"string.hpp"

int main() {
  String str_1;
  String str_2("test");
  String new_str("_test_");
  String str_copy(str_2);
  str_1 = new_str;
  std::cout << str_2 << std::endl;
  str_2 += str_1;
  str_1 *= 7;
  std::cout << (str_1 == str_2) << std::endl;
  std::cout << (str_2 < str_1) << std::endl;
  String substr("te");
  std::cout << str_2.Find(substr) << std::endl;
  str_2.Replace('t', '-');
  str_2.Size();
  str_2.Empty();
  std::cout << str_2[6] << std::endl;
  str_2[2] = '+';
  String str_3("____TEST____");
  str_3.RTrim('_');
  str_3.LTrim('_');
  std::cout << str_3 << std::endl;
  String s1("aaa"), s2("bbb");
  s1.swap(s2);
  std::cout << s1 + s2 << std::endl;
  std::cout << s1 * 3 << std::endl;
  std::cout << (s1 != s2) << std::endl;
  std::cout << (s1 > s2) << std::endl;
  return 0;
}
