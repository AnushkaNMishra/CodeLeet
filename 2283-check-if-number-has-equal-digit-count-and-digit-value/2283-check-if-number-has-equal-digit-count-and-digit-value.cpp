class Solution {
public:
    bool digitCount(string num) {
        vector<int>v(10,0);
        for(auto it:num){
            v[it-'0']++;
        }
        for(int i=0;i<num.size();i++){
            if(v[i]!=num[i]-'0'){
                return false;
            }
        }
       return true;
    }
};