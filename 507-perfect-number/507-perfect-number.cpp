class Solution {
public:
    bool checkPerfectNumber(int num) {
        int x=num;
        int temp=0;
    for(int i=1;i*i<num;i++){
        if(num%i==0){
            cout<<i<<"a ";
            temp+=i;
        if(i!=num/i){
            int a=num/i;
                cout<<num/i<<"b ";
                temp+=a;
            }
            
        }
        
    }cout<<temp<<"a";
        int res=temp-x;
        if(res==x)return true;
        return false;
    }
};
    