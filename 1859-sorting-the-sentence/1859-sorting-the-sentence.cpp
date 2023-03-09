class Solution {
public:
    string sortSentence(string s) {
        vector<string>v(10,"");
        for(int i=0;i<s.size();i++){
            int j=i;
            string curr;
            while(!isdigit(s[j])){
                curr.push_back(s[j]);
                j++;
            }
            v[s[j]-'0']=curr;
            i=j+1;
        }
        string res;        
        for(int i=1;i<10;i++){
            if(v[i].length()>0){
            res+=v[i];
            res.push_back(' ');
           
        }
        }
        res.pop_back();
        return res;
    }
};