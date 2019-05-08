#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
	const int MAX = 101;
	vector<vector<int>> matrix;
	for (int i = 0; i < str1.size() + 1; i++){
		matrix.push_back(vector<int> {});
		for (int j = 0; j < str2.size() + 1 ; j++){
			matrix[i].push_back(MAX);
		}
	}
	for (int i = 0; i < str1.size() + 1; i++){
		matrix[i][0] = i;
	}
	for (int j = 0; j < str2.size() + 1; j++){
		matrix[0][j] = j;
	}
	for (int i = 1; i < str1.size() + 1; i++){
		for (int j = 1; j < str2.size() + 1; j++){
			int diff = (str1[i-1] != str2[j-1]) ? 1 : 0;
			matrix[i][j] = std::min({matrix[i-1][j-1]+diff, matrix[i][j-1]+1, matrix[i-1][j]+1});
	}
	}
	return matrix[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
