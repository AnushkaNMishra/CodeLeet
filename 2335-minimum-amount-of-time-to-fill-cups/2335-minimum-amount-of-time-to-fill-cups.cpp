class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int count=0;
        while(amount[2]!=0){
            count++;
            amount[2]--;
            if(amount[1]>0){
                amount[1]--;
            }
            sort(amount.begin(),amount.end());
        }
        return count;
    }
};