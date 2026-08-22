class Solution {
public:
    long long calcHour(vector<int>& piles, int t){
        long long hrs = 0;
        for(int banana : piles) hrs += (banana + t - 1)/t;

        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for(int i : piles) maxi = max(maxi, i);

        for(int i=1; i<=maxi; i++){
            long long time = calcHour(piles, i);
            if(time<=h) return i;
        }
        return maxi;
    }
};
