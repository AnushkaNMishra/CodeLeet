class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int d=0,i=2;
        d=abs(arr[1]-arr[0]);
        
        while(i!=n){
            
            int c=abs(arr[i]-arr[i-1]);
            cout<<c;
            if(c==d){
                i++;
            }
            else{
            return false;
            }
        }
        return true;
    }
};