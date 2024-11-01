#include <iostream>
#include <vector>
#include <vector>
#include <unordered_map>

class Solution { 
public:

    std::vector<std::vector<int>> multiply1(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
        int m = mat1.size(), n = mat2[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        // vector of vector of pairs
        auto g1 = preprocess1(mat1), g2 = preprocess1(mat2);
        for (int i = 0; i < m; ++i) {
            for (auto& [k, x] : g1[i]) {
                for (auto& [j, y] : g2[k]) {
                    ans[i][j] += x * y;
                }
            }
        }
        return ans;
    }

    std::vector<std::vector<int>> multiply2(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
        int m = mat1.size(), n = mat2[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));

        // map of map
        auto g1 = preprocess2(mat1);
        auto g2 = preprocess2(mat2);

        for (int i = 0; i < m; ++i) {
            if (g1.find(i) != g1.end()) {
                for (const auto& [k, x] : g1[i]) {
                    if (g2.find(k) != g2.end()) {
                        for (const auto& [j, y] : g2[k]) {
                            ans[i][j] += x * y;
                        }
                    }
                }
            }
        }

        return ans;
    }

    std::vector<std::vector<int>> multiply3(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
        int m = mat1.size(), n = mat2[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));

        // map of vector of pairs
        auto g1 = preprocess3(mat1);
        auto g2 = preprocess3(mat2);

        for (int i = 0; i < m; ++i) {
            if (g1.find(i) != g1.end()) {
                for (const auto& [k, x] : g1[i]) {
                    if (g2.find(k) != g2.end()) {
                        for (const auto& [j, y] : g2[k]) {
                            ans[i][j] += x * y;
                        }
                    }
                }
            }
        }

        return ans;
    }


private:

    std::vector<std::vector<std::pair<int, int>>> preprocess1(std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::vector<std::pair<int, int>>> g(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    g[i].emplace_back(j, mat[i][j]);
                }
            }
        }
        return g;
    }
    
    // Preprocessing function that uses unordered_map for sparse storage
    std::unordered_map<int, std::unordered_map<int, int>> preprocess2(std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        std::unordered_map<int, std::unordered_map<int, int>> map;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != 0) {
                    map[i][j] = mat[i][j];  
                }
            }
        }
        
        return map;
    }

    std::unordered_map<int, std::vector<std::pair<int, int>>> preprocess3(std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        std::unordered_map<int, std::vector<std::pair<int, int>>> map;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != 0) {
                    map[i].emplace_back(j, mat[i][j]); 
                }
            }
        }

        return map;
    }

};


// Function to print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Test case
int main() {
    Solution solution;

    // Define matrices mat1 and mat2
    std::vector<std::vector<int>> mat1 = {
        {1, 0},
        {0, 2},
        {3, 0}
    };

    std::vector<std::vector<int>> mat2 = {
        {0, 4, 0},
        {2, 0, 6}
    };

    // Perform multiplication
    std::vector<std::vector<int>> result = solution.multiply1(mat1, mat2);

    // Print result
    std::cout << "Result of mat1 * mat2:" << std::endl;
    printMatrix(result);

    return 0;
}
