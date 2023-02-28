class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       // set<int>s;
       //  for(auto it:nums){
       //      if(it!=0){
       //          s.insert(it);
       //      }
       //  }
       //  return s.size();
        
        priority_queue<int>pq;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(pq.empty()){
                    pq.push(nums[i]);
                }
                else{
                    if(pq.top()==nums[i]){
                        continue;
                    }
                    else{
                        pq.push(nums[i]);
                    }
                }
            }
        }
        return pq.size();
    }
};