class Solution {
private:
    int f(vector<int> & cost, int i, vector<int>& dp){
        if(i>=cost.size()) return 0;

        if(dp[i]!=0) return dp[i];

        return dp[i] = cost[i]+min(f(cost, i+1, dp), f(cost, i+2, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        return min(f(cost, 0, dp), f(cost, 1, dp));
    }
};
