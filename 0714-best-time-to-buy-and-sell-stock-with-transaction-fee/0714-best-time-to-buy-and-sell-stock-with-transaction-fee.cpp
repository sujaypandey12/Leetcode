class Solution {
public:
    int helper(vector<int> & prices,int fee,int buy,int idx,vector<vector<int>> &dp){
        if(idx==prices.size())  return 0;
        long long profit1=0;
        long long profit2=0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
        profit1=max(-prices[idx]+helper(prices,fee,0,idx+1,dp),helper(prices,fee,1,idx+1,dp));
        }else{
        profit2=max(prices[idx]-fee+helper(prices,fee,1,idx+1,dp),helper(prices,fee,0,idx+1,dp));
        }
        return   dp[idx][buy]= max(profit1,profit2);

    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,fee,1,0,dp);
        
    }
};