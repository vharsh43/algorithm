#include<iostream>

using namespace std;

#define INF 999

int U, src, cost[100][100];
int dist[100];
bool visited[100] = { 0 };
int Prnt[100];

void init()
{
	for (int x = 0; x < U; x++)
	{
		Prnt[x] = x;
		dist[x] = INF;
	}

	dist[src] = 0;
}

int getNearest()
{
	int minimumValue = INF;
	int minimumNode = 0;

	for (int x = 0; x < U; x++)
	{
		if (!visited[x] && dist[x] < minimumValue)
		{
			minimumValue = dist[x];
			minimumNode = x;
		}
	}

	return minimumNode;
}

void djkAlgorithm()
{
	for (int x = 0; x < U; x++)
	{
		int nearest = getNearest();
		visited[nearest] = true;

		for (int adj = 0; adj < U; adj++)
		{
			if (cost[nearest][adj] != INF && 
				dist[adj] > dist[nearest] + cost[nearest][adj])
			{
				dist[adj] = dist[nearest] + cost[nearest][adj];
				Prnt[adj] = nearest;
			}
		}
	}
}

void display()
{
	cout << "Node:\t\t\tCost :\t\t\tPath";

	for (int x = 0; x < U; x++)
	{
		cout << x << "\t\t\t" << dist[x] << "\t\t\t" << " ";

		cout << x << " ";

		int parnode = Prnt[x];

		while (parnode != src)
		{
			cout << " <-- " << parnode << " ";
			parnode = Prnt[parnode];
		}
		cout << endl;
	}
}

int main(void) {
	cout << "Enter the number of vertives : ";
	cin >> U;

	for (int x = 0; x < U; x++) 
	{
		for (int y = 0; y< U; y++) 
		{
			cin >> cost[x][y];
		}
	}

	cout << "Enter Src Node : ";
	cin >> src;

	init();
	djkAlgorithm();
	display();
}