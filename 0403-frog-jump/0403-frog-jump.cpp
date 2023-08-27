class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,set<int>>mp;
        for(int i=0;i<stones.size();i++)
        {
            set<int>st;
            mp[stones[i]]=st;
        }
        
        int k=1;
        mp[0].insert(1);
        for(int i=0;i<stones.size();i++)
        {
            int curStone=stones[i];
            for(auto a: mp[curStone])
            {
                int pos=curStone+a;
                if(pos==stones[stones.size()-1])
                    return true;
                if(mp.find(pos)!=mp.end())
                    mp[pos].insert(a-1);
                    mp[pos].insert(a);
                    mp[pos].insert(a+1);
            }
        }
        return false;
    }
};