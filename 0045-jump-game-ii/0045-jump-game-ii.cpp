class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int currmax=0, jump=0, maxx=0;
        for(int i=0;i<n-1;i++){
            maxx=max(maxx, nums[i]+i);
            if(i==currmax){
                //we need to update the currmax 
                // so we have to jump here
                jump++;
                currmax=maxx;
            }
        }
        return jump;
    }
};