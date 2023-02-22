class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ans(n);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        int i=1;
        while(!pq.empty()){
            int topp=pq.top().second;
            if(i==1){
                ans[topp]="Gold Medal";
            }
            else if(i==2){
                ans[topp]="Silver Medal";
            }
            else if(i==3){
                ans[topp]="Bronze Medal";
            }
            else{
                ans[topp]=to_string(i);
            }
            i++;
            pq.pop();
        }
        return ans;
        
    }
};