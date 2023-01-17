class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c1=0,cf=0;
        for(auto it:s)
        {
            if(it=='1')
            {
                c1+=1;
            }
            else{
                cf+=1;
            }
            cf=min(cf,c1);
        }
        return cf;
    }
};