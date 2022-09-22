class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int j=0,i=0;
        while(i<n){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
            else
                i++;
            
        }
    }
};