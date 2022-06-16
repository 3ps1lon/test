// Copyright 2020 Your Name <your_email>

#include <string.hpp>
#include <string.h>
#include <algorithm>


String::String(){
  Data = nullptr;
  length = 0;
}
String::~String() {
  delete[] Data;
}

String::String(const String &rhs) {
  length = rhs.length;
  Data = new char[length];
  for (size_t i = 0; i < length; i++) {
    Data[i] = rhs.Data[i];
  }

 /* length = rhs.length;
  Data = new char[length + 1];
  strcpy(Data, rhs.Data); */
}

String::String(const char* data)
{
  length = strlen(data);
  this->Data = new char[length + 1];
  for (size_t i = 0; i < length; i++)
    this->Data[i] = data[i];

  this->Data[length] = '\0';
}
String& String::operator=(const String& rhs) {
  if (&rhs != this) {
    length = rhs.length;
    Data = new char[length];
    for (size_t i = 0; i < length; i++)
      Data[i] = rhs.Data[i];
  }
  return *this;
}
String& String::operator+=(const String& rhs) {
  size_t lengthth = length;
  char *datata = new char[lengthth + rhs.length];
  std::copy(Data, Data + std::min(length, lengthth + rhs.length), datata);
  delete[] Data;
  Data = datata;
  length = lengthth + rhs.length;
  std::copy(rhs.Data, rhs.Data + rhs.length, Data + lengthth);

  return *this;
}

String& String::operator*=(unsigned int m) {
  String datata(*this);
  for (size_t i = 1; i < m; i++)
    *this += datata;
  return *this;
}

bool String::operator==(const String& rhs) const {
  if (rhs.length != length){
    return false;
  } else {
    for (size_t i = 0; i < length; i++){
      if (Data[i] != rhs.Data[i]){
        return false;
      }
    }
    return true;
  }
}
bool String::operator<(const String& rhs) const {
  if (length < rhs.length){
    return true;
  }
  if (length > rhs.length) {
    return false;
  }
  for (size_t i = 0; i < length; i++){
    if (Data[i] < rhs.Data[i]){
      return true;
    }
    return false;
  }

  return false; }
size_t String::Find(const String& substr) const {
  unsigned int i = 0;
  unsigned int j = 0;
  while (i < length) {
    while (Data[i] != substr.Data[0] && i < length) {
      ++i;
    }
    unsigned int t = i;
    while (j < substr.length && i < length
           && Data[i] == substr.Data[j]) {
      ++i;
      ++j;
    }
    if (j == substr.length)
      return t;
    ++i;
    j = 0;
  }
  return -1;}

void String::Replace(char oldSymbol, char newSymbol) {
  for (size_t i = 0; i < length; i++) {
    if (Data[i] == oldSymbol)
      Data[i] = newSymbol;
  }
}
size_t String::Size() const {return length; }
bool String::Empty() const { return (Size() == 0); }
char String::operator[](size_t index) const { return Data[index]; }
char& String::operator[](size_t index) { return Data[index]; }
void String::RTrim(char symbol) {
  size_t trim = 0;
  for (size_t i = length - 1;i = 0; i--) {
    if (Data[i] == symbol){
      trim++;
    } else {
      break;
    }
  }
  if (trim > 0) {
    char* datata = new char[length - trim];
    std::copy(Data, Data + (length - trim), datata);
    delete[] Data;

    Data = datata;
    length = length - trim;
  }
}

void String::LTrim(char symbol) {
  size_t trim = 0;
  for (size_t i = 0; i < length; i++) {
    if (Data[i] == symbol){
      trim++;
    } else {
      break;
    }
  }
  if (trim > 0) {
    char* datata = new char[length - trim];
    std::copy(Data + trim, Data + length, datata);
    delete[] Data;
    Data = datata;
    length = length - trim;
  }
}

void String::swap(String& oth) {
  String datata(*this);
  *this = oth;
  oth = datata;

}
std::ostream& operator<<(std::ostream& out, const String& str) {
  for (size_t i =0;i < str.length; i++){
    out << str[i];
  }
  return out;
}

String operator+(const String &a, const String &b) {
  String str(a);
  str += b;
  return str;
}

String operator*(const String &a, unsigned int b) {
  String str(a);
  str *= b;
  return str;
}
