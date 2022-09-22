class Solution {
public:
    int maximumProduct(vector<int>& v) {
        
        sort(v.begin(),v.end());
       int a=v.size();
        return max(v[a-1]*v[a-2]*v[a-3],v[0]*v[1]*v[a-1]);
    }
};
