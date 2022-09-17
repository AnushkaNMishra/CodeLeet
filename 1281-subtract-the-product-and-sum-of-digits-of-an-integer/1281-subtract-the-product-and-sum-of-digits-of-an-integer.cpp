class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int product=1;
        int temp=n;
        while(temp>0){
                int x=(temp%10);
                sum+=x;
                product=product*x;
                temp=temp/10;
  
            }
       
        
        return product-sum;
    }
};