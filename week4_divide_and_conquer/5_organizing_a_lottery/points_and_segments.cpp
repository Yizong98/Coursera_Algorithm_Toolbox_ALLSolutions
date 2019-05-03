#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::vector;
using std::string;
struct Segment {
  int value, index;
  string trait;
};

bool sortby(const Segment &segA, const Segment &segB){
  if (segA.value != segB.value) {
      return (segA.value < segB.value);
  }
  return segA.trait < segB.trait;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  vector<Segment> total;
  for (int index = 0; index < starts.size(); index++){
    Segment temp;
    temp.value = starts[index];
    temp.trait = "l";
    temp.index = index;
    total.push_back(temp);
  }
  for (int index = 0; index < ends.size(); index++){
    Segment temp;
    temp.value = ends[index];
    temp.trait = "r";
    temp.index = index;
    total.push_back(temp);
  }
  for (int index = 0; index < points.size(); index++){
    Segment temp;
    temp.value = points[index];
    temp.trait = "p";
    temp.index = index;
    total.push_back(temp);
  }
  sort(total.begin(), total.end(), sortby);
  int tracker = 0;
  for (int index = 0; index < total.size(); index++){
    if (total[index].trait == "l"){
      tracker++;
    } else if(total[index].trait == "r"){
      tracker--;
    } else{
      cnt[total[index].index] = tracker;
    }
  }
  //write your code here
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  /*
  while(true){
    int n = rand()%10;
    std::cout << n << '\n';
    int m = rand()%10;
    std::cout << m << '\n';
    vector<int> starts, ends;
    for (size_t i = 0; i < n; i++) {
      int temp = rand()%5;
      starts.push_back(temp);
      ends.push_back(temp + rand()%5);
    }
    std::cout << "HELLO" << '\n';
    for (size_t i = 0; i < starts.size(); i++) {
      std::cout << starts[i] << " END: " << ends[i] << ' ';
    }
    std::cout << "\n";
    int p = rand()%10;
    vector<int> points;
    for (size_t i = 0; i < p; i++) {
      points.push_back(rand()%5- rand()%5);
    }
    for (size_t i = 0; i < points.size(); i++) {
      std::cout << points[i] << ' ';
    }
    std::cout << "\n";
    vector<int> res1 = fast_count_segments(starts, ends, points);
    vector<int> res2 = naive_count_segments(starts, ends, points);
    if (res1 != res2){
      std::cout << "WRONG " << "\n";
      for (size_t i = 0; i < res1.size(); i++) {
        std::cout << res1[i] << " NAIVE: " << res2[i] << ' ';
      }
      break;
    } else {
      std::cout << "OK \n" ;
    }
  }
  */
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
