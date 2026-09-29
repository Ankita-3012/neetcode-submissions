class TimeMap {
public:
    unordered_map<string, unordered_map<int, vector<string>>> mpp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end()) return "";
        int seen = -1;
        for(auto& [t, val] : mpp[key]){
            if(t<=timestamp){
                seen = max(t, seen);
            }
        }

        return seen == -1? "":mpp[key][seen].back();
    }
};
