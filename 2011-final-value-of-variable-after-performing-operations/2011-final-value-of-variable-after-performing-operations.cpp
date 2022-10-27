class Solution {
public:
    int finalValueAfterOperations(vector<string>& nums) {
        int n=nums.size();
        int X=0;
        for(int i=0;i<n;i++){
            if(nums[i]=="++X"){
                ++X;
            }
            else if(nums[i]=="X++"){
                X++;
            }
            else if(nums[i]=="--X"){
                --X;
            }
            else if(nums[i]=="X--"){
                X--;
            }
        }
        return X;
    }
};