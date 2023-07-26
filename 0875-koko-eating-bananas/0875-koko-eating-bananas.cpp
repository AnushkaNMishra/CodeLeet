class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int n=piles.size();
        int ans=-1;
       while(l<=r){
           double time=0.0;
           long long mid=l+(r-l)/2;
           for(int i=0;i<n;i++){
               time+=ceil((double)piles[i]/(double)mid);
           }
           if(time<=h){
               ans=mid;
               r=mid-1;
           }
           else{
               l=mid+1;
           }
       }
        return ans;
        
    }
};