class Solution {
public:
     
    int helper(vector<int> & prices,int idx,int buy,vector<vector<int>> &dp){
        if(idx>=prices.size())  return 0;
        int profit1=0;
        int profit2=0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
          profit1=max(-prices[idx]+helper(prices,idx+1,0,dp),helper(prices,idx+1,1,dp));
        }else{
            profit2=max(prices[idx]+helper(prices,idx+2,1,dp),helper(prices,idx+1,0,dp));
        }
        return dp[idx][buy]=max(profit1,profit2);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(prices,0,1,dp);
        
    }
};