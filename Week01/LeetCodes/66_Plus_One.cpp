class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size();
        do {
            digits[i-1] = digits[i-1] == 9 ? 0 : digits[i-1]+1;
        } while (!digits[--i] && i);
            
        if (!i && !digits[i]) {
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};
