#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSum(vector<int> vecs) {
	int Max = INT_MIN;
	int sum = 0;
	for (auto &vec : vecs) {
		sum = sum + vec > 0 ? sum + vec : 0;
		if (sum > Max) Max = sum;
	}
	return Max;
}
int findMaxSum(vector<vector<int>> mat) {
	int res = INT_MIN;
	for (int i = 0; i < mat.size(); ++i)
		res = max(res, maxSum(mat[i]));
	return res;
}

int main4() {
	cout << "success" << endl;
	return 0;
}