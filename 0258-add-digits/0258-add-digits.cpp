class Solution {
public:
int value(int n){
int rim , sum = 0;
if(!n){
return 0;
}
else {
while(n != 0){
rim = n % 10;
n = n / 10;
sum = sum + rim;
}

    if(sum > 9){
        return value(sum);
    }
    else
        return sum;
    }
};
int addDigits(int num) {
    int n = num,rim,store = 0 , n1= 0;
    if(num == 0 || num > 0 && num < 10)
            return num;
    else{
        store = value(num);
    }
    return store;
}
};