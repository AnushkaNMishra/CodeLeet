class Solution {
public:
    int commonFactors(int a, int b) {
        int count=1;
        int min=b;
        if(a<b){
            min=a;
        }
        
        if(a==0 || b==0)return 0;
        for(int i=2 ; i<= min; i++){
                if(a%i==0 && b%i==0){
                count++;
            
            }
        }
        return count;
    }
};