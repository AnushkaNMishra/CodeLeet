class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       int n=score.size();
        vector<string>v(n);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        int i=1;
        while(!pq.empty()){
            
            int topp=pq.top().second;
            if(i==1){
                v[topp]="Gold Medal";
            }
            else if(i==2){
                v[topp]="Silver Medal";
            }
            else if(i==3){
                v[topp]="Bronze Medal";
            }
            else{
                v[topp]=to_string(i);
            }
            i++;
            pq.pop();
        }
        return v;
    }
};