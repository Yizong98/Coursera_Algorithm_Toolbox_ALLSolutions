#include <iostream>
// 3, 9 18 3
// 6, 18, 18, 0 
// gcd(6,18) --> gcd(6/18) -- > 6 

// LCD Algo : find gcd, while loop, condition: while not divide both a and b, keep iterating n * gcd
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if (b == 0){
    return a;
  }
  int a_prime = a % b;
  // 18 17 --> 17, 1 --> 1,0
  return gcd_fast(b,a_prime);

}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
