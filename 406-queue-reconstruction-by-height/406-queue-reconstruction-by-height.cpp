class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return (a[0]==b[0])?(a[1]<b[1]):a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++)
        {
            res.insert(res.begin()+people[i][1], people[i]);
        }
        return res;
    }
};