class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>v;
        int n=num.size()-1, carry=0;
        while(n>=0 || carry>0 || k!=0){
            if(k!=0){
                carry+=k%10;
                k=k/10;
            }
            if(n>=0){
                carry+=num[n];
                n--;
            }
            int a=carry%10;
            v.push_back(a);
            carry=carry/10;
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};