#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        std::vector<std::vector<int>> ans(r, std::vector<int>(c));
        for (int i = 0; i < m * n; ++i) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};