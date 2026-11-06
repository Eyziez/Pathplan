#include <iostream>
#include <vector>
#include "head.h"
#include "pathplan.h"

using std::cout;
using std::endl;
using std::vector;

int main() 
{
    int w = 10;
    int h = 10;

    // 1. Initialize the map
    Searchmap map(w, h);

    // 2. Create obstacles (walls). 
    // We use 1D array: index = y * width + x
    vector<bool> walls(w * h, false);

    // Build a vertical wall at x = 5, from y = 0 to y = 7
    for (int y = 0; y < 8; y++) {
        walls[y * w + 5] = true;
    }

    // Initialize the map with these walls
    map.init(walls);

    // 3. Set start and end points
    Point start(2, 2);
    Point end(8, 8);

    Pathplan planner;
    planner.set_se(start, end);

    // 4. Run A* search
    cout << "Start A* pathfinding..." << endl;
    bool found = planner.Astar(map);

    if (found) {
        cout << "Success! Target found." << endl;

        // 5. Backtrack path for visualization
        // Create a temporary array to mark the final path
        vector<bool> is_path(w * h, false);

        Point curr = end;
        while (!(curr == start)) {
            int idx = curr.gety() * w + curr.getx(); // Use standard 1D mapping
            is_path[idx] = true;
            curr = map.parent[idx];
        }
        is_path[start.gety() * w + start.getx()] = true; // Mark start

        // 6. Print the final map
        cout << "\n--- Final Map ---" << endl;
        cout << "S: Start, E: End, *: Path, #: Wall, .: Free" << endl;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int idx = y * w + x;

                if (start.getx() == x && start.gety() == y) {
                    cout << "S ";
                }
                else if (end.getx() == x && end.gety() == y) {
                    cout << "E ";
                }
                else if (map.wallmap[idx]) {
                    cout << "# ";
                }
                else if (is_path[idx]) {
                    cout << "* ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
    else {
        cout << "Failed! No path found." << endl;
    }
    map.clear(); // 重置地图状态！

    // 因为 BFS 不保证最短，我们随便设个起点终点
    Point bfs_start(2, 2);
    Point bfs_end(8, 8);
    planner.set_se(bfs_start, bfs_end);

    cout << "Start BFS pathfinding..." << endl;
    if (planner.Bfs(map)) 
    {
        cout << "BFS Success!" << endl;
    }
    else 
        cout << "BFS Failed." << endl;
    return 0;
}