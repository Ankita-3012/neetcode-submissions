class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = (n1+n2)/2;
        int prev = 0, curr = 0;
        int i=0, j=0;
        for(int cnt = 0; cnt<n+1; cnt++){
            prev = curr;
            if(i<n1 && j<n2){
                if(nums1[i]<nums2[j]){
                    curr = nums1[i];
                    i++;
                }else{
                    curr = nums2[j];
                    j++;
                }
            }else if(i<n1){
                curr = nums1[i];
                i++;
            }else{
                curr = nums2[j];
                j++;
            }
        }

        if((n1+n2)%2 == 0){
            return (double)(prev+curr)/2.0;
        }
        return (double)curr;
    }
};
