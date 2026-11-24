class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> pascal(numRows);
        pascal[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            pascal[i].resize(i + 1);
            pascal[i][0] = 1;
            pascal[i][i] = 1; 
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal;
    }
};