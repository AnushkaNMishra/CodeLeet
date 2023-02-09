class Solution {
public:
    string convert(string s, int numRows) {
        string res="";
        if(numRows==1){
            return s;
        }
        vector<string>v(numRows);
        int i=0,j=0;
        while(j<s.size()){
            while(i<numRows && j<s.size()){
                v[i]+=s[j];
                i++;
                j++;
            }
            i=i-2;
            while(i>=1 && j<s.size()){
                v[i]+=s[j];
                i--;
                j++;
            }
        }
        for(int i=0;i<numRows;i++){
            res+=v[i];
        }
        return res;
    }
};