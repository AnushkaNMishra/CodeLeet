class SummaryRanges {
public:
    map<int,int>mp;
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int value) {
        int l=value,r=value;
        auto greater_val =mp.upper_bound(value); //logn
        //auto nextv=prev;
        
        if(greater_val!=mp.begin()){
            
            auto lower_val = greater_val;
            lower_val--;
        
            if(lower_val->second >= value){
                return;
            }
            
            if(lower_val->second == value-1){
                l = lower_val->first;
            }
        }
        
        if(greater_val != mp.end() && greater_val->first == value+1){
            r=greater_val->second;
            mp.erase(greater_val);
        }
        mp[l]=r;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>res;
        for(auto& it: mp){
            res.push_back({it.first,it.second});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */