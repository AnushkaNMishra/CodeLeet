class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0,minsum=0;
        for(auto it:nums){
            sum+=it;
            if(sum<minsum){
                minsum=sum;
            }
        }
        return minsum*-1+1;
    }
};