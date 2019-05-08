#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  const int MAX = 1000000;
  vector<int> operations{2,3};
  vector<int> matrix{-1,0};
  vector<int> previous{-1,1};
  for (int i = 2; i <= n; i++){
    matrix.push_back(i);
    previous.push_back(MAX);
    for (int operation:operations){
      if (i % operation == 0){
        int minimum = matrix[i/operation] + 1;
        if (minimum < matrix[i]){
          matrix[i] = minimum;
          previous[i] = i/operation;
        }
      }
    }
    
    int minimum = matrix[i-1] + 1;
    if (minimum < matrix[i]){
      matrix[i] = minimum;
      previous[i] = i-1;
    }
    

  }
  vector<int> path{n};
  int track = n;
  while(track != 1 && previous.size()>2){
    path.push_back(previous[track]);
    track = previous[track];
  }
  std::reverse(path.begin(),path.end());
  return path;
}

// 7: 
// 3 6 8
// 22: 
// 99: 1 3 9 27 81 + 18


int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
