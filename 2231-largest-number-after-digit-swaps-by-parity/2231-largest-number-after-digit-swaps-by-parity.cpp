class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>even;
        priority_queue<int>odd;
        string s=to_string(num);
        for(auto it:s){
            int temp=it-'0';
            if(temp%2==0){
                even.push(temp);
            }
            else{
                odd.push(temp);
            }
        }
        
        
        for(auto& x:s){
            int temp=x-'0';
            if(temp%2==0){
                x=even.top()+'0';
                even.pop();
            }
            else{
                x=odd.top()+'0';
                odd.pop();
            }
        }
        return stoi(s);
    }
};