#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &hash, int m, int sum,int &res,int start) {
	if (sum > m) return;
	if (sum == m) { ++res; return; }
	for (int i = start; i < 17; ++i) {
		helper(hash, m, sum + hash[i], res, i);
	}
}

int func(int m) {
	vector<int> hash(17, 0);
	for (int i = 1; i <= 17; ++i)
		hash[i - 1] = i*i;
	int res = 0;
	for (int i = 0; i < 17 && hash[i] < m; ++i)
		helper(hash, m, hash[i], res,i);
	return res;
}
int main2() {
	int m;
	cin >> m;
	cout << func(m) << endl;
	system("pause");
	return 0;
}