class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,count=0,rem=0;
        unordered_map<int,int>um;
        um[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0){
                rem=rem+k;
            }
            if(um.find(rem)!=um.end()){
                count+=um[rem];
            }
            um[rem]++;
        }
        return count;
    }
};