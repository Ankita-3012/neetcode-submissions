class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(string s : strs){
            int len = s.length();
            str += to_string(len)+"/:"+s;
        }
        return str;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.size()){
            int len = 0;
            while(isdigit(s[i])){
                len = len*10 + (s[i]-'0');
                i++;
            }

            if(s[i] == '/') i++;
            if(s[i] == ':') i++;

            string st = s.substr(i, len);
            ans.push_back(st);
            i += len;
        }
        return ans;
    }
};
