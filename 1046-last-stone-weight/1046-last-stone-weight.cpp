class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it:stones){
            pq.push(it);
        }
        
        int n=stones.size();
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b){
                int rem=abs(a-b);
                pq.push(rem);
            }
            
        }
        if(pq.size()==1){
            return pq.top();
        }
        return 0;
    }
};