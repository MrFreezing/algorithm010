class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ug(n, 1);

        int c2 = 2, c3 = 3, c5 = 5;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; i++) {
            int t = ug[i] = min(min(c2, c3), c5);
            if (c2 == t) c2 = ug[++p2] * 2; 
            if (c3 == t) c3 = ug[++p3] * 3;
            if (c5 == t) c5 = ug[++p5] * 5;
        }
        return ug[n-1];
        
    }
};
