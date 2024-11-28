class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        cout<<sum<<endl;
        if(sum%2==1){
            return false;
        }else{
            int target=sum/2;
             vector<bool> prev(target+1,0);
             prev[0]=true;
             if(nums[0]>target){
                return false;
             }
             prev[nums[0]]=true;
           
             for(int i=1;i<n;i++){
                vector<bool> curr(target+1,0);
                curr[0]=true;   
                for(int k=1;k<=target;k++){
                  bool nottake=prev[k];
                  bool take=false;
                  if(nums[i]<=k){   
                    take=prev[k-nums[i]];
                  }
                  curr[k]=take || nottake;
                }
                prev=curr;
             }
             return prev[target];
             

        }
    }
};