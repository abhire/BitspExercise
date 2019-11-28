#include "graph.h"
#include <fstream>
#include <string>

graph::graph(int size, bool isdirected)
{
	adjList.resize(size);
	_size = size;
	_directed = isdirected;
}

void graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);

	if (!_directed)
		adjList[v].push_back(u);
}

bool graph::isdfsCycle(int v, std::vector<int>& visited, std::vector<int> &parent, std::vector<std::vector <int> > &cycle, int &cyclelNo)
{
	visited[v] = GREY;

	int size = adjList[v].size();

	for (int i = 0; i < size; i++)
	{
			
		if (visited[adjList[v][i]] == WHITE)
		{
			parent[adjList[v][i]] = v;
			isdfsCycle(adjList[v][i], visited, parent, cycle, cyclelNo);
		}

		if (visited[adjList[v][i]] == GREY && adjList[v][i] != parent[v]) // partial visited inside the recursion
		{
			cyclelNo ++;
			int curr = v;
			int end = adjList[v][i];
			
			cycle[cyclelNo].push_back(end);
			
			while (curr != end)
			{
				cycle[cyclelNo].push_back(curr);
				curr = parent[curr];
			}
		}
	}

	visited[v] = BLACK;
	return false;
}
bool graph::printCycle(std::vector<std::vector <int> > &CycleMap)
{
	cout << "================detecting  cycle ================" << endl;
	
	int count = 0;
	bool found = false;
	
	for (int i = 0; i < _size; i++)
	{
		if (CycleMap[i].size())
		{
			found = true;
			cout << "\n Cycle found ------\n";

			for (int j = 0; j < CycleMap[i].size(); j++)
			{
				cout << CycleMap[i][j] << " ";
			}


			cout << "\n Cycle ends \n";
		}
	}

	if (!found)
		cout << "\n No cycles found";

	return true;
}

bool graph::dfsCycleUtil()
{
	std::vector<int> parent(_size, -1);

	std::vector<int> visited(_size, WHITE);

	std::vector<std::vector< int>>  cycle(_size); // maximum cycles can be lesser than size
	int cycleno =-1;

	for (int i = 0; i < _size; i++)
	{
		isdfsCycle(i, visited, parent, cycle, cycleno);
		
	}

	printCycle(cycle);

	//cout << cycle_end;



	return false;
}

void graphString::addEdge(std::string movie, std::string actor)
{
	bool isMovieFound = false;
	bool isActorFound = false;

	int movieNum = -1;
	int actorNum = -1;
	auto itr = hashMap.begin();

	while (itr != hashMap.end())
	{
		if (itr->second._name == movie)
		{
			isMovieFound = true;
			movieNum = itr->second._num;
		}

		if (itr->second._name == actor)
		{
			isActorFound = true;
			actorNum = itr->second._num;
		}

		++itr;
	}



	if (!isMovieFound) {
		Node x(num++, movie, true);
		hashMap[x._num] = x;
		movieNum = x._num;
	}

	if (!isActorFound) {
		Node y(num++, actor, false);
		hashMap[y._num] = y;
		actorNum = y._num;
	}

	
	

	adjList[movieNum].push_back(actorNum);
	adjList[actorNum].push_back(movieNum);
}



void graphString::readActMovfile(std::string fileName)
{
	string line;
	ifstream myfile(fileName.c_str());
	if (myfile.is_open())
	{
		std::vector<std::string> movie;
		while (getline(myfile, line))
		{
			char * pch;
			pch = strtok( (char*)line.c_str(), "/");
			
			bool isFirst = false;
			
			std::string movie;
			std::vector<std::string> actors;

			while (pch)
			{
				if (!isFirst)
				{
					isFirst = true;
					movie = pch;
				} else {
					actors.push_back(pch);
				}
				pch = strtok(NULL, "/");
			}
		 
			for (int i = 0; i < actors.size(); i++)
			{
				addEdge(movie, actors[i]);
			}
		}
		myfile.close();
	}

}

void graphString::displayActMov()
{
	
}

void graphString::dfsUtil()
{
	std::vector<int> visited(adjList.size(), 0);

	for (int i = 0; i < adjList.size(); i++)
	{
		if (visited[i] == 0)
		{
			dfs(i, visited);
		}

	}
}

void graphString::dfs(int i, std::vector<int>& visited)
{
	visited[i] = 1;

	auto itr = adjList[i].begin();

	while (itr != adjList[i].end())
	{
		if (visited[*itr] == 0)
		{
			dfs(*itr, visited);
		}
		++itr;
	}
}
