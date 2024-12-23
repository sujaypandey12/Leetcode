class Solution {
public:
    int helper(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp) {
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        if (buy) {
            return dp[idx][buy] =
                       max(-prices[idx] + helper(prices, idx + 1, 0, dp),
                           helper(prices, idx + 1, 1, dp));
        } else {
            return dp[idx][buy] =
                       max(prices[idx] + helper(prices, idx + 1, 1, dp),
                           helper(prices, idx + 1, 0, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j == 1) {
                    dp[i][j] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    dp[i][j] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
    };