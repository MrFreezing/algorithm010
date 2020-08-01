class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> map;
        for (int i : arr1) map[i]++;
        
        int offset = 0;
        vector<int> res(arr1.size(), 0);
        for (int i : arr2) 
            while(map[i]--)
                res[offset++] = i;

        for (auto &v : map) 
            while (v.second-- > 0) 
                res[offset++] = v.first;

        return res;
    }
};
