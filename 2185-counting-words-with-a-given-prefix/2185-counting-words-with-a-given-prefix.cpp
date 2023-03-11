class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
       int n=pref.size();
        int ans=0;
        for(int i=0;i<words.size();i++){
           // if(words[i].compare(0, pref.size(), pref)==0){
           //     ans++;
           // }
            if(words[i].substr(0,n)==pref){
                ans++;
            }
            
        }
        return ans;
    }
};