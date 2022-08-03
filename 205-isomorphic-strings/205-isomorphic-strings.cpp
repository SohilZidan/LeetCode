class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> replacedby;
        unordered_map<char,char> replace;
        for (string::size_type i = 0; i < s.size(); i++) {
            if( replacedby.find(s[i]) != replacedby.end() )
            {
                if(replacedby[s[i]] == t[i]) continue;
                else
                    return false;
            }
            if( replace.find(t[i]) != replace.end() )
            {
                if(replace[t[i]] == s[i]) continue;
                else
                    return false;
            }
            replacedby[s[i]] = t[i];
            replace[t[i]] = s[i];
        }
        return true;
    }
};