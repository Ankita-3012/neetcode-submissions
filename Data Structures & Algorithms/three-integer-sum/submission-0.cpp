class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> v = {nums[i], nums[j], nums[k]};
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                }
            }
        }

        for(auto it:st){
            ans.push_back(it);
        }

        return ans;
    }
};
