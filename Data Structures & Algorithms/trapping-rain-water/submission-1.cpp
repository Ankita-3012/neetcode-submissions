class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int tot_water = 0;
        for(int i=0; i<n; i++){
            int lmax = height[i], rmax = height[i];
            for(int j=0; j<i; j++){
                lmax = max(lmax, height[j]);
            }
            for(int j=i+1; j<n; j++){
                rmax = max(rmax, height[j]);
            }

            tot_water += min(lmax, rmax) - height[i];
        }
        return tot_water;
    }
};
