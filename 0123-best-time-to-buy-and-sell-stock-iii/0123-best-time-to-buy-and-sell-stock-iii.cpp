class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>> (2,vector<long long>(3,0)));
        //try to cover the first test case
       
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j==1){
                        dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }else{
                        dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];

    }
};