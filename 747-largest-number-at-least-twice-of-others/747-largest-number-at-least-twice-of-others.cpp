class Solution {
public:
    int dominantIndex(vector<int>& v) {
       int max=*max_element(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            if((v[i]*2)<=max || v[i]==max){
                continue;
            }
            else{
                cout<<i;
                return -1;
            }
        }
        int maxElementIndex =std::max_element(v.begin(),v.end()) - v.begin();
        return maxElementIndex;
    }
};