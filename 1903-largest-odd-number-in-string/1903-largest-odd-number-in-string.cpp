class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            int odd=num[i]-'0'; //every odd number has odd ascii code
            if(odd%2==1){
                ans=num.substr(0,i+1);
                return ans; 
               
            }
        }
        return "";
    }
};