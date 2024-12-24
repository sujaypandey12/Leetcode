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
      //  vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
       // return helper(prices,0,1,k,dp);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // i am not going to make changes to base case as i alreasy inttilised woth 0
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int t=1;t<=k;t++){
                    if(j==1){
                        dp[i][j][t]=max(-prices[i]+dp[i+1][0][t],dp[i+1][1][t]);
                    }else{
                        dp[i][j][t]=max(prices[i]+dp[i+1][1][t-1],dp[i+1][0][t]);
                    }
                }
            }
        }
        return dp[0][1][k];

        
    }
};