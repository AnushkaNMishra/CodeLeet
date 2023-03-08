class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long st=1,end=*max_element(piles.begin(),piles.end());
        while(st<end)
        {
            long long mid=(end+st)/2,val=0;
            for(int i=0;i<piles.size();i++)
            {
                val+=ceil(piles[i]*1.0/mid);
            }
            if(val<=h)
            {
                end=mid;
            }
            else
            {
                st=mid+1;
            }
        }
        return end;
    }
};