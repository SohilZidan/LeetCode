class Solution {
public:
    vector<int> base_case = {1};
    vector<int> getRow(int rowIndex){
        vector<vector<int>> res;
        res.push_back(base_case);
        for(int row = 1; row <= rowIndex; row++){
            vector<int> row_values(row+1, 1);
            for(int col = 1; col < row; col++)
                row_values.at(col) = res.at(0).at(col-1) + res.at(0).at(col);
            // pop then push
            res.pop_back();
            res.push_back(row_values);
        }
        return res.back();
    }
};