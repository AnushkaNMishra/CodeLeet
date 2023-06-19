class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int sum=0,max_alt=0;
        
        
        for(int i=0;i<n;i++){
             sum+=gain[i];
            max_alt=max(max_alt,sum);
        }
         
 
         return max_alt;
        
    }
};