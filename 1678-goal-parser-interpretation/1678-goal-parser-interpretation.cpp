class Solution {
public:
    string interpret(string command) {
        string ans;
    
       for(int i=0;i<command.size();){
            if(command[i]=='G'){
                i++;
                ans+='G';
            }
           else if(command[i]=='(' && command[i+1]==')'){
                i=i+2;
                ans+='o';
            }
            else {
                ans+="al";
                i=i+4;
            }
        }
        return ans;
    }
};