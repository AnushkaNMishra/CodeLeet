class Solution {
public:
    int bestClosingTime(string customers) {
      
        int points = 0;
        int hour=-1;
        int z=0;
        for(int i = 0; i < customers.size(); i++){
            if(customers[i] == 'Y'){
            points=points+ 1;
            }
            else{ 
                points= points-1;
            }
            if(points>z){
                z=points;
                hour = i;
            }
        }
        return hour+1 ;
    
}
};