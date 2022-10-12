class Solution {
public:
    int reverse(int x) {
        int newNum=0;
        int digit;
        while(x!=0){
            if(newNum>INT_MAX/10 || newNum<INT_MIN/10){
                return 0;
            }
            digit=x%10;
            newNum= newNum*10+digit;
            x=x/10;
            
        }
        return newNum;
        
    }
};