class Solution {
public:
    
    void func(vector<int>&nums, int i, int j){
        int a=i;
        int b=j;
        
        while(a<b){
            swap(nums[a],nums[b]);
            a++;
            b--;
            
        }
    }
    
    void rotate(vector<int>& nums, int k) {
       
       int n=nums.size();
        k=k%n;
        if(k<0){
            k+=n;
        }
        func(nums,0,n-k-1);
        func(nums,n-k,n-1);
        func(nums,0,n-1);
    }
};