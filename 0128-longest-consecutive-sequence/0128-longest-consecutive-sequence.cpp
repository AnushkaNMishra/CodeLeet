class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans=1;
        if(nums.size()==0){
            return 0;
        }
        for(auto it:nums){
            st.insert(it);
        }
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-1)==st.end()){
                j=nums[i]+1;
            
            while(st.find(j)!=st.end()){
                j++;
            }
            ans=max(ans,j-nums[i]);
            }
        }
        return ans;
    }
};