// class Solution {
// public:
//     long long putMarbles(vector<int>& weights, int k) {
        
//     }
// };

class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n=nums.size();
        if(n == k) return 0;
        priority_queue<int> pq;
        priority_queue<int> pq2;

        for(int i=0;i<n-1;i++)
        {
            pq.push(nums[i]+nums[i+1]);
            pq2.push(-1*(nums[i]+nums[i+1]));
            
        }
        long long int sum1=0;
        k--;
        while(k--)
        {
            sum1+=pq.top();
            sum1+=pq2.top();
            pq.pop();pq2.pop();
        }        
        return sum1;

    }
};