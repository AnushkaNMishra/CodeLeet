class Solution {
public:
    int dayOfYear(string date) {
        //string substr (size_t pos, size_t len) const;
        int ans=0;
        vector<int>v{0,31,28,31,30,31,30,31,31,30,31,30,31};
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int days=stoi(date.substr(8,2));
        for(int i=1;i<month;i++){
            if(i==2 && ((year%4==0 &&(year%100!=0 || year%400==0)))){
                ans+=1;
            }
            ans+=v[i];
        }
        ans+=days;
        return ans;
    }
};