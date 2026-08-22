class Solution {
    bool binarySearch(vector<int>& nums, int t){
        int n = nums.size();
        int l = 0, h = n-1;
        while(l<=h){
            int mid = l + ((h-l)/2);
            if(nums[mid] == t) return true;
            else if(nums[mid]<t) l = mid+1;
            else h = mid-1;

        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            if(binarySearch(matrix[i], target)) return true;
        }
        return false;
    }
};
