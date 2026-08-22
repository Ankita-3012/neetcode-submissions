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
        int l = 0, r = n*m-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int row = mid/m, col = mid%m;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col]<target) l = mid+1;
            else if(matrix[row][col]>target) r = mid-1;
        }

        return false;
    }
};
