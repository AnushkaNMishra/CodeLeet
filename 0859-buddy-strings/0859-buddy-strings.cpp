class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        
        if(s==goal){
            unordered_set<char>unique_elements(s.begin(),s.end());
            return unique_elements.size() < s.size();
        }
        
       vector<int>ind;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                ind.push_back(i);
            }
        }
        if(ind.size()!=2){
            return false;
        }
        
        swap(s[ind[0]],s[ind[1]]);
        return s==goal;
    }
};