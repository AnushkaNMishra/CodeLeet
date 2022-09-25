class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> sol;
        int size=nums.size();
            for(int i=0;i<size;i++){
                int temp=target -nums[i];
                for(int j=i+1;j<size;j++){
                    
                    if(temp==nums[j])
                    {
                        sol.push_back(i);
                        sol.push_back(j);
                    }
                }
            }
        return sol;
    }
};