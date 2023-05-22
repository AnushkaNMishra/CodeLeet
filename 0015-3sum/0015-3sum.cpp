class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int sum=0;
        if (nums.size()<3){
            return {};
        }
        if(nums[0]>0){
            return {};
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int low=i+1,high=nums.size()-1;
            while(low<high){
                sum=nums[i]+nums[low]+nums[high];
                if(sum>0){
                    high--;             
                }
                else if(sum<0){
                    low++;
                }
                else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    int duplicatelow=nums[low],duplicatehigh=nums[high];
                    while(low<high && duplicatelow==nums[low]){
                        low++;
                    }
                    while(low<high && duplicatehigh==nums[high]){
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};