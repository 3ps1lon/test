// Copyright 2020 Your Name <your_email>

#include <substring.hpp>
#include <cmath>

size_t str_find(const std::string& str, const std::string& substr){
  size_t t =  str.size();
  size_t last  = substr.size();
  if (t < last) {
    return -1;
  }
  while (t < last) {
    size_t temp = 0;
    while(temp <= last && str[ t + temp ] == substr[temp] ){
      temp++;
    }
    if (temp == last){
      return t;
    }
        t++;
  }
  return -1;
}
int hash(std::basic_string<char> s, int table_size, const int key)
{
  int hash_result = 0;
  for (size_t i = 0; i != s.size(); ++i)
    hash_result = (key * hash_result + s[i]) % table_size;
  hash_result = (hash_result * 2 + 1) % table_size;
  return hash_result;
}

size_t rk_find(const std::string& str, const std::string& substr) {
  size_t str_s = str.size();
  size_t substr_s = substr.size();
  int p = 997;
  int r = 899439232;
  if (str_s < substr_s) {
    return -1;
  }

  int hashS = hash(str, str_s, 45);
  int hashSS = hash(substr, substr_s, 45);

  for (size_t i = 0; i < str_s - substr_s; i++){
    if (hashS == hashSS){
      return i;
    }
    hashS = (p * hashS - static_cast<int> (pow(p, substr_s)) * hashS) % r;
  }
  return -1;
}

// https://brestprog.by/topics/prefixfunction/
std::vector<int> lps_func(const std::string& str){
  size_t i;
  std::vector<int>pi(str.length(), 0);
  for (i = 1; i < str.length(); i++) {
    int j = pi[i - 1];
    while (j > 0 && str[i] != str[j]) {
      j = pi[j - 1];
    }
    if (str[i] == str[j]) {
      pi[i] = j + 1;
    } else {
      pi[i] = j;
    }
  }
  return pi;
}

size_t kmp_find(const std::string& str, const std::string& substr){
  size_t i;
  std::vector<int> pi = lps_func(substr +'#'+str);
  int t_len = substr.length();
  for (i = 0; i < str.size(); i++) {
    if (pi[t_len + 1 + i] == t_len) {
      return i - t_len + 1;
    }
  }
  return -1;
}
