class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int n = s.size(), cnt = t.size();
        if(cnt > n) return ans;
        int l=0, r=0;
        int minlen = INT_MAX;
        int start = 0;
        map<char, int> mpp;
        for(char c : t) mpp[c]++;
        while(r<n){
            if(mpp[s[r]]>0){
                cnt--;
            }
            mpp[s[r]]--;

            while(cnt == 0){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    start = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt++;

                l++;
            }
            r++;
        }

        if(minlen == INT_MAX) return "";
        return s.substr(start, minlen);
    }
};
