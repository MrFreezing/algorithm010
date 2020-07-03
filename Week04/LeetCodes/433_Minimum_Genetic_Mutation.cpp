class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start.empty() || end.empty() || bank.size() == 0) return -1;
        if (find(bank.begin(), bank.end(), end) == bank.end()) return -1;


        vector<int> visited(bank.size(), 0);
        queue<string> q;
        q.push(start);
        int step = 0;

        while(q.size()) {
            step++;
            int len = q.size();

            for (int k = 0; k < len; k++) {
                string tmp = q.front();
                q.pop();

                for (int i = 0; i < bank.size(); i++) {
                    if (visited[i] == 0) {
                        int diff = 0;
                        for (int j = 0; j < tmp.length(); j++){
                            if (tmp[j] != bank[i][j]) diff++;
                        }

                        if (diff == 1) {
                            if (bank[i] == end) return step;
                            visited[i] = 1;
                            q.push(bank[i]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
