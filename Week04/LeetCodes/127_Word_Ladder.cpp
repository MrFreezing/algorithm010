class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.empty() || endWord.empty() || wordList.size() == 0) return 0;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        vector<int> visited(wordList.size(), 0);
        queue<string> q;
        q.push(beginWord);
        int step = 1;

        while(q.size()) {
            step++;
            int len = q.size();
            for (int k = 0; k < len; k++) {
                string tmp = q.front();
                q.pop();

                for (int i = 0; i < wordList.size(); i++) {
                    if (visited[i] == 0) {
                        int diff = 0;
                        for (int j = 0; j < tmp.length(); j++) 
                            if (tmp[j] != wordList[i][j]) diff++;
                        
                        if (diff == 1) {
                            if (wordList[i] == endWord) return step;
                            visited[i] = 1;
                            q.push(wordList[i]);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
