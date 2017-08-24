#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Rect { 
public: 
	int top; 
	int bottom;  
	int left;   
	int right; 
};
void helper(vector<vector<bool>> &image, int row, int col, Rect &rect) {
	if (row >= 0 && col >= 0 && row < image.size() && col < image[0].size()) {
		if (image[row][col] != false) {
			image[row][col] = false;
			rect.top = min(rect.top, row);
			rect.bottom = max(rect.bottom, row);
			rect.left = min(rect.left, col);
			rect.right = max(rect.right, col);
			helper(image, row - 1, col, rect);
			helper(image, row+1, col, rect);
			helper(image, row , col-1, rect);
			helper(image, row , col+1, rect);
			helper(image, row - 1, col-1, rect);
			helper(image, row + 1, col-1, rect);
			helper(image, row-1, col + 1, rect);
			helper(image, row+1, col + 1, rect);
		}
	}
	else {
		return;
	}
}
vector<Rect> findRects(vector<vector<bool>> image) {
	vector<Rect> res;
	for (int j = 0; j < image.size(); ++j) {
		for (int i = 0; i < image[0].size(); ++i) {
			if (image[j][i] != false) {
				Rect rect;
				rect.top = j;
				rect.bottom = j;
				rect.left = i;
				rect.right = i;
				helper(image, j, i, rect);
				res.push_back(rect);
			}
		}
	}
	return res;
}

int main3() {
	cout << "success" << endl;
	system("pause");
	return 0;
}