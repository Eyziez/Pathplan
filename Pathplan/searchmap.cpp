#include<iostream>
#include<queue>
#include "head.h"
#include "Emath.h"

using std::pair;
using std::vector;
using std::queue;

//int width, height;
//vector<vector<bool>> wallmap;
//vector<vector<bool>> visited;
//vector<vector<Point>> parent;
//double value;我思考了一下，可能要设置成vector<vector<Double>>，但我先删除,因为虽然python我可能就是这么干的，但是Double占用空间还是太凶了，也许老师你有更好的办法
bool Point:: operator==(const Point& other) const
{
	return (this->x == other.x) && (this->y == other.y);
}
Point Point:: operator+(const Point& other) const
{
	return Point((this->x + other.x), (this->y + other.y));
}
Point Point:: operator-(const Point& other) const
{
	return Point((this->x - other.x), (this->y - other.y));
}

Searchmap::Searchmap(int width, int height)//初始化
{
	this->width = width;
	this->height = height;
	this->clear();
	
}
void Searchmap::clear()//用来清空大地图的全部东西
{
	wallmap.assign(width*height,false);
	visited.assign(width * height, false);
	parent.assign(width * height,  Point(-1,-1));
	g_score.assign(width * height, 2147483247);
}
void Searchmap::init(vector<bool>& wallmap)
{	
	this->wallmap = wallmap;//把二维数组丢进去
}
void Searchmap::setparent(Point& child, Point& elder)//有parent了，用另一个词代替一下
{
	parent[child.getx() + child.gety() *width] = elder;
}
