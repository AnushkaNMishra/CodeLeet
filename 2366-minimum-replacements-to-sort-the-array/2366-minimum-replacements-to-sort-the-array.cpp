class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long p=0;
        long long o =0;
        for(int i = nums.size()-1 ; i>0 ; i--){
            if(nums[i-1] > nums[i] ){
                p = nums[i-1]/nums[i];
                if(nums[i-1] % nums[i] !=0) p++;

                nums[i-1] /= p;
                o += (p-1);
            }
        }
        return o;
    }
};