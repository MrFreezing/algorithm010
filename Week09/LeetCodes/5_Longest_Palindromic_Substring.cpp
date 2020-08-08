class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";

        int maxLen = 1;
        int maxPos = 0;

        for (int i = 0; i < s.length() - maxLen; i++) {
            for (int j = s.length() - 1; j >= (i + maxLen); j--) {
                int cnt = 0;
                int odd = 0;
                int k = j;
                for (; k > (i + cnt); k--) {
                    if (s[k]  == s[i+cnt]) {
                        cnt++;
                    } else {
                        cnt = 0;
                        break;
                    }
                } 

                if (!cnt) continue;
                if ((i + cnt) == k) odd = 1;
                int len = 2*cnt + odd;
                if (len > maxLen) {
                    maxLen = len;
                    maxPos = i;
                }     
            }

        }

        return s.substr(maxPos, maxLen);
    }
};
