class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n=costs.size();
        int count=0;
        if(n==1 && costs[0]>coins) return 0;
        for(int i=0;i<n-1;i++){
            coins-=costs[i];
            count++;
            if(coins<0){
                return 0;
            }
            else if(coins==0){
                return count;
            }
            else if(coins<costs[i+1]){
                return count;
            }
            
        }
        return count+1;
    }
};

/*if(ans==coins){
                return i+1;
            }
            else if(ans>coins){
                ans=ans-costs[i];
                if(ans<coins){
                    return i-1;
                }
                else{
                    return 0;
                }
            }
            */