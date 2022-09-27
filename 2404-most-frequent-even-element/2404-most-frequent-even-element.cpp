class Solution {
    public:
    int mostFrequentEven(vector<int> &nums) {
        int mx=-1,res=-1;
    map<int,int>um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto x:um){
            if(x.first%2==0 && x.second>mx){
                mx=x.second;
                res=x.first;
            }
        }
        return res;
    }
};

