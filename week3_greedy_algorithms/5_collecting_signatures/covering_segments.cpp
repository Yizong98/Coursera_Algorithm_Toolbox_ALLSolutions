#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

// ALGO: sort by end, while loop(until not finished), start from min end, if next.end >= min end >= next.start, ignore, pass, if not
// update next, try again

bool sortby(const Segment &segA, const Segment &segB){
  return (segA.end < segB.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(), segments.end(), sortby); 
  int start = 0;
  int cnt = 0;
  while (start < segments.size()){
    int temp = start;
    points.push_back(segments[start].end);
    while ((temp < segments.size() - 1) && (segments[start].end >= segments[temp+1].start)){
      temp++;
    }
    if (temp < segments.size() - 1){
      start = temp+1;
    } else {
      break;
    }

  }
  //for (size_t i = 0; i < segments.size(); ++i) { 1 3 1 2 4 5 --> (1 2) (1 3) (4 5)  
    //points.push_back(segments[i].start);
    //points.push_back(segments[i].end);
  //}
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
