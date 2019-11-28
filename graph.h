#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;
class graph
{
	enum COLOR
	{
		WHITE,
		GREY,
		BLACK
	};
	int _directed;
	int _size;
	std::vector  <std::vector<int> > adjList; 
public:
	int cycle_start;
	int cycle_end;
	graph(int size, bool isdirected = true);

	void addEdge(int u, int v);

	bool isdfsCycle(int v, std::vector<int> &visited, std::vector<int> &parent, std::vector< std::vector<int> > &cycle, int &cycleno);
	bool printCycle(std::vector<std::vector < int> > &cycle);
	bool dfsCycleUtil();

};

class graphString
{
	enum COLOR
	{
		WHITE,
		GREY,
		BLACK
	};
	//int _directed;
	//int _size;

	class Node
	{
	public:
		int _num;
		std::string _name;
		bool _isMovie;

		Node(int num, std::string name, bool isMovie) : _num(num), _name(name), _isMovie(isMovie) 
		{
			
		}
		Node()
		{}

		~Node() {}
	};

	std::map<int, Node> hashMap;

	int num;
	std::vector  <std::vector<int> > adjList ;
public:
//	int cycle_start;
	//int cycle_end;
	graphString(int size = 50) { num = 0; adjList.resize(size); };

	void addEdge(std::string u, std::string v);
	void readActMovfile(std::string fileName);
	void displayActMov();
	//bool isdfsCycle(int v, std::vector<int> &visited, std::vector<int> &parent, std::vector< std::vector<int> > &cycle, int &cycleno);
	//bool printCycle(std::vector<std::vector < int> > &cycle);
	//bool dfsCycleUtil();

	void dfsUtil();
	void dfs(int i, std::vector<int> &visited);

	~graphString() {}

};