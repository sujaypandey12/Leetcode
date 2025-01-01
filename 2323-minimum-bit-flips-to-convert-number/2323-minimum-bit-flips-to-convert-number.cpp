class Solution {
public:
    int minBitFlips(int start, int goal) {
        int y=start^goal;
        int cnt=0;
        while(y!=0) {
            y=y&(y-1);
            cnt++;
        } 
        return cnt;
  }
};