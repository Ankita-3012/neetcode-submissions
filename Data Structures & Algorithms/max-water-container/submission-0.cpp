class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int low = 0, high = n-1;
        int b = n-1;
        int h = min(heights[low], heights[high]);
        int ar = b*h;
        while(low<high){
            if(heights[low]<heights[high]) low++;
            else if(heights[low]>=heights[high]) high--;

            int nh = min(heights[low], heights[high]);
            int nb = high - low;
            int nar = nh*nb;
            ar = max(ar, nar);
        }

        return ar;
    }
};
