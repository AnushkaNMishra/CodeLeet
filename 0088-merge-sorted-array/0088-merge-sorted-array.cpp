class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=0;i<nums1.size();i++){
            if(i>=m){
                for(int j=0;j<nums2.size();j++){
                    nums1[i]=nums2[j];
                    i++;
                    
                    if(j>=n){
                        break;
                    }
                }
                
            }
        }
        sort(nums1.begin(),nums1.end());
        
    }
};