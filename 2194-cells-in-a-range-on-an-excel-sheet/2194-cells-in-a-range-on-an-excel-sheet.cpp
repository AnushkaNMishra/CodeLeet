class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>v;
        char c1=s[0],c2=s[3]; // storing the 0th and 3rd element
        //ex  as in "K1:L2"
        //storing c1=k and c2=L
        int n1=s[1]-'0', n2=s[4]-'0';
        //storing n1=1 and n2=2;
        
        for(int i=c1-'A';i<=c2-'A';i++){
            string temp="";
            for(int j=n1;j<=n2;j++){
                temp=c1+to_string(j);
                v.push_back(temp);
            }
            c1=c1+1;
        }
        return v;
    }
};