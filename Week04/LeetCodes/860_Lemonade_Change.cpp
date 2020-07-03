class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills) {
            if (bill == 5) five++;
            else if (bill == 10) five--, ten++;
            else if (bill == 20) ten ? ten--, five-- : five -=3;
            else return false;

            if (five < 0) return false;
        }
        return true;
    }
};
