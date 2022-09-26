class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid=(h-l)/2+l;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=nums[mid]){
                sum+=nums[mid]-nums[i];
            }
            else{
                sum+=nums[i]-nums[mid];
            }
        }
        return sum;
    }
};
//val1 = abs(22);