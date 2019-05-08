#include <iostream>
#include <vector>
using std::vector;
int get_change(int m) {
	//write your code here
	vector<int> coins_number{0};
	vector<int> coins{1,3,4};
	for (int i = 1; i <= m; i++){
		coins_number.push_back(1001);
		for (int coin:coins){
			if (i >= coin){
				int minimum = coins_number[i-coin] + 1;
				if (minimum < coins_number[i]){
					coins_number[i] = minimum;
				}
			}
		}
	}
  return coins_number[coins_number.size()-1];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
