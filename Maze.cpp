#include <iostream>
using namespace std;

class Maze {

public:
  static int const NUM_ROWS = 7;
  static int const NUM_COLUMNS = 7;
  enum Direction {up, down, left, right};
  int x, y;
  int grid[NUM_ROWS][NUM_COLUMNS];

  Maze(): grid{
        {6,3,2,4,6,2,5},
        {3,5,2,4,4,4,1},
        {3,3,2,3,3,4,2},
        {3,4,1,2,2,5,3},
        {4,4,4,2,3,2,4},
        {2,5,4,2,3,2,5},
        {3,5,2,1,4,4,0}}
  {}

  int move(Direction d) {
    int newx = x, newy = y;
    switch(d) {
        case up: newy -= grid[y][x]; break;
        case down: newy += grid[y][x]; break;
        case left: newx -= grid[y][x]; break;
        case right: newx += grid[y][x]; break;
    }

    if (newx < 0 || newx >= NUM_COLUMNS || newy < 0 || newy >= NUM_ROWS) {
        return 0;
    }

    x = newx;
    y = newy;
    return 1;
  }

  void print() {
    string result("Current Maze State:\n");
      for (int i = 0; i < NUM_ROWS; i++) {
          for (int j = 0; j < NUM_COLUMNS; j++) {
	    if (i == y && j == x) {
	      result += "\e[1m" + to_string(grid[i][j]) + "\e[0m ";
	    } else {
	      result += to_string(grid[i][j]) + " ";
	    }
          }
          result += "\n";
      }
      cout << result << endl;
  }

  int isGoalState() {
      return x == NUM_COLUMN - 1 && y == NUM_ROW - 1;
  }

};

int main() {
    Maze maze;
    maze.print();

    while(!maze.isGoalState()) {
        cout << "Select either up, down, left or right" << endl;
        string s;
        cin >> s;
        
        if (s == "up") {
            maze.move(up);
        } else if (s == "down") {
            maze.move(down);
        } else if (s == "left") {
            maze.move(left);
        } else if (s == "right") {
            maze.move(right);
        } else {
            cout << "Invalid input. Try again" << endl;
        }

        maze.print();
    }
}
