class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
        
        int dx[] = {0, 1, 0, -1}; // {north, east, south, west} for X
        int dy[] = {1, 0, -1, 0}; // {north, east, south, west} for Y
        int x = 0, y = 0, direction = 0;
        int maxDist = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                // Turn right
                direction = (direction + 1) % 4;
            } else {
                // Move forward k steps
                for (int step = 0; step < command; ++step) {
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    string nextPos = to_string(nx) + "," + to_string(ny);
                    
                    if (obstacleSet.find(nextPos) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        // Hit an obstacle, stop
                        break;
                    }
                }
            }
        }
        
        return maxDist;
    }
};