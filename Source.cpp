#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main() {
	// Given an m x n matrix, return all elements of the matrix in spiral order.
	return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	// Edge Cases
	if (matrix.empty()) { return {}; }

	// Boundaries
	int top = 0;
	int bottom = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;

	// Store spiral numbers in vector
	vector<int> spiralVec;

	// Traverse the matrix in a spiral
	while (top <= bottom && left <= right) {
		// Begin from the top left to top right
		for (int i = left; i <= right && top <= bottom; ++i) {
			spiralVec.push_back(matrix[top][i]);
		}
		++top;

		// Then, traverse the rightmost column, from the updated top boundary to the bottom boundary
		for (int i = top; i <= bottom && left <= right; ++i) {
			spiralVec.push_back(matrix[i][right]);
		}
		--right;

		// Now, traverse the bottom row, right to left
		for (int i = right; i >= left && top <= bottom; --i) {
			spiralVec.push_back(matrix[bottom][i]);
		}
		--bottom;

		// Finally, traverse the left column
		for (int i = bottom; i >= top && left <= right; --i) {
			spiralVec.push_back(matrix[i][left]);
		}
		++left;
	}

	return spiralVec;
}