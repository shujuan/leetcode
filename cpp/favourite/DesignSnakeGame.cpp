class SnakeGame {
    deque<pair<int,int>>snake;
    unordered_set<int>snakeCollect;
    queue<pair<int,int>>foodList;
    int w, h;
    pair<int,int>curFood;
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;
        for(int i=0; i<food.size(); i++) {
            foodList.push({food[i][0], food[i][1]});
        }
        curFood = foodList.front();
        snake.push_front({0,0});
        snakeCollect.insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int,int>head = snake.front();
        pair<int,int>tail = snake.back();
       // cout<<tail.first << " " << tail.second<< "\n";
        snakeCollect.erase(tail.first*w + tail.second);
        snake.pop_back();
        if(direction == "L"){
            head.second--;
        }else if(direction == "R") {
            head.second++;
        } else if (direction == "U") {
            head.first--;
        } else {
            head.first++;
        }
       //  cout<< "head " <<head.first << " " <<head.second<< " " << curFood.first << " " << curFood.second <<"\n";
        if(head.first<0 || head.first >= h || head.second<0 || head.second >= w || snakeCollect.count(head.first*w+head.second)) return -1;  
        snake.push_front(head);
        snakeCollect.insert(head.first*w + head.second);
        if(head == curFood) {
            foodList.pop();
            curFood = foodList.front();
         //    cout<<"push back" <<tail.first << " " << tail.second<< "\n";
            snake.push_back(tail);
            snakeCollect.insert(tail.first*w + tail.second);
        }
        
        return snake.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */