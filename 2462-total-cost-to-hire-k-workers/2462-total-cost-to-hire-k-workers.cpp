// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
        
//     }
// };

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        priority_queue<int, vector<int>, greater<int> > p1,p2;
        int n=costs.size();
        long long res=0;
        int i=0,j=n-1;
        int can=candidates;
        while(candidates--)
        {
            p1.push(costs[i++]);
        }
        while(can--)
        {
            if(j>=i)
            p2.push(costs[j--]);
        }
        cout<<i<<j<<endl;
        while(k--)
        {
            int v1 = INT_MAX, v2 = INT_MAX;
            if (!p1.empty()) v1 = p1.top(); 
            if (!p2.empty()) v2 = p2.top();
            if(v1<=v2)
            {
                res+=p1.top();
                p1.pop();
                if(i<=j)
                p1.push(costs[i++]);
            }
            else if(v1>v2)
            {
                res+=p2.top();
                p2.pop();
                if(i<=j)
                p2.push(costs[j--]);
            }
        }
        return res;
        
    }
};