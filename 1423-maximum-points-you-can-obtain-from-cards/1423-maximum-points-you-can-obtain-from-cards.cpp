class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalpts = accumulate(cardPoints.end()-k, cardPoints.end(), 0);
        // int leftpts = accumulate(cardPoints.begin()+k, cardPoints.end(), 0);
        int ans = totalpts;
        
        int n = cardPoints.size();
        // int leftout = n - k - 1;
        size_t tail = n - k, head = 0;
        // int cnt = n-k;
        // cout << n <<endl;
        // cout << k << endl;
        while(k-- > 0)
        {
            // cout << k << endl;
            
        // }
        // for(size_t tail = n - k; tail < n; tail++, head++)
        // {
            // cout<<totalpts<<endl;
            
            // cout<<to_string(head)<< ", "<<to_string(tail) <<endl;
            
            
            totalpts += cardPoints[head] - cardPoints[tail];
            // cout<<"before max" <<endl;
            ans = max(totalpts, ans);
            // cout<<ans<<endl;
            // cout << "----------" <<endl;
            tail++;
            head++;
        }
        return ans;
    }
};