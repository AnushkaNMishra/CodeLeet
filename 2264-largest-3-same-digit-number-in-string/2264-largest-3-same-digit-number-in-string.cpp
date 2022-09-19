class Solution {
public:
    string largestGoodInteger(string num) {
        char res=0;
        for(int i=0;i<num.size();++i){
            if((num[i+1])==num[i] && (num[i+2])==num[i])
                res=max(res,num[i]);
            
        }
        if(res==0) 
            return "";
        else
            return string(3,res);
    }
};
//suppose you get res =7 char , then the meaning of string(3, res) is print 3 times 7 or "777";