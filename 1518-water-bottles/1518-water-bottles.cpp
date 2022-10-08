class Solution {
public:
    int numWaterBottles(int numBottle, int numExchange) {
        return numBottle+(numBottle-1)/(numExchange-1);
    }
};