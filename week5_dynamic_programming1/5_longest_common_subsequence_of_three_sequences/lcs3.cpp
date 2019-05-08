#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  vector<vector<vector<int>>> dmatrix(a.size() + 1,vector<vector<int>>(b.size()+1,vector<int>(c.size()+1,0)));
  for (int i = 1; i < a.size() + 1; i++){
    for (int j = 1; j < b.size() + 1; j++){
      for (int k = 1; k < c.size() + 1; k++){
        int diff = (a[i-1] == b[j-1] && a[i-1] == c[k-1]) ? 1 : 0;
        int intermediate = std::max({dmatrix[i][j][k-1], dmatrix[i][j-1][k], dmatrix[i-1][j][k]});
        dmatrix[i][j][k] = std::max(dmatrix[i-1][j-1][k-1]+diff,intermediate);
      }
  }
  }
  return dmatrix[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
