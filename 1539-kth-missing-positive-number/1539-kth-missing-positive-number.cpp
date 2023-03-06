class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>v(2001,0);
        for(auto it:arr){
            v[it]++;
        }
        for(int i=1;i<2001;i++){
            if(v[i]==0){
                k--;
            }
            if(k==0){
                return i;
            }
        }
        return 0;
    }
};