#pragma once
#include<iostream>
#include<vector>

using std::vector;

class Point
{
private:
	int x, y;
public:
	Point() : x(0), y(0) {};
	Point(int x, int y);
	void set(int x, int y);
	int getx() const;
	int gety() const;
	double distance(const Point& other);
	bool operator==(const Point& other) const;
	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	
};

class Searchmap
{
private:
	
	//double value;我思考了一下，可能要设置成vector<vector<Double>>，但我先删除,因为虽然python我可能就是这么干的，但是Double占用空间还是太凶了，也许老师你有更好的办法
public:
	int width, height;
	vector<double> g_score;
	vector<bool> wallmap;
	vector<bool> visited;
	vector<Point> parent;
	Searchmap(int width, int height);
	void clear();//用来清空大地图的全部东西
	void init(vector<bool> &wallmap);
	void setparent(Point &child, Point &elder);
	bool Bfs(Point& start, Point& end);


};
