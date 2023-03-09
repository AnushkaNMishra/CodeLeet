class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        for(auto x:stones){
            mp[x]++;
        }
        int count=0;
        for(int i=0;i<jewels.length();i++){
            if(mp.find(jewels[i])!=mp.end()){
                count+=mp[jewels[i]];
            }
        }
        return count;
    }
};