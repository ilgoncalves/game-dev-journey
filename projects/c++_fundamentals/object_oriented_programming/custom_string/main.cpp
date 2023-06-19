#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

class String {
 private:
  char* str;
  size_t len;

 public:
  String(const char* str = "") : len(std::strlen(str)) {
    this->str = new char[len + 1];
    std::strcpy(this->str, str);
  }

  String(const String& other) : len(other.len) {
    str = new char[len + 1];
    std::strcpy(str, other.str);
  }

  ~String() { delete[] str; }

  size_t length() const { return len; }

  String substr(size_t start, size_t length) const {
    if (start > len) {
      throw std::out_of_range("Invalid start position");
    }

    char* substr = new char[length + 1];
    std::strncpy(substr, str + start, length);
    substr[length] = '\0';

    String result(substr);
    delete[] substr;

    return result;
  }

  size_t find(const String& substring) const {
    char* pos = std::strstr(str, substring.str);
    if (pos) {
      return pos - str;
    } else {
      return npos;
    }
  }

  String operator+(const String& other) const {
    char* new_str = new char[len + other.len + 1];
    std::strcpy(new_str, str);
    std::strcat(new_str, other.str);

    String result(new_str);
    delete[] new_str;

    return result;
  }

  String& operator+=(const String& other) {
    char* new_str = new char[len + other.len + 1];
    std::strcpy(new_str, str);
    std::strcat(new_str, other.str);

    delete[] str;
    str = new_str;
    len += other.len;

    return *this;
  }

  bool operator==(const String& other) const {
    return std::strcmp(str, other.str) == 0;
  }

  bool operator!=(const String& other) const { return !(*this == other); }

  friend std::ostream& operator<<(std::ostream& os, const String& string);

  static const size_t npos = -1;
};

std::ostream& operator<<(std::ostream& os, const String& string) {
  os << string.str;
  return os;
}

int main() {
  String str1 = "Hello, ";
  String str2 = "world!";
  String str3 = str1 + str2;

  std::cout << str3 << "\n";

  std::cout << str3.substr(7, 5) << "\n";

  std::cout << str3.find("world") << "\n";
  return 0;
}
