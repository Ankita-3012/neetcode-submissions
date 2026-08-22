class Solution {
private:
    int OFFSET = 1000;
    int helper(int ind, int currt, vector<int> & nums, vector<vector<int>>& dp){
        if(ind < 0) return currt == 0? 1:0;
        if(dp[ind][currt + OFFSET] != -1) return dp[ind][currt+OFFSET];

        int add_take = helper(ind-1, currt - nums[ind], nums, dp);
        int sub_take = helper(ind-1, nums[ind]+currt, nums, dp);
        
        return dp[ind][currt+OFFSET] = add_take + sub_take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return helper(n-1, target, nums, dp);
    }
};
