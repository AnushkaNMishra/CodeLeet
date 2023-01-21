class Solution {
public: 
    int n;
    vector<string>res;
    bool isvalid(string str){
        if(str[0]=='0')return false;
        int a=stoi(str);
        if(a>255)return false;
        return true;
    }
    
    void helper(string& s, int index, int part,string curr)
    {
        if(index==n && part==4)
        {
            res.push_back(curr.substr(0,curr.length()-1));
            return ;
        }
        if(index+1<=n){
            helper(s, index+1,part+1,curr+s.substr(index,1)+".");
        }
        if(index+2<=n && isvalid(s.substr(index,2))){
            helper(s, index+2,part+1,curr+s.substr(index,2)+".");
        }
        if(index+3<=n && isvalid(s.substr(index,3))){
            helper(s, index+3,part+1,curr+s.substr(index,3)+".");
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
       res.clear();
        n=s.length();
        if(n>12)return res;
        int part=0;
        string curr="";
        helper(s,0,part,curr);
        return res;
    }
};
//TC- O(Mn.N)(where n is in the powerand represents the height)(M=No of digits)