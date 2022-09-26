class Solution {
public:
    int arrangeCoins(int n) {
        int i=0;
        while(n>0){
            n=n-i;
            if(n>0 && n>i){
                i++;
            }
        }
        return i;
    }
};