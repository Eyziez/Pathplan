#include<iostream>
#include "head.h"

//int width, height;
//vector<vector<bool>> wallmap;
//vector<vector<bool>> isread;
//vector<vector<Point>> father;
//double value;我思考了一下，可能要设置成vector<vector<Double>>，但我先删除,因为虽然python我可能就是这么干的，但是Double占用空间还是太凶了，也许老师你有更好的办法

Searchmap::Searchmap(int width, int height)//初始化
{
	this->width = width;
	this->height = height;
	this->clear();
	
}
void Searchmap::clear()//用来清空大地图的全部东西
{
	wallmap.resize(width, vector<bool>(height, false));
	isread.resize(width, vector<bool>(height, false));
	father.resize(width, vector<Point>(height, Point(-1,-1)));
}
void Searchmap::init(vector<vector<bool>>& wallmap)
{	
	this->wallmap = wallmap;//把二维数组丢进去
}
void Searchmap::setFather(Point& child, Point& elder)//有father了，用另一个词代替一下
{
	father[child.getx()][child.gety()] = elder;
}
bool Searchmap::Bfs(Point& start, Point& end)
{
	//明早待续
}