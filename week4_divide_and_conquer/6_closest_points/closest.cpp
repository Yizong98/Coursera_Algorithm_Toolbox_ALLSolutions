#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <float.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Point {
  long long x, y;
};

struct Pair {
  Point x, y;
  float dist;
};

float calculate_distance(Point p1,Point p2){
  return sqrt(pow(((long long)p1.x - (long long)p2.x),2)+pow(((long long)p1.y - (long long)p2.y),2));
}
Pair best_split_pair(vector<Point> px, vector<Point> py, double delta, Pair curr_pair) {
  long long length_x = px.size();
  long long mid_x = px[length_x/2].x;
  vector<Point> in_between;
  for (Point x: py) {
    long long diff = abs(x.x - mid_x);
    if (diff < delta){
        in_between.push_back(x);
    }
  }
  long long between_size = in_between.size();
  for (long long i = 0; i < between_size - 1; i++){
    long long minimum = std::min((i + 7), between_size);
    for (long long j = i + 1; j < minimum; j++){
      Point temp1 = in_between[i];
      Point temp2 = in_between[j];
      float distance = calculate_distance(temp1,temp2);
      if (distance < delta){
        delta = distance;
        Pair temp_p;
        temp_p.x = temp1;
        temp_p.y = temp2;
        temp_p.dist = distance;
        curr_pair = temp_p;
      }
    }

  }
  return curr_pair;

}

Pair base_case(vector<Point> px){
  float dist = calculate_distance(px[0],px[1]);
  Point first = px[0];
  Point second = px[1];
  Pair result;
  result.x = first;
  result.y = second;
  result.dist = dist;
  long long length = px.size();
  if (length == 2){
    return result;
  }
  for (size_t i = 0; i < length - 1; i++){
    for (size_t j = i + 1; j < length; j++){
        float temp_d = calculate_distance(px[i],px[j]);
        if (temp_d < dist){
          dist = temp_d;
          result.dist = temp_d;
          result.x = px[i];
          result.y = px[j];
        }
    }
  }
  return result;

}

Pair best_pair(vector<Point> px, vector<Point> py){
  long long length = px.size();
  if (length <= 3){
    return base_case(px);
  }
  long long mid_p = length / 2;
  vector<Point> leftX = vector<Point>(px.begin(), px.begin() + mid_p);
  vector<Point> rightX = vector<Point>(px.begin()  + mid_p, px.end());
  long long mid_val = px[mid_p].x;
  vector<Point> leftY;
  vector<Point> rightY;
  for (Point x : py){
    if (x.x < mid_val){
      leftY.push_back(x);
    } else {
      rightY.push_back(x);
    }
  }
  // divide
  Pair leftP = best_pair(leftX,leftY);
  Pair rightP = best_pair(rightX,rightY);
  double smaller_part;
  Pair check;
  if (leftP.dist > rightP.dist){
    smaller_part = rightP.dist;
    check.x = rightP.x;
    check.y = rightP.y;
  } else {
    smaller_part = leftP.dist;
    check.x = leftP.x;
    check.y = leftP.y;
  }
  check.dist = smaller_part;

  Pair middle = best_split_pair(px,py,smaller_part,check);
  if (smaller_part <= middle.dist){
    return check;
  }
  return middle;

}

bool sortbyx(const Point &Pa, const Point &Pb){
  return Pa.x < Pb.x;
}

bool sortbyy(const Point &Pa, const Point &Pb){
    return Pa.y < Pb.y;
}

// 54788054 41270817 59290351 55312229 49267511 78474788 683268966 68186064 87348551 45450973 319520324 
// 726081442 409995535 103231927 361709773 558191765 665254350 228700096 492083367 178038328 183393329 456418222 
float minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  vector<Point> points;
  for (size_t i =0; i < x.size(); i++){
    // initialize point
    Point temp;
    temp.x = x[i];
    temp.y = y[i];
    points.push_back(temp);
  }
  vector<Point>  point_by_x(points);
  vector<Point>  point_by_y(points);
  // presorting
  sort(point_by_x.begin(), point_by_x.end(), sortbyx);
  sort(point_by_y.begin(), point_by_y.end(), sortbyy);
  Pair bestPair = best_pair(point_by_x,point_by_y);
  return bestPair.dist;
}


int main() {
  /*
  while(true){
    int n = rand()%(int)pow(10,5) + 2;
    std::cout << n << '\n';
    vector<int> x, y;
    Point P[n];
    for (size_t i = 0; i < n; i++) {
      int temp = rand()%((int)pow(10,9)-rand()%(int)pow(10,9));
      int tempx = rand()%((int)pow(10,9)-rand()%(int)pow(10,9));
      P[i].x = tempx;
      P[i].y = temp;
      x.push_back(tempx);//rand()%(int)pow(10,9)-rand()%(int)pow(10,9));
      y.push_back(temp);

    }
    double res1 = minimal_distance(x, y);
    double res2 = closest(P,n);
    if (res1 != res2){//!double_equals(res1,res2)){
      std::cout << "WRONG " << "\n";
      std::cout << "RES  " << res1 << " " << res2 << "\n";
      for (size_t i = 0; i < n; i++){
        std::cout << x[i] << " ";
      }
      std::cout << "\n" ;
      for (size_t i = 0; i < n; i++){
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
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
  //std::cout << std::setprecision(9) << closest(P, n) << "\n";
}
