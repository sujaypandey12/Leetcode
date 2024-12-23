class Solution {
public:
    int helper(vector<int> & prices,int idx,int buy,int cnt,vector<vector<vector<int>>> &dp){
        //base case
        if(cnt==0) return 0;
        if(idx==prices.size()){
          return 0;
        }
        int profit1=0;
        int profit2=0;
        if(dp[idx][buy][cnt]!=-1){
            return dp[idx][buy][cnt];
        }
        if(buy==1){
          profit1= max(-prices[idx]+helper(prices,idx+1,0,cnt,dp),helper(prices,idx+1,1,cnt,dp));
        }else{
    
        profit2= max(prices[idx]+helper(prices,idx+1,1,cnt-1,dp),helper(prices,idx+1,0,cnt,dp));
        }
        
        return dp[idx][buy][cnt]=max(profit1,profit2);

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return helper(prices,0,1,2,dp);
    }
};