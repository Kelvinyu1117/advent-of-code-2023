#include <iostream>
#include <string>
#include <vector>

using namespace std;

char try_split(std::string &s) {
  static const std::vector<std::pair<std::string, char>> mp{
      {"one", '1'},   {"two", '2'},   {"three", '3'},
      {"four", '4'},  {"five", '5'},  {"six", '6'},
      {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};

  bool is_found = false;
  char result = 0;

  for (const auto &[text, n] : mp) {
    if (auto it = s.find(text, 0); it != string::npos && it == 0) {
      result = n;
      s.erase(it, 1);
      is_found = true;
      break;
    }
  }

  if (!is_found) {
    if (!s.empty()) {
      char c = s[0];
      s.erase(0, 1);
      if (isdigit(c)) {
        return c;
      }
    }
  }

  return result;
}

int main() {
  string s;
  int sum = 0;
  while (getline(cin, s)) {
    std::string result_string{s};

    bool done = false;
    std::string vv;
    int i = 0;
    while (!done) {
      if (result_string.empty()) {
        done = true;
      } else {
        auto extracted = try_split(result_string);
        if (extracted) {
          if (vv.size() >= 2)
            vv.pop_back();

          vv.push_back(extracted);
        }
      }
    }

    if (!vv.empty()) {
      if (vv.size() == 1) {
        vv.push_back(vv[0]);
      }

      sum += std::stoi(vv);
      // std::cout << s << " " << vv[0] << vv[1] << '\n';
    }
  }

  cout << sum << '\n';

  return 0;
}
