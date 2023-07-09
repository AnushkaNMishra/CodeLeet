class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp; //{char,count}
        int left=0,right=0;
        int res=0;
        while(right<s.size()){
            mp[s[right]]++;
            if(mp.size()==right-left+1){
                res=max(res,right-left+1);
                right++;
            }
            else if(mp.size()<right-left+1){
                while(mp.size()<right-left+1){
                    mp[s[left]]--;
                    if(mp[s[left]]==0){
                        mp.erase(s[left]);
                    }
                    left++;
                }
                right++;
            }
        }
        return res;
    }
};



 // int ans=INT_MAX;
 //        for(auto it:s){
 //            mp[s[it]]++;
 //        }
 //        int ind=0;
 //        for(auto x:mp){
 //            char temp=x.first;
 //            int a=x.second;
 //            if(a>1){
 //                if(mp.find(temp)!=mp.end()){
 //                    ind=mp[temp];
 //                }
 //                ans=min(ans,ind);
 //            }
 //        }
 //        return ans+1;