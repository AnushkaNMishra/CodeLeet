// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)return n;
        int l=0,h=n;
        int mid=0,bad=0;
        while(l<=h){
            mid=l+(h-l)/2;
            if(isBadVersion(mid)==true){
                bad=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return bad;
    }
};