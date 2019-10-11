/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
    int x=0;
    int y=0; //记录当下的位置
    vector<pair<int,int>>dirs = {{-1,0}, {0, 1}, {1,0}, {0,-1}};
    set<pair<int,int>>visited;
    int dir =0; //沿着之前的方向走
    
public:
    void cleanRoom(Robot& robot) {
        if(visited.count({x,y})) return;
        visited.insert({x,y});
         robot.clean();
        
        for(int i=0; i<4; i++){
            if(robot.move()){
                x += dirs[dir].first;
                y += dirs[dir].second;
               
                cleanRoom(robot);
                
               
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                x -= dirs[dir].first;
                y -= dirs[dir].second;
            }
            
            robot.turnRight();
            dir = (dir+1) % 4;
        
        }
    }
};