class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int leftmax = height[l], rightmax = height[r];
        int tot_water = 0;
        while(l<r){
            if(leftmax < rightmax){
                l++;
                leftmax = max(leftmax, height[l]);
                tot_water += leftmax - height[l];
            }else{
                r--;
                rightmax = max(rightmax, height[r]);
                tot_water += rightmax - height[r];
            }
        }
        return tot_water;
    }
};
