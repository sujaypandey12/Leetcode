class Solution {
public:
    int helper(vector<int> & prices,int idx,int buy,vector<vector<int>> &dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
           return dp[idx][buy]=max(-prices[idx]+helper(prices,idx+1,0,dp),helper(prices,idx+1,1,dp));
        }else{
            return dp[idx][buy]=max(prices[idx]+helper(prices,idx+1,1,dp),helper(prices,idx+1,0,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(prices,0,1,dp);
    }
};