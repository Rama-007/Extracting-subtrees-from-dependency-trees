#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<cmath>
#define min(a,b) a<b?a:b
#define ll long long
#define mod 1000000007
using namespace std;
typedef struct node
{
	int posi;
	char name1[10024],name2[10024] ,pos[10024],tag[10024],info[10024];
	int tree;
	char relation[10024] , unknown[10024] ,moreinfo[10024],chunkid[100];
}node;

typedef struct level
{
	char name1[10024], name2[10024],pos1[10024],pos2[10024],chunkid1[10024],chunkid2[10024],relation[10024];
}level;

typedef struct levelh
{
	char name1[10024],pos1[10024],chunkid1[10024],relation[10024],other[10024];
}levelh;

int f[1000];



class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    f[v]=v;
    //cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;	
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}
char buff[100];
char *getchunk(char a[100])
{
	int l=strlen(a);
	int j,k=0,flag=0;
	for(int i=0;i<l-2;i++)
	{
		if(a[i]=='C' && a[i+1]=='h')
		{
			j=i;
			k=1;
			i=i+2;
		}
		while(k)
		{
			if(a[i]=='|')
			{
				flag=1;
				break;
			}
			i++;
		}
		if(flag==1)
		{
			strncpy(buff,a+j,i-j);
			return buff;
		}
	}
}
int main()
{
	int len;
	std::vector<level> level0[10000];
	std::vector<levelh> levellh[10000];
		//Graph g(1000);
	std::vector< string > groupcp[10000];
	//std::map<int, char*> groupno;
	int t;
	cin>>t;
	while(t--)
	{
	map <int ,int> parent;	
	cin>>len;
	Graph g(len+2);
	int edgecount[len+1];
	memset(edgecount,0,sizeof(edgecount));
	node *a[len];

	std::vector<int> child[len+1];
	int flg[len+1];
	memset(flg,0,sizeof(flg));
	char groupno[1000][1000];
	for (int i=0;i<len;i++)
	{
		a[i]=(node*)malloc(sizeof(node));
		cin>> a[i]->posi >> a[i]->name1 >> a[i]->name2 >> a[i]->pos >> a[i]->tag >> a[i]->info >> a[i]->tree;
		cin>> a[i]->relation >> a[i]->unknown >> a[i]->moreinfo;
		strcpy(a[i]->chunkid,getchunk(a[i]->moreinfo));
		g.addEdge(a[i]->tree,a[i]->posi);
		parent[a[i]->posi]=a[i]->tree;
		edgecount[a[i]->tree]++;
		child[a[i]->tree].push_back(a[i]->posi);
	}
	for(int i=0;i<len;i++)
	{
		char tmp[100];
		if(edgecount[a[i]->posi]==0)
		{
		//	cout<<a[i]->posi<<" "<<parent[a[i]->posi] <<endl;	
			for(int j=0;j<100000;j++)
			{
				if(level0[j].empty())
				{
					level0[j].push_back(level());
					strcpy(level0[j][0].name1,a[i]->name1);
					strcpy(level0[j][0].name2,a[parent[a[i]->posi]-1]->name1);
					strcpy(level0[j][0].pos1,a[i]->pos);
					strcpy(level0[j][0].pos2,a[parent[a[i]->posi]-1]->pos);
					strcpy(level0[j][0].relation,a[i]->relation);
					strcpy(level0[j][0].chunkid1,a[i]->chunkid);
					strcpy(level0[j][0].chunkid2,a[parent[a[i]->posi]-1]->chunkid);
					sprintf(tmp,"level0[%d]",j);
					strcpy(groupno[parent[a[i]->posi]],tmp);
					//groupno[a[i]->posi]=tmp;
					groupcp[parent[a[i]->posi]].push_back(tmp);
					flg[a[i]->posi]=1;
					break;
				}
				else
				{
					level temp;
					strcpy(temp.name1,a[i]->name1);
					strcpy(temp.name2,a[parent[a[i]->posi]-1]->name1);
					strcpy(temp.pos1,a[i]->pos);
					strcpy(temp.pos2,a[parent[a[i]->posi]-1]->pos);
					strcpy(temp.relation,a[i]->relation);
					strcpy(temp.chunkid1,a[i]->chunkid);
					strcpy(temp.chunkid2,a[parent[a[i]->posi]-1]->chunkid);
					if(strcmp(level0[j][0].pos1,a[i]->pos)==0 && strcmp(level0[j][0].pos2,a[parent[a[i]->posi]-1]->pos)==0 && strcmp(level0[j][0].relation,a[i]->relation)==0 && strcmp(level0[j][0].chunkid1,a[i]->chunkid)==0 && strcmp(level0[j][0].chunkid2,a[parent[a[i]->posi]-1]->chunkid)==0)
					{
						level0[j].push_back(temp);
						sprintf(tmp,"level0[%d]",j);
						strcpy(groupno[parent[a[i]->posi]],tmp);
						groupcp[parent[a[i]->posi]].push_back(tmp);
						flg[a[i]->posi]=1;
						break;
					}
				}
			}
		}
		cout<<"CommonPoint"<<endl;
	for(int j=0;j<len;j++)
	{
		std::vector<string>::iterator it;
		it = std::unique (groupcp[j].begin(), groupcp[j].end());
		groupcp[j].resize( std::distance(groupcp[j].begin(),it) );

		for (std::vector<string>::const_iterator i = groupcp[j].begin(); i != groupcp[j].end(); ++i)
    std::cout << *i << ' ';
	//cout<<endl;
	cout<<endl;
	}

	}
cout<< "Subtrees of ";
for(int i=0;i<len;i++)
{
	cout<<a[i]->name1<<" ";
}
cout<<endl;
for(int i=0;i<len+1;i++)
	{
		std::vector<int> k;
		memset(f,-1,sizeof(f));
		g.DFS(i);
		for(int j=0;j<1000;j++)
		{
			if(f[j]!=-1 &&  f[j]!=0)
				k.push_back(f[j]);
		}
		sort(k.begin(),k.end());
		for(std::vector<int>::iterator it=k.begin();it!=k.end();++it)
		{
			cout<< a[*it -1]->name1 << " ";
		}
		cout<<endl;
	}
cout<< "##############################################" << endl;

	for(int i=0;i<len;i++)
	{
		char tmp[1000];
		string tokka;
		if(edgecount[a[i]->posi]!=0)
		{
			//cout<<a[i]->posi<<" "<<parent[a[i]->posi] <<endl;	
			for(int j=0;j<10000;j++)
			{
				int k=a[i]->posi -1;
				if(k<0)
					k=0;
				int ff=parent[a[i]->posi]-1;
				if(ff<0)
					ff=0;
				if(levellh[j].empty())
				{
					
					levellh[j].push_back(levelh());
					strcpy(levellh[j][0].name1,a[i]->name1);
					strcpy(levellh[j][0].pos1,a[i]->pos);
					strcpy(levellh[j][0].relation,a[i]->relation);
					strcpy(levellh[j][0].chunkid1,a[k]->chunkid);
					strcpy(levellh[j][0].other,groupno[a[i]->posi]);
					sprintf(tmp,"levellh[%d]",j);
					strcpy(groupno[a[i]->posi],tmp);
					//groupno[a[i]->posi]=tmp;
					groupcp[parent[a[i]->posi]].push_back(tmp);
					break;
				}
				else
				{
					levelh temp;
					strcpy(temp.name1,a[parent[k]]->name1);
					strcpy(temp.pos1,a[parent[k]]->pos);
					strcpy(temp.relation,a[i]->relation);
					strcpy(temp.chunkid1,a[parent[k]]->chunkid);
					strcpy(temp.other,groupno[a[i]->posi]);
					if(strcmp(levellh[j][0].pos1,a[ff]->pos)==0 && strcmp(levellh[j][0].relation,a[i]->relation)==0 
						&& strcmp(levellh[j][0].chunkid1,a[ff]->chunkid)==0 && strcmp(levellh[j][0].other,groupno[a[i]->posi])==0)
					{
						levellh[j].push_back(temp);
						sprintf(tmp,"levellh[%d]",j);
						//groupno[a[i]->posi]=tmp;
						strcpy(groupno[a[i]->posi],tmp);
						groupcp[parent[a[i]->posi]].push_back(tmp);
						break;
					}
				}
			}	
		}
	}
	for(int i=0;i<len+1;i++)
	{
		g.DFS(i);
		cout<<endl<<endl;
	}


}

	for(int i=0;i<10000;i++)
	{
		if(!level0[i].empty())
		{
			printf("level0[%d] :",i );
			cout<<level0[i][0].pos1<<' ' << level0[i][0].pos2<<" "<<level0[i][0].chunkid1<<" "<<level0[i][0].chunkid2<<" "<<level0[i][0].relation<<endl;
		for(int j=0;j<3;j++)
		{
			//cout<<i << " "<<j<<endl;
			if(level0[i][j].name1!="")
				cout<<level0[i][j].name1<<" "<<level0[i][j].name2<<endl;
		}
	}
	} 

	for(int i=0;i<10000;i++)
	{
		if(!levellh[i].empty())
		{
			cout<<levellh[i][0].pos1<<" "<<levellh[i][0].chunkid1<<" "<<levellh[i][0].relation<<levellh[i][0].other<<endl;
		for(int j=0;j<2;j++)
		{
			//cout<<i << " "<<j<<endl;
			if(levellh[i][j].name1!=NULL)
				cout<<levellh[i][j].name1<<" "<<levellh[i][j].other<<endl;
		}
	}
	}
	

	
}

