class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp;
        int i=0,j=0,res=0;
        while(j<n){
            mp[fruits[j]]++;
            
            while(mp.size()>2){
                if(mp[fruits[i]]==1){
                mp.erase(fruits[i]);
                }
                else{
                    mp[fruits[i]]--;
                }
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};