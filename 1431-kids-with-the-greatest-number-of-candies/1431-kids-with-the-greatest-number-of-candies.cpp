class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        int n=candies.size();
        vector<bool>res;
        //sort(candies.begin(),candies.end());
        int f=0;
        for(int i=0;i<n;i++){
            if(candies[i]>f){
                f=candies[i];
            }
        }
       
        
       for(int i=0;i<n;i++){
            if((candies[i]+e)>=f){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
           
        }
        return res;
    }
};