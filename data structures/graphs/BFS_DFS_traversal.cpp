//BFS traversal:Breadth-first search also reffered as level order traversal.
//BFS is a traversal technique in which all the nodes of the same level are explored first, and then we move to the next level.

//DFS traversal: Depth first search.
//DFS is also a traversal technique in which traversal is started from the root node and explore the nodes as far as possible 
//until we reach the node that has no unvisited adjacent nodes.


#include <iostream>
#include<queue>
using namespace std;

void printdfs(int **edges,int n, int sv, bool*visited)
{
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(i==sv){
			continue;
			
		}
		if(edges[sv][i]==1)
		{
		
			if(visited[i])
			{
				continue;
			}
	    
			printdfs(edges,n,i,visited);
		}
	}

}

void printbfs(int **edges,int n, int sv, bool*visited)
{
	queue<int>vertices;
	vertices.push(sv);
	visited[sv]=true;
	while(vertices.size()!=0)
	{
		int front=vertices.front();
		cout<<front<<" ";
		vertices.pop();
		for(int i=0;i<n;i++)
	{
		if(i==sv){
			continue;
			
		}
		if(edges[front][i]==1)
		{
		
			if(visited[i])
			{
				continue;
			}
	    
			visited[i]=true;
			vertices.push(i);
		}
	}

		
		
	}
}


int main()
{
	int n,e;
	cout<<"Enter the number of vertices and edges:"<<endl;
	cin>>n>>e;
	
	int **edges =new int* [n];
	for(int i=0; i<n; i++)
	{
		edges[i]= new int[n];
		for (int j=0; j<n; j++)
		{
			edges[i][j]=0;
		}
	}
	for (int i=0;i<e;i++)
	{
		int f,s;
		cin >>f >> s;
		edges[f][s]=1;
		edges[s][f]=1;
		
	}
	
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	
	cout<<"THE DFS TRAVERSAL FOR THE GIVEN GRAPH IS:"<<endl;
	printdfs(edges, n, 0, visited);

	cout<<"THE BFS TRAVERSAL FOR THE GIVEN GRAPH IS:"<<endl;
	printbfs(edges,n,0,visited);
    
}