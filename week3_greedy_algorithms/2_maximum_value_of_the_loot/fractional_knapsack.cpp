#include <iostream>
#include <vector>
#include <tuple>
#include<algorithm>
#include <unordered_map>
using std::vector;
using std::tuple;
using std::get;
using std::make_tuple;
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<tuple<double, int>> tuple_list;
  for (int i = 0; i < values.size(); ++i) {
    tuple_list.push_back(make_tuple((double)values[i]/weights[i],weights[i]));
  }
  sort(tuple_list.begin(), tuple_list.end()); 
  int agg = 0;
  vector<int> track(values.size());
  for (int i = tuple_list.size()-1; i > -1; i--){
    while(agg <= capacity && track[i] <= get<1>(tuple_list[i])){
      if (agg == capacity || track[i] == get<1>(tuple_list[i])) {
        break;
      }
      track[i]++;
      agg++;
      value += get<0>(tuple_list[i]);
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
