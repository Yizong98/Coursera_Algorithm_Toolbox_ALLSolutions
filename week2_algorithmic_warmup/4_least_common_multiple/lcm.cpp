#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
  if (b == 0){
    return a;
  }
  int a_prime = a % b;
  // 18 17 --> 17, 1 --> 1,0
  return gcd_fast(b,a_prime);

}

long long lcm_fast(int a, int b){
	int gcd = gcd_fast(a,b);
	return ((long long) a) * b / gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
