class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        
      
        vector<int> temp(n+1);
        for(int i=1;i<n+1;i++){
            temp[i]=nums[i-1];
        }
       
        unordered_map<long,long> mpp;
        int i=1;
         long long sum=0;
         mpp[0]=0;
        while(i%k!=0){
            sum+=temp[i];
            mpp[i]=sum;
             i++;
        }
        
      
        long long ans=LLONG_MIN;
        for(int i=k;i<n+1;i++){
            sum+=temp[i];
            ans=max(ans,sum-mpp[i%k]);
          
                if(mpp[i%k]>sum){
                    mpp[i%k]=sum;
                }
           
        }
        
        
        return ans;
    }
};