#include <iostream>
#include <deque>
#include <vector>

class SnakeGame{
private:
    int width;
    int height;
    std::deque<std::pair<int, int>> snake; 
    std::pair<int, int> food; //food coordinate
    std::vector<std::vector<char>> field; //pole
    int foodStep = 0;
    
    void move(int dy, int dx){
        std::pair<int, int> head = snake.front();
        int newY = head.first + dy;
        int newX = head.second + dx;
        
        if(newY < 0 || newY >= height || newX < 0 || newX >= width){
            std::cout << "Error\n";
            return;
        }
        
        for(const auto& seg : snake){
            if(seg.first == newY && seg.second == newX){
                std::cout << "eats itself\n";
                return;
            }
        }
        
        snake.push_front({newY, newX});
        
        if(newY == food.first && newX == food.second){
            spawnFood();
        }else{
            snake.pop_back();
        }
        
        updateField();
    }
    
    void updateField(){
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                field[i][j] = '.';
            }
        }
        
        field[food.first][food.second] = '*';
        
        bool first = true;
        for(const auto& seg : snake){
            if(first) {
                field[seg.first][seg.second] = '@';
            }else{
                field[seg.first][seg.second] = 'O';
            }
            first = false;
        }
    }
    
public:
    SnakeGame(int w, int h, int startY, int startX) : width(w), 
                height(h), field(h, std::vector<char>(w, '.')) 
    {
        snake.push_back({startY, startX});
        food = {0, 0};
        updateField();
    }
                
    void moveUp(){ move(-1, 0); }
    
    void moveDown() { move(1, 0); }
    
    void moveLeft(){ move(0, -1); }
    
    void moveRight(){ move(0, 1); }
    
    void print() const{
        for(const auto& row : field){
            for(char c : row) std::cout <<  c << ' ';
            std::cout << '\n';
        }
        std::cout << std::string(width * 2, '-') << "\n";
    }
    
    void spawnFood(){
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                bool occupied = false;
                for(const auto& seg : snake){
                    if(seg.first == i && seg.second == j){
                        occupied = true;
                    }
                }
                if(!occupied && (i + j + foodStep) % 2 == 0){
                    food = {i, j};
                    foodStep++;
                    return;
                }
            }
        }
        food = {0, 0};
    }
    
   
};

int main()
{
	
    SnakeGame game(8, 5, 2, 3); 
    
    game.print();

    game.spawnFood();
    game.print();

    game.spawnFood();
    game.print();

    game.spawnFood();
    game.print();

    game.moveRight();
    game.print();

    game.moveDown();
    game.print();

    game.moveLeft();
    game.print();

    return 0;
}