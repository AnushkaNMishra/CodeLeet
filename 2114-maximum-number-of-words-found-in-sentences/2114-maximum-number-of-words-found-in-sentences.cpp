class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int curr=1,res=0;
        for(int i=0;i<sentences.size();i++){
            curr=1;
            string x=sentences[i];
            for(int j=0;j<x.size();j++){
                if(x[j]==' '){
                    curr++;
                }
            }
            res=max(res,curr);
        }
        return res;
    }
};