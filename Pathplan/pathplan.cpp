#include<iostream>
#include<queue>
#include "head.h"
#include "pathplan.h"
#include "Emath.h"
#include<cmath>

using std::queue;
using std::priority_queue;





void Pathplan:: set_se(const Point& start, const Point& end)
{
    this->start = start;
    this->end = end;
}

// BFS 算法（晚上填逻辑）
// 注意：把地图作为 const 引用传进来，绝对不复制！
bool Pathplan::Bfs(Searchmap& map)
{
	vector<int> coords = { -1, 0, 1 };
	auto all_dirs = cartesian_product(coords, coords);
	vector<pair<int, int>> dirs;
	for (const auto& dir : all_dirs)
	{
		if ((dir.first == 0) && (dir.second == 0)) continue;
		dirs.push_back(dir);
	}

	Point current = start;
	// 注意：这里全换成了 map.xxx，并且用了一维索引
	map.visited[start.gety() * map.width + start.getx()] = true;

	std::queue<Point> q;
	q.push(current);

	while (!q.empty())
	{
		current = q.front();
		q.pop();

		if (current == end) return true;

		for (const auto& dir : dirs)
		{
			Point next = current + Point(dir.first, dir.second);
			int x = next.getx();
			int y = next.gety();

			if ((x >= 0) && (x < map.width) && (y >= 0) && (y < map.height) &&
				(map.wallmap[y * map.width + x] == 0))
			{
				if (map.visited[y * map.width + x] == false)
				{
					map.visited[y * map.width + x] = true;
					map.setparent(next, current);
					q.push(next);
				}
			}
		}
	}
	return false;
}

// A* 算法（今晚的重头戏）
bool Pathplan::Astar( Searchmap& map)
{
	vector<int> coords = { -1, 0, 1 };
	auto all_dirs = cartesian_product(coords, coords);//笛卡尔积相乘，得到了3*3=9个方向，但这里包括了（0，0）我们得剔除它
	vector<pair<int, int>> dirs;
	for (const auto& dir : all_dirs)
	{
		if ((dir.first == 0) && (dir.second == 0))
			continue;
		dirs.push_back(dir);
	}
	//获得八个方向
	
	priority_queue<PathNode,vector<PathNode>, CompareNode> pq;//

	Point current = start;//在外面先定义好
	//double value = Point(start.getx(), start.gety()).distance(start) + Point(start.getx(), start.gety()).distance(end);//
	map.g_score[start.getx() + start.gety()*map.width] = 0;//当前值当然是0
	double value = start.distance(end);
	pq.push(PathNode(current, value));
	while (!pq.empty()) 
	{
		current = pq.top().p;//我们就要个点
		pq.pop();
		if (map.visited[current.getx() + map.width * current.gety()] == true)//如果当前的点居然读过，就删掉，直接下一个循环。	
			continue;
		else
			map.visited[current.getx() + map.width * current.gety()] = true;//标记已读
		//以上是Astar的延迟删除
		
		if (current == end)//如果队列空了，就没法跑了，报错。
			return true;
		for (const auto& dir : dirs)
		{
			Point next = current + Point(dir.first, dir.second);
			int x = next.getx();
			int y = next.gety();
			if ((x >= 0) && (x < map.width) && (y >= 0) &&
				(y < map.height) && (map.wallmap[x + map.width * y] == 0))//不能越界！且不能是墙
			{
				double new_g = sqrt(abs(dir.first) + abs(dir.second)) + map.g_score[current.getx() + map.width * current.gety()];//距离步长 + 历史使用;
				//value_current
				//进入队列
				if (map.g_score[x + map.width * y] >new_g)
				{
					map.g_score[x + map.width * y] = new_g;
					map.setparent(next, current);

					double value = new_g + Point(x, y).distance(end);// 已知数据+ 预估未来
					pq.push(PathNode(next,value));
				}
			}
		}
		//上面都和BFS几乎一样，但是接下来才是重点，怎么挑
	}
    return false; // 没找着
}