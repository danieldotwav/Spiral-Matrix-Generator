## Introduction

This project implements a function to return all elements of a given m x n matrix in spiral order. It demonstrates the use of vector manipulation and control flow in C++ to traverse the matrix boundaries efficiently.

## Algorithms

### **1. Spiral Order Matrix Traversal**

#### Logic

- The algorithm initializes four boundaries (top, bottom, left, right) to traverse the outer perimeter of the matrix and gradually moves inward in a spiral manner. It checks for edge cases (e.g., empty matrix) and uses a loop to iterate over the matrix elements in the specified spiral order: from the top row, right column, bottom row, to the left column, sequentially adjusting the boundaries.

#### Complexity Analysis

- **Time Complexity:** O(M*N), where M is the number of rows and N is the number of columns in the matrix. Each element is visited exactly once.
- **Space Complexity:** O(1), disregarding the space used to store the result as it is required for the output. The algorithm uses a constant amount of space for variables.

### Code Snippet

```cpp
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
```

## Usage

To utilize this function, include it in your C++ project and invoke `spiralOrder` with a 2D vector (matrix) parameter. The function returns a vector containing the matrix elements in spiral order, which can be useful for various applications requiring matrix manipulation or data presentation in a specific sequence.

## Test Cases

The `main` function includes several test cases, ranging from empty matrices to rectangular and square matrices, demonstrating the versatility and correctness of the `spiralOrder` function. Users are encouraged to add more test cases to validate the function's behavior under different scenarios.

## Verification

After running the program, it prints the outcome of each test case to the console, indicating whether it passed or failed based on the expected output. This immediate feedback helps in quickly identifying any issues or edge cases that may not have been adequately addressed.

## Memory Management

The code utilizes standard C++ vectors, which automatically manage memory, ensuring that dynamically allocated memory is appropriately freed up when it's no longer needed, avoiding memory leaks.

## Conclusion

This project provides a robust solution for traversing and returning elements of a matrix in spiral order. It's designed for easy integration into larger projects and can be extended or modified to meet various requirements.