class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map1;
        map<char, int> map2;
        for (char c : s) map1[c]++;
        for (char c : t) map2[c]++;

        if (map1.size() != map2.size()) return false;

        map<char, int>::iterator it1, it2;
        for (it1 = map1.begin(), it2 = map2.begin(); it1 != map1.end(); it1++, it2++) 
            if (it1->first != it2->first || it1->second != it2->second) 
                return false;
        
        return true;
    }
};
