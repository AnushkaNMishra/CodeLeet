class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>v;
        unordered_map<int,int>um;
        for(int i=0;i<n1;i++){
            um[nums1[i]]++;
        }
        for(int j=0;j<n2;j++){
            if(um.find(nums2[j])!=um.end()){
                v.push_back(nums2[j]);
                um[nums2[j]]--;
                if(um[nums2[j]]<=0){
                    um.erase(nums2[j]);
                }
            }
        }
        return v;
    }
};