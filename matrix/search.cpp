#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    // Edge case: if the matrix is empty, return false
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int m = matrix.size();
    int n = matrix[0].size();

    // Binary search to find the row containing the target value
    int left = 0;
    int right = m - 1;
    int row = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
            row = mid;
            break;
        } else if (matrix[mid][0] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // If no valid row is found
    if (row == -1) {
        return false;
    }

    // Binary search within the row to find the target
    left = 0;
    right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (matrix[row][mid] == target) {
            return true;
        } else if (matrix[row][mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    // Test cases
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    int target2 = 13;

    std::cout << "Searching for " << target1 << ": " << (searchMatrix(matrix, target1) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for " << target2 << ": " << (searchMatrix(matrix, target2) ? "Found" : "Not Found") << std::endl;

    return 0;
}
