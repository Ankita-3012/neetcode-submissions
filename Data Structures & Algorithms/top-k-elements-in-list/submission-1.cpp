class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        vector<pair<int, int>>  freq(mpp.begin(), mpp.end());
        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
