class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>v;
        if(num%3!=0)return v;
        long long a =num/3;
       a-=1;
        v.push_back(a);
        v.push_back(a+1);
        v.push_back(a+2);
        return v;
    }
};