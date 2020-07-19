class SnakeGame {
public:
    int count = 0, posx = 0, posy = 0, width = 0, height = 0;
    vector<pair<int, int>> snake;
    vector<pair<int, int>> food;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->food = food;
        snake.push_back({0,0});
        this->height = height;
        this->width = width;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(count>this->food.size()) return -1;
        if(direction.compare("U")==0) posx--;
        if(direction.compare("D")==0) posx++;
        if(direction.compare("L")==0) posy--;
        if(direction.compare("R")==0) posy++;
        if(posx<0||posx>=this->height||posy<0||posy>=this->width) return -1;
        if(count<this->food.size()&&posx==this->food[count].first&&posy==this->food[count].second){
            snake.push_back({posx,posy});
            return ++count;
        }
        snake.erase(snake.begin());
        for(auto a:snake){
            if(a.first == posx&&a.second == posy) return -1;
        }
        snake.push_back({posx,posy});
        return count;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */