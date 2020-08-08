class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int len_s = s.length(), len_p = p.length();
        if(len_s < len_p ) return ans;
        vector<int> freq_s(26, 0), freq_p(26, 0);
        for(int i=0; i<len_p; i++){
            freq_p[p[i] - 'a']++;
            freq_s[s[i] - 'a']++;
        }
        int dif = 0;
        for(int i=0; i<26; i++){
            if(freq_s[i] != freq_p[i])
                dif++;
        }
        if(dif == 0) ans.push_back(0);
        for(int l = 0, r = len_p; r < len_s; r++, l++){
            freq_s[s[l] - 'a']--;
            freq_s[s[r] - 'a']++;
            if(s[l] != s[r]){
                if(freq_s[s[l] - 'a'] == freq_p[s[l] - 'a']) dif--;
                else if(freq_s[s[l] - 'a']+1 == freq_p[s[l] - 'a']) dif++;
                if(freq_s[s[r] - 'a'] == freq_p[s[r] - 'a']) dif--;
                else if(freq_s[s[r] - 'a']-1 == freq_p[s[r] - 'a']) dif++;
            }
            if(dif == 0) ans.push_back(l+1);
        }
        return ans;
    }
};
