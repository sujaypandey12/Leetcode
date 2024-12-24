class Solution {
public:
    int helper(vector<int> & prices,int idx,int buy,int k,vector<vector<vector<int>>> &dp){
        if(idx==prices.size() || k==0){
            return 0;
        }
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        int profit1=0;
        int profit2=0;
        if(buy){
            profit1=max(-prices[idx]+helper(prices,idx+1,0,k,dp),helper(prices,idx+1,1,k,dp));
        }else{
            profit2=max(prices[idx]+helper(prices,idx+1,1,k-1,dp),helper(prices,idx+1,0,k,dp));
        }
        return  dp[idx][buy][k]=max(profit1,profit2);

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(prices,0,1,k,dp);
        
    }
};