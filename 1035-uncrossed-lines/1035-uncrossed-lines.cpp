class Solution {
public:
    int n,m;
    int t[501][501];
    int fn(int i,int j, vector<int>& nums1, vector<int>& nums2){
        if(i>=m || j>=n) return 0;
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(nums1[i]==nums2[j]){
            return t[i][j]=1+ fn(i+1,j+1,nums1,nums2);
        }
        else{
            int ip=fn(i,j+1,nums1,nums2);
            int jp=fn(i+1,j,nums1,nums2);
            return t[i][j]=max(ip,jp);
        }
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        memset(t,-1,sizeof(t));
        return fn(0,0,nums1,nums2);
    }
};