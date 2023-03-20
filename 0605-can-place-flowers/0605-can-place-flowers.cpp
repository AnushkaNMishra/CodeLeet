class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int a) {
        int n=nums.size();
        if(a==0)return true;
        if(n==1){
            if(nums[0]==0){
                return true;
            }
            else{
            return false;
        }
        }
        int count=0;
        
        if(nums[0]==0 && nums[1]==0){
            nums[0]=1;
            count++;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]==0 && nums[i-1]==0 && nums[i+1]==0){
                nums[i]=1;
                count++;
            }
        }
        
        if(nums[0]==0 && nums[1]==0){
            count++;
        }
        if(nums[n-1]==0 && nums[n-2]==0){
            count++;
        }
        if(count>=a){
            return true;
        }
        return false;
    }
};