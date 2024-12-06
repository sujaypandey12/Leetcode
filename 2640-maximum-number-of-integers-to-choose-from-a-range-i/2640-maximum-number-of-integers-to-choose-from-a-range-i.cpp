class Solution {
public:
   

    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int> bannedSet(banned.begin(), banned.end());

        vector<int> validNumbers;
        for (int i = 1; i <= n; i++) {
            if (bannedSet.find(i) == bannedSet.end()) {
                validNumbers.push_back(i);
            }
        }

        sort(validNumbers.begin(), validNumbers.end());
        int m=validNumbers.size();
         int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            int sum=validNumbers[i];
           for(int j=i+1;j<m;j++){
            sum+=validNumbers[j];
            if(sum<=maxSum){
            maxi=max(maxi,j-i+1);
           }
       
           }
        }
        if(maxi==INT_MIN) return 0;
        return maxi;
    }
};
