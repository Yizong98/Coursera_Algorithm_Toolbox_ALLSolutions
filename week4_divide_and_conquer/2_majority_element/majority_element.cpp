#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int cntHelper(vector<int> &a, int left, int right, int element){
  int count = 0;
  for (int i = left; i <= right; i++){
    if (a[i] == element) {
      count++;
    }
  }
  return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[left];
  if (left > right) return -1;
  int mid = (left + right) / 2;
  int leftCnt = get_majority_element(a,left,mid);
  int rightCnt = get_majority_element(a,mid+1,right);
  if (leftCnt == -1 && rightCnt != -1){
    int num = cntHelper(a,left,right,rightCnt);
    if (num > (right - left + 1)/2){
      return rightCnt;
    }
    return -1;
  } else if (leftCnt != -1 && rightCnt == -1){
    int num = cntHelper(a,left,right,leftCnt);
    if (num > (right - left + 1)/2){
      return leftCnt;
    }
    return -1;
  } else if (leftCnt != -1 && rightCnt != -1){
    int leftnum = cntHelper(a,left,right,leftCnt);
    int rightnum = cntHelper(a,left,right,rightCnt);
    if (leftnum > (right - left + 1)/2){
      return leftCnt;
    } else if (rightnum > (right - left + 1)/2){
      return rightCnt;
    }
    return -1;
  }
  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
