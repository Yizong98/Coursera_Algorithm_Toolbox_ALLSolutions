#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  const int MAX = 101;
  vector<vector<int>> matrix;
  for (int i = 0; i < a.size() + 1; i++){
    matrix.push_back(vector<int> {});
    for (int j = 0; j < b.size() + 1 ; j++){
      matrix[i].push_back(MAX);
    }
  }
  for (int i = 0; i < a.size() + 1; i++){
    matrix[i][0] = 0;
  }
  for (int j = 0; j < b.size() + 1; j++){
    matrix[0][j] = 0;
  }
  for (int i = 1; i < a.size() + 1; i++){
    for (int j = 1; j < b.size() + 1; j++){
      int diff = (a[i-1] == b[j-1]) ? 1 : 0;
      matrix[i][j] = std::max({matrix[i-1][j-1]+diff, matrix[i][j-1], matrix[i-1][j]});
  }
  }
  return matrix[a.size()][b.size()];
}

int main() {
  /*
  while(true){
    int n = rand()%5+1;
    int m = rand()%5+1;
    std::cout << n << '\n';
    std::cout << m << '\n';
    vector<int> x, y;
    for (size_t i = 0; i < n; i++) {
      int temp = rand()%5;
      x.push_back(temp);//rand()%(int)pow(10,9)-rand()%(int)pow(10,9));
    }
    for (size_t i = 0; i < m; i++) {
      int temp = rand()%5;
      y.push_back(temp);//rand()%(int)pow(10,9)-rand()%(int)pow(10,9));
    }
    int res1 = lcs2a(x, y);
    int res2 = lcs2(x,y);
    if (res1 != res2){//!double_equals(res1,res2)){
      std::cout << "WRONG " << "\n";
      std::cout << "RES  " << res1 << " " << res2 << "\n";
      for (size_t i = 0; i < n; i++){
        std::cout << x[i] << " ";
      }
      std::cout << "\n" ;
      for (size_t i = 0; i < m; i++){
        std::cout << y[i] << " ";
      }
      std::cout << "\n" ;
      break;
    } else {
      std::cout << "OK \n" ;
    }
  }
  */
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
