class Solution {
public:
vector<string> arr;
unordered_map<char,vector<char>> mp={
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };

void helper(vector<char>& s,string& nums,int i)
{
    if(s.size()==nums.size())
    {
        string help="";
        for(int k=0;k<s.size();k++)
        {
            help+=s[k];
        }
        arr.push_back(help);
        return;
    }
    for(int j=0;j<mp[nums[i]].size();j++)
    {
        s.push_back(mp[nums[i]][j]);
        helper(s,nums,i+1);
        s.pop_back();
    }
}

vector<string> letterCombinations(string& nums)
{
    if(nums.size()==0)
    {
        return {};
    }
    vector<char> s;
    helper(s,nums,0);
    return arr;
}

};