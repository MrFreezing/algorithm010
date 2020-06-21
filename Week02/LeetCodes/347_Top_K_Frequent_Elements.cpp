class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frep;
        for (int i : nums) frep[i]++;

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second;};
        priority_queue<pair<int, int> , vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (auto f : frep) {
            pq.push(f);
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }

    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> frep;
    //     for (int i : nums) frep[i]++;

    //     //超长buckets
    //     vector<vector<int>> buckets(nums.size() + 1);

    //     for (auto f : frep) 
    //         buckets.at(f.second).push_back(f.first);
        
    //     vector<int> res;
    //     for (int i = buckets.size() - 1; i >= 0; i--) {
    //         for (auto bucket : buckets[i]) {
    //             res.push_back(bucket);
    //             if (res.size() == k) return res;
    //         }
    //     }
        
    //     return res;
    // }
};
