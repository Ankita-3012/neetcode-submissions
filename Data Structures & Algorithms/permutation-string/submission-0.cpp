class Solution {
private:
    bool isperm(string st1, string st2){
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());
        return st1 == st2;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n>m) return false;

        int l=0, r=n-1;
        while(r<m){
            if(isperm(s1, s2.substr(l, r-l+1))) return true;
            l++;
            r++;
        }
        return false;
    }
};
