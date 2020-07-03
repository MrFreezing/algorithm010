class Solution {
private:
    enum {North = 0, West, East, South};
    //unordered_set<pair<int, int>> obs;
    set<pair<int, int>> obs;

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for (auto o : obstacles) obs.insert({o[0], o[1]});
        
        int max_dis = 0;
        pair<int, int> position = {0, 0};
        int forward = North;

        for (auto command : commands) {
            if (command > 0) {//forward
                max_dis = max(robotWalk(position, forward, command), max_dis);
            }
            else if (command == -1 || command == -2) {//turn
                robotTurn(forward, command);
            } else {
                return 0;
            }
        }

        return max_dis;
    }

private:
    int robotWalk(pair<int, int>& position, const int forward, const int command) {
        int x = position.first;
        int y = position.second;

        switch(forward) {
            case North : {
                for (int i = 1; i <= command; i++) {
                    if (obs.find({x, y + 1}) != obs.end()) break;
                    else y++;
                }
                break;
            }
            case West : {
                for (int i = 1; i <= command; i++) {
                    if (obs.find({x - 1, y}) != obs.end()) break;
                    else x--;
                }
                break;
            }
            case East : {
                for (int i = 1; i <= command; i++) {
                    if (obs.find({x + 1, y}) != obs.end()) break;
                    else x++;
                }
                break;
            }
            case South : {
                for (int i = 1; i <= command; i++) {
                    if (obs.find({x, y - 1}) != obs.end()) break;
                    else y--;
                }
                break;
            }
        }

        position = {x, y};

        return x * x + y * y;
    }

    void robotTurn (int & forward, int command) {
        if (command ==  -1) {
            switch (forward) {
                case North : forward = East; break;
                case West : forward = North; break;
                case East : forward = South; break;
                case South : forward = West; break;                
            }
        } else if (command == -2){
            switch (forward) {
                case North : forward = West; break;
                case West : forward = South; break;
                case East : forward = North; break;
                case South : forward = East; break;
            }
        }
    }
};
