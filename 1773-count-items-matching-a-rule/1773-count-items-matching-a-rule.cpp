class Solution {
public:
    int countMatches(vector<vector<string>>& items, string rulekey, string rulevalue) {
        int n=items.size();
        int count=0;
        int i=0;
       
            if(rulekey=="type"){
                while(i<n){
                    if(items[i][0]==rulevalue){
                        count++;
                    }
                    i++;
                }
            }
            else if(rulekey=="color"){
                while(i<n){
                    if(items[i][1]==rulevalue){
                        count++;
                    }
                    i++;
                }
            }
            else{
                 while(i<n){
                    if(items[i][2]==rulevalue){
                        count++;
                    }
                    i++;
                }
            }
            
        
                return count;
    }
};