class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v(2,-1);
        int l=0, r=nums.size()-1;
        
        //for first occurence
        while(l<=r){
            int mid= l + (r-l)/2;
        
            if(nums[mid]<target){
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                if(mid==0 || nums[mid]!=nums[mid-1]){
                    v[0]=mid;
                    break;
                }
                else{
                    r=mid-1;
                    v[0]=mid-1;
                }
            }
        }
        // for last occurence
         l=0, r=nums.size()-1;
         while(l<=r){
            int mid= l + (r-l)/2;
        
            if(nums[mid]<target){
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                if(mid==nums.size()-1 || nums[mid]!=nums[mid+1]){
                    v[1]=mid;
                    break;
                }
                else{
                    l=mid+1;
                    v[1]=mid+1;
                }
            }
        }
        
        
        
        return v;

        
    }
};