class Solution {
public:
    string convertToTitle(int col) {
        string res="";
        char temp;
        while(col){
            col-=1;
            temp='A'+col%26;
            res=temp+res;
            col/=26;
        }
        return res;
    }
};
