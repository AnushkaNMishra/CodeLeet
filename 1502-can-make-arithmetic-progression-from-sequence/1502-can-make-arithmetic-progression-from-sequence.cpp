class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int d=0,i=2;
        d=arr[1]-arr[0];
        
        while(i!=n){
            if(arr[i]-arr[i-1]!=d){
                return false;
            }
            i++;
        }
        return true;
    }
};