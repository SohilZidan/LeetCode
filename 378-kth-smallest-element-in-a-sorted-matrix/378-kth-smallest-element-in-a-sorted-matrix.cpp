class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> max_heap;
        for(size_t row = 0; row < matrix.size(); row++)
        {
            for(size_t col = 0; col < matrix[0].size(); col++)
            {
                max_heap.push(matrix[row][col]);
                if(max_heap.size() > k) max_heap.pop();
            }
        }
        return max_heap.top();
    }
};