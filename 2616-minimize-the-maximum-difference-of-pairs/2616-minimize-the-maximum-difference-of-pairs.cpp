class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        // Sort the array as its required for binary search;
        sort(nums.begin(),nums.end());
        
        // taking low as 0;
        int low = 0;
        
        // taking high as a large prime number;
        int high = 1e9 + 7;
        
        
        while(low <= high){
            // choosing a mid which will act as maximum distance between elements;
            int mid = low + (high - low)/2;
            
            int pairs = 0;
            
            
            for(int i = 1 ; i < nums.size(); i++){
                // if the difference is within the mid then we cannot use these pairs again therefore an additional i++;
                if((nums[i] - nums[i - 1]) <= mid){
                    i++;
                    pairs++;
                }
                
            }
            
            // If the pairs is greater than required pairs then lower the mid else increase it; 
            if(pairs >= p){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        
        // return the lowest maximum difference
        return low;
    }
};