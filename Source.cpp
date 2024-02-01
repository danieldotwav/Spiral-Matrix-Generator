#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main() {
	// Given an m x n matrix, return all elements of the matrix in spiral order.

	// Empty Matrix
	vector<vector<int>> matrix1 = {};
	vector<int> expected1 = {};
	cout << "Test Case 1: " << (spiralOrder(matrix1) == expected1 ? "Passed" : "Failed") << endl;
	
	// Single Element Matrix
	vector<vector<int>> matrix2 = { {1} };
	vector<int> expected2 = { 1 };
	cout << "Test Case 2: " << (spiralOrder(matrix2) == expected2 ? "Passed" : "Failed") << endl;

	// Single Row Matrix
	vector<vector<int>> matrix3 = { {1, 2, 3, 4} };
	vector<int> expected3 = { 1, 2, 3, 4 };
	cout << "Test Case 3: " << (spiralOrder(matrix3) == expected3 ? "Passed" : "Failed") << endl;

	// Single Column Matrix
	vector<vector<int>> matrix4 = { {1}, {2}, {3}, {4} };
	vector<int> expected4 = { 1, 2, 3, 4 };
	cout << "Test Case 4: " << (spiralOrder(matrix4) == expected4 ? "Passed" : "Failed") << endl;

	// Square Matrix
	vector<vector<int>> matrix5 = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
	};
	vector<int> expected5 = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };
	cout << "Test Case 5: " << (spiralOrder(matrix5) == expected5 ? "Passed" : "Failed") << endl;

	// Rectangular Matrix
	vector<vector<int>> matrix6 = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12}
	};
	vector<int> expected6 = { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 };
	cout << "Test Case 6: " << (spiralOrder(matrix6) == expected6 ? "Passed" : "Failed") << endl;

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