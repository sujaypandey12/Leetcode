class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mpp;
        int n=intervals.size();
        int cnt=1;

        for(int i=0;i<n;i++){
             int start=intervals[i][0];
             int end=intervals[i][1];
             mpp[start]++;
             mpp[end+1]--;
        }
        int sum=0;
        int maxi=1;
        for(auto & it:mpp){
            sum+=(it.second);
            maxi=max(maxi,sum);
          
        }
        return maxi;
    }
};