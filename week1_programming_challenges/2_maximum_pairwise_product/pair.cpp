#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

long long findMax(int i,int j,const vector<int>& numbers,int total) {
	if (i == j) {
		vector<int> tracker(total,0);
		tracker[0] = 1;
		tracker[1] = numbers[i];
		return tracker;
	}
	compare1 = findMax(i,i+(j-i)/2,numbers,total);
	compare2 = findMax(i+(j-i)/2+1,j,numbers,total);

	if (compare1[1] > compare2[1]){
		compare1[0] += 1;
		compare1[compare1[0]]  = compare2[1];
		return compare1;
	} else {
		compare2[0] += 1;
		compare2[compare2[0]]  = compare1[1];
		return compare2;
	}


}


long long solution(int total, const vector<int>& numbers){
	compare1 = findMax(1,total,numbers,total)
	compare2 = findMax(2,compare1[0],numbers,total)
	return compare2[1] * compare1[1]
}

int main() { 
	int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << solution(n,numbers); << "\n";
    return 0;
}

