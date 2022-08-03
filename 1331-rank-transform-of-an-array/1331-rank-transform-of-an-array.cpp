class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        auto a = arr;
        sort(a.begin(), a.end());
        
        unordered_map<int, int> rank;
        int acc_rank = 1;
        for(size_t i = 0; i < a.size(); i++)
        {
            if(rank.find(a[i]) == rank.end())
                rank[a[i]] = acc_rank++;
        }
            
        
        for(size_t i = 0; i < arr.size(); i++) a[i] = rank[arr[i]];
        
        return a;
    }
};