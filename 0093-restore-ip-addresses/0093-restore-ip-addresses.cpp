class Solution {
public: 
    int n;
    vector<string>ans;
    
    bool isvalid(string str)
    {
        if(str[0]=='0')return false;
        
        int val=stoi(str);
        if(val>255)
        {return false;
        }
        return true;
    }
    
    void solve(string& s, int index, int parts, string curr)
    {
        if(index==n && parts==4){
            // curr.pop_back(); //removing the last dot  
            // ans.push_back(curr);
            
            // or we to remove the dot we cam simple do
             ans.push_back(curr.substr(0, curr.length()-1));
            return;
        }
        if(index+1<=n){
        solve(s,index+1,parts+1, curr+s.substr(index,1)+".");
        }
        if(index+2<=n && isvalid(s.substr(index,2))){
        solve(s,index+2,parts+1, curr+s.substr(index,2)+".");
        }
        if(index+3<=n && isvalid(s.substr(index,3))){
        solve(s,index+3,parts+1, curr+s.substr(index,3)+".");
        }

    }
        
        
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        n=s.length();
        if(n>12)return ans;
        string curr="";
        int parts=0;
        solve(s,0,parts,curr);  
        return ans;
    }
};
//TC- O(Mn.N)(where n is in the powerand represents the height)(M=No of digits)