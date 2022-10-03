class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //vector <int> sol;
        //int size=nums.size();
         //   for(int i=0;i<size;i++){
           //     int temp=target -nums[i];
             //   for(int j=i+1;j<size;j++){
               //     
                 //   if(temp==nums[j])
                   // {
                     //   sol.push_back(i);
                       // sol.push_back(j);
//                    }
  //              }
    //        }
      //  return sol;
        vector<int>v;
        int n=nums.size();
        unordered_map<int,int>um;
        for(int i=0;i<n;i++)            
        {
            if(um.find(target-nums[i])!=um.end()){
                v.push_back(i);
                v.push_back(um[target-nums[i]]);
                return v;
            }
            else{
                um[nums[i]]=i;
            }
        }
        
    return v;
    }
};