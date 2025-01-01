class Solution {
public:
    int minBitFlips(int start, int goal) {
        int y=start^goal;
        return __builtin_popcount(y);
    }
};