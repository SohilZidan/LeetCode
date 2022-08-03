class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> char_pos(26);
        for(size_t pos = 0; pos < t.size(); pos++) char_pos[t[pos]-'a'].push_back(pos);

        int last_idx = -1;
        for(char c: s)
        {
            auto iter = upper_bound(char_pos[c-'a'].begin(), char_pos[c-'a'].end(), last_idx);
            if(iter == char_pos[c-'a'].end()) return false;
            last_idx = *iter;
        }
        return true;
    }
};