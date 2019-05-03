#include <iostream>

// safe mode: choose 10 first if not filled up, then 5, 1 

int get_change(int m) {
	//write your code here
	int n = 0;
	int agg = 0;
	while (agg+10<=m){
		n++;
		agg+=10;
	}
	while (agg+5<=m){
		n++;
		agg+=5;
	}
	while (agg+1<=m){
		n++;
		agg+=1;
	}
	return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

