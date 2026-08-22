class Solution {
private:
    int helper(int ind, int currt, vector<int> & nums){
        if(ind < 0) return currt == 0? 1:0;

        int add_take = helper(ind-1, currt - nums[ind], nums);
        int sub_take = helper(ind-1, nums[ind]+currt, nums);
        
        return add_take + sub_take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        return helper(n-1, target, nums);
    }
};
