class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int s=colors.size();
        int sum=0;
        int n=neededTime.size();
        for(int i=0;i<s-1;i++){
            if(colors[i]==colors[i+1]){
                if(neededTime[i]<neededTime[i+1]){
                sum+=neededTime[i];
                }
                else{
                    sum+=neededTime[i+1];
                    swap(neededTime[i],neededTime[i+1]);
                }
            }
        }
        return sum;
    }
};