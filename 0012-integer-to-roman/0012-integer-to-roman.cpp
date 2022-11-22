class Solution {
public:
    string intToRoman(int num) {
        vector<int>v={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>s={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string st;
        for(int i=0;i<13;i++){
            while(num>=v[i]){
                st.append(s[i]);
                num-=v[i];
            }
        }
        return st;
    }
};