class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        int count=0;
       while(n>=0 && s[n]==' '){
           
               n--;
           
       }
        while(n>=0){
            if(s[n]==' '){
                break;
            }
            else{
                count++;
                --n;
            }
        }
        return count;
    }
};