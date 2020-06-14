class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m+n-1; i>=0 && n >0; i--) 
            nums1[i] = m < 1 ? nums2[--n] : nums1[m-1] > nums2[n-1] ? nums1[--m] : nums2[--n]; 

    }
};
