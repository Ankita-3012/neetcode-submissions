class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, r=0;
        int len = 0, maxf=0;
        map<char, int> mpp;
        while(r<n){
            mpp[s[r]]++;
            maxf = max(maxf, mpp[s[r]]);
            int rep = (r-l+1)-maxf;
            if(rep>k){
                mpp[s[l]]--;
                maxf = 0;
                for(auto it : mpp){
                    maxf = max(maxf, it.second);
                }
                l++;
            }
            else if(rep<=k) len = max(r-l+1, len);
            r++;
        }
        return len;
    }
};
