class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1,r=arr.size()-2;
        int peak=l;
        while(l<=r){
            int m=(l+r)>>1;
            if(arr[m]>arr[m-1] and arr[m]>arr[m+1])return m;
            else if(arr[m]>arr[m-1] and arr[m]<arr[m+1])l=m+1;
            else r=m-1;
        }
        return -1;
    }
};