#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;

bool cmp(string a , string b)
{
  string A , B;
  A = a.append(b);
  B = b.append(a);
  
  return A.compare(B) > 0 ? 1 : 0;
}

string largest_number2(vector<string> a) {
  //write your code here
  std::sort(a.begin() , a.end() , cmp);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

string largest_number(vector<string> a) {

  //write your code here
  std::stringstream ret;
  while (a.size() != 0){
    string maxDigit = "0";
    int idx = 0;
    int maxidx = 0;
    for (string x: a){
          idx++;
          if (std::stoi(x + maxDigit) > std::stoi(maxDigit + x)){
            maxDigit = x;
            maxidx = idx;
          }
    }
    ret << maxDigit;
    a.erase(a.begin() + maxidx - 1);
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  // stress test
  /*
  while(true){
    int n = rand() % 100 + 1;
    cout << n << "\n";
    vector<string> a;
    for (size_t i = 0; i < n; i++) {
      a.push_back(std::to_string(rand() % 1000 + 1));
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    string res1 = largest_number(a);
    string res2 = largest_number2(a);
    if (res1 != res2){
      cout << "WRONG FUCK!" << res1 << ' ' << res2 << "\n";
      for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
      }
      break;
    } 
    else {
      cout << "OK\n";
    }

  }
  //*/
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

//
//98197794933865853814801669666 [6357/63/629]  5495365014254082982422813115 
//98197794933865853814801669666 [63/6357/629]  5495365014254082982422813115

//63 635 629






