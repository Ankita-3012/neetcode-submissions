class Solution {
private:
    int dfs(vector<int>& nums, int i, vector<int>& dp){
        if(i == 0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i] + dfs(nums, i-2, dp);
        int not_pick = dfs(nums, i-1, dp);

        return dp[i] = max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> v1, v2;
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp1(n-1, -1), dp2(n-1, -1);
        for(int i=0; i<n; i++){
            if(i!=n-1) v1.push_back(nums[i]);
            if(i!=0) v2.push_back(nums[i]); 
        }

        return max(dfs(v1, n-2, dp1), dfs(v2, n-2, dp2));
    }
};
