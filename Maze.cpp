#include <iostream>
using namespace std;

class Maze {

public:
  static int NUM_ROWS = 7;
  static int NUM_COLUMNS = 7;
  enum Direction {up, down, left, right};
  int x, y;
  int grid[NUM_ROWS][NUM_COLUMNS];

  Maze(int mazegrid[]) {
      grid = mazegrid;
  }

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
      string result;
      for (int i = 0; i < NUM_ROWS; i++) {
          for (int j = 0; j < NUM_COLUMNS; j++) {
              result += grid[i][j] + " ";
          }
          result += "\n";
      }
      cout << result << endl;
  }

}

int main() {
    int grid1[] = {
        {6,3,2,4,6,2,5},
        {3,5,2,4,4,4,1},
        {3,3,2,3,3,4,2},
        {3,4,1,2,2,5,3},
        {4,4,4,2,3,2,4},
        {2,5,4,2,3,2,5},
        {3,5,2,1,4,4,0}
    };
    Maze maze1(grid1);
    maze1.print();
}
