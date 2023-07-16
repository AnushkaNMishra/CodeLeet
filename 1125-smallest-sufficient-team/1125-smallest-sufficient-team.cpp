class Solution {
public:
    using ll = long long int;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        ll n = req_skills.size();
        ll m = people.size();
        vector <ll> dp((1LL<<n),(1LL<<m)-1);
        vector <ll> masks(m);
        map <string,ll> mp;
        for(ll i=0;i<n;i++){
            mp[req_skills[i]] = i;
        }
        for(ll i=0;i<m;i++){
            ll mask = 0;
            for(auto j:people[i]){
                mask |= (1LL<<mp[j]);
            }
            masks[i] = mask;
        }
        dp[0] = 0;
        for(ll i=1;i<(1LL<<n);i++){
            for(ll j=0;j<m;j++){
                ll notMask = (~masks[j]) & (i);
                if(notMask != i){
                    ll setMask = (1LL<<j) | dp[notMask];
                    if(__builtin_popcountll(setMask) < __builtin_popcountll(dp[i])){
                        dp[i] = setMask;
                    }
                }
            }
        }
        vector <int> ans;
        for(ll i=0;i<m;i++){
            if((1LL<<i) & dp[(1<<n)-1]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};