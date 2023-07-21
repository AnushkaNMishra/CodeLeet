class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int diff=arr[1]-arr[0];
        
        for(int i=0;i<arr.size()-1;i++){
            int k=abs(arr[i]-arr[i+1]);
                
                if(k==diff){
                ans.push_back({arr[i],arr[i+1]});
                }
            else if(k<diff){
                diff=k;
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
            }
            
        }
        return ans;
    }
    
};