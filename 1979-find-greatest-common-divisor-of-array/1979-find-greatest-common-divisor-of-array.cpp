class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int c=nums[0];
        int d=nums[n-1];
        while(c!=d)
    {   
        if(c>d)
            c=c-d;
        
        else
        
            d=d-c;
        
    }
        return c;
    }
};