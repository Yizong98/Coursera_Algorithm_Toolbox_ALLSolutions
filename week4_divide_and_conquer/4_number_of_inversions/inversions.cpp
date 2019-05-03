#include <iostream>
#include <vector>
#include <limits>
#include <tuple> 
using std::vector;

long long merge_help(vector<int> &a,vector<int> &b, int left, int right){
  int count = 0;
  int total = right - left + 1;
  int mid = (right + left + 1) / 2;
  int l = 0;
  vector<long long> acpy = vector<long long> (a.begin() + left, a.begin() + mid);
  acpy.push_back(std::numeric_limits<int>::max());
  vector<long long> bcpy = vector<long long> (a.begin() + mid, a.begin() + right + 1);
  bcpy.push_back(std::numeric_limits<int>::max());
  for (int idx = 0; idx < total;idx++){
    int tempa = acpy.front();
    int tempb = bcpy.front();
    if (tempa <= tempb){
      acpy.erase(acpy.begin());
      a[left++] = tempa;
    } else {
      bcpy.erase(bcpy.begin());
      a[left++] = tempb;
      count += (acpy.size()-1-l); 
    }
  }
  return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = (right + left + 1) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave-1);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  number_of_inversions += merge_help(a,b,left,right);
  //write your code here
  return number_of_inversions;
}
// 2 get_number_of_inversions(a, b, 0, 1)--> 0;get_number_of_inversions(a, b, 2, 4);
// 9 2 --> 
// 88881 111 // 4 --> 888 81 --> 88 8
// 


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  b = a;
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}

// 2 3 9  2 9 
// 2 3 2 9 9
// 2 2 3 9 9
// 6 1 5 2 3 --> 615 23 --> 61 5 23 --> --> 16 5 --> 2 --> 156 23 --> 4 --> (6)
// 2 3 9 2 9 --> 23 9 29 --> 239 29 --> 2 
// 88881111




