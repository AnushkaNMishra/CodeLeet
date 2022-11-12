class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int count=0,r=1,l=0;
        int n=a.size();
        sort(a.begin(),a.end());
        while(r<n){
            if(a[l][1]<=a[r][0]){
                l=r;
                r++;
            }
            else if(a[l][1]<=a[r][1]){
                count++;
                r++;
            }
            else if(a[l][1]>a[r][1]){
                count++;
                l=r;
                r++;
            }
        }
        return count;
    }
};