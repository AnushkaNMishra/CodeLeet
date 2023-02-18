class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());
        int n=strs.size();
        if(n==0)return "";
        string a=strs[0];
        string res="";
        string b=strs[n-1];
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i]){
                res+=a[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};