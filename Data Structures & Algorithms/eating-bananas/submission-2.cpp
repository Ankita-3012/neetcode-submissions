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

        int l=1, r=maxi;
        int ans = maxi;
        while(l<=r){
            int mid = l+(r-l)/2;
            long long time = calcHour(piles, mid);
            if(time<=h){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
