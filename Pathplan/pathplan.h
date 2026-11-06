#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <functional> 
#include "head.h"

using std::vector;


struct PathNode
{
    Point p;
    double value; // 这里的 value 就是你 A* 算法里的 f 值
};

struct CompareNode
{
    bool operator()(const PathNode& a, const PathNode& b) 
    {
        return a.value > b.value; // 注意这里的大于号！
    }
};

class Pathplan
{
private:
    Point start;
    Point end;
    vector<Point> path;
public:
    // 默认构造函数
    Pathplan() {}
    void set_se(const Point& start, const Point& end);
    bool Bfs( Searchmap& map);
    bool Astar( Searchmap& map);
};