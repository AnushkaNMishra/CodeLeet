class Solution {
public:
    int percentageLetter(string s, char letter) {
        double count=0;
        float n=s.size();
        sort(s.begin(),s.end());
        int i=0;
        while(i<n){
            if(s[i]==letter){
                count++;
               
            }
            i++;
        }
        
        return count/n*100;
        
    }
};