class Solution {
public:
    vector<int> base_case = {1};
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back(base_case);
        for(int row = 1; row < numRows; row++){
            vector<int> row_values(row+1, 1);
            for(int col = 1; col < row; col++)
            {
                row_values.at(col) = res.at(row-1).at(col-1) + res.at(row-1).at(col);
            }
            res.push_back(row_values);
        }
        return res;
    }
};