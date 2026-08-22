class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(n==1) return 1;
        int l = 0, r = 0;
        int maxi = 0, cnt = 0;
        while(r<n){
            bool poss = false;
            int duplicate_idx = -1;
            for(int i=l; i<r; i++){
                if(s[i]==s[r]){
                    poss = true;
                    duplicate_idx = i;
                    break;
                }
            }
            if(poss){
                l = duplicate_idx + 1;
                cnt = r - l + 1;
            }else{
                cnt = r-l+1;

            maxi = max(cnt, maxi);
            }
            r++;
        }
        return maxi;
    }
};
