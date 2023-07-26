class Solution {
public:
    
    
//          https://leetcode.com/problems/koko-ea...

//             https://leetcode.com/problems/capacit...

//             https://leetcode.com/problems/minimum...

//             https://leetcode.com/problems/magneti...

//             Allocate Minimum Number Of Pages (https://practice.geeksforgeeks.org/pr...
// )
    
    
    double possible(vector<int>& dist, int speed,double hour){
        double time=0.0;
        int n=dist.size();
        for(int i=0;i<n-1;i++){
            double t=(double)dist[i]/(double)speed;
            time+=ceil(t);
        }
        time+=(double)dist[n-1]/(double)speed;
        return time;
    }
    
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
     // if(hour<dist.size()){
     //     return -1;
     // }   
        int l=1;
        int r=1e7;
        int minspeed=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(dist,mid,hour)<=hour){
                minspeed=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return minspeed;
    }
};