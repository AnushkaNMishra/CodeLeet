class Solution {
public:
    bool checkPerfectNumber(int num) {
        int x=num;
        int temp=0;
    for(int i=1;i*i<num;i++){
        if(num%i==0){
            temp+=i;
        if(i!=num/i){
            int a=num/i;
                temp+=a;
            }
            
        }
        
    }
        
        if((temp-x)==x)return true;
        return false;
    }
};
    