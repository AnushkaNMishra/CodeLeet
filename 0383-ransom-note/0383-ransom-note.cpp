class Solution {
public:
    bool canConstruct(string r, string m) {
        if(r.size()>m.size()){
            return false;
        }
        
            vector<int> v(26,0);
        
           
            for(char c:m)
            {
                v[c-'a']++;
            }
            for(char c:r){
                
                
                v[c-'a']--;
                if(v[c-'a']<0){
                    return 0;
                }
            }
            return 1;
        }
        
    
};