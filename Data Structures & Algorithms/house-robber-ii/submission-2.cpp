class Solution {
private:
    int helper(vector<int>& nums){
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }

        return dp[nums.size()-1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> v1, v2;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i!=n-1) v1.push_back(nums[i]);
            if(i!=0) v2.push_back(nums[i]); 
        }

        return max(helper(v1), helper(v2));
    }
};
