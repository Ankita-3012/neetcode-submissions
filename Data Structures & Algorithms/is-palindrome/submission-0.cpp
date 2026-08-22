class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        for(char c : s){
            if(isalnum(c)) st += tolower(c);
        }

        string rev = st;
        reverse(rev.begin(), rev.end());

        if(st == rev) return true;
        return false;
    }
};
