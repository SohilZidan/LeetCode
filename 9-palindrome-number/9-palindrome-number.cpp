class Solution {
public:
    bool isPalindrome(int x) {
        string x_str = to_string(x);
        int length = x_str.size();
        
        for(int i=0; i < ceil(length/2.0); i++)
        {
            if(x_str[i] != x_str[length-1-i]) return false;
        }
        return true;
    }
};