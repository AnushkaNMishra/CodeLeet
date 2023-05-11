class Solution {
public:
    //bottom-up
   int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
       vector<vector<int>>dp(m+1,vector<int>(n+1));
       
       for(int i=0;i<m+1;i++){
           for(int j=0;j<n+1;j++){
               if(i==0 || j==0){
                   dp[i][j]=0;                  
               }
               else if(nums1[i-1]==nums2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
               }
               else{
                   dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
               }
           }
       }
       return dp[m][n];
  }
};

//recur+memo
// class Solution {
// public:
//     int n,m;
//     int t[501][501];
//     int fn(int i,int j, vector<int>& nums1, vector<int>& nums2){
//         if(i>=m || j>=n) return 0;
        
//         if(t[i][j]!=-1){
//             return t[i][j];
//         }
//         if(nums1[i]==nums2[j]){
//             return t[i][j]=1+ fn(i+1,j+1,nums1,nums2);
//         }
//         else{
//             int ip=fn(i,j+1,nums1,nums2);
//             int jp=fn(i+1,j,nums1,nums2);
//             return t[i][j]=max(ip,jp);
//         }
//     }
    
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         m=nums1.size();
//         n=nums2.size();
//         memset(t,-1,sizeof(t));
//         return fn(0,0,nums1,nums2);
//     }
// };