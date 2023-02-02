class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
          string word1=words[i];
          string word2=words[i+1];
          int n=min(word1.size(),word2.size());
          for(int j=0;j<n;j++){
              if(mp[word1[j]]<mp[word2[j]]){
                  break;;
              }
            if(mp[word1[j]]>mp[word2[j]]){
                return false;
            }
            if(j==n-1 && word1.size()>word2.size()){
                return false;
            }
          }
        }
        return true;
    }
};