class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int cnt_0 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) cnt_0++;
        }
        if(cnt_0>1) return ans;
        else if(cnt_0==1){
            int mul = 1, idx=-1;
            for(int i=0; i<n; i++){
                if(nums[i]!=0) mul*=nums[i];
                else idx = i;
            }
            ans[idx] = mul;
            return ans;
        }

        int mul = 1;
        for(int i=0; i<n; i++){
            mul *= nums[i];
        }

        for(int i=0; i<n; i++){
            ans[i] = mul/nums[i];
        }
        return ans;
    }
};
