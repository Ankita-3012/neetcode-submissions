class Solution {
public:
    bool isAnagram(string s, string t) {
      map<int, int> mpp1, mpp2;
      int n = s.size(), m = t.size();
      if(n!=m) return false;
      for(int i=0; i<n; i++){
        mpp1[s[i]]++;
      }
      for(char c : t){
        mpp2[c]++;
      }
      for(char c: t){
        if(mpp1[c] != mpp2[c]) return false;
      }
      return true;
    }
};
