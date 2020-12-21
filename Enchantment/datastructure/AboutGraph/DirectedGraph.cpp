#include <bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 100
#define STACKNCREMRNT 10

#define MAX_TREE_SIZE 100
#define MAXN 10006

#define MAX_VERTEX_NUM 20

// typedef struct ArcNode{
//     int adjvex;
//     struct ArcNode *nextarcarc;
//     InfoTyoe *info;
// }ArcNode;

// typedef struct VNode{
//     VertexType data;
//     ArcNode *firstarc;
// }VNode,AdjList[MAX_VERTEX_NUM];

// typedef struct{
//     AdjList vertices;
//     int vexnum,arcnum;
//     int kind;
// }MMGraph,*MMGraphList;


// int visited[MAX];
// Status (*VisitFunc)(int v);

// void DFSTraverse(MMGraph G,Status(*Visit)(int v)){
//     visitFunc=Visit;
//     for(v=0;v<G.vexnum;v++)
//         visited[v]=FALSE;
//     for(v=0;v<G.vexnum;v++)
//         if(!visited[v])
//             DFS(G,v);
// }

// void DFS(MMGraph G, int v){
//     visited[v]=TRUE;
//     VisitFunc(v);
//     for(w=FirstAdjVex(G,v);w>=0;w=nextarcAdjVex(G,v,w))
//         if(!visited[w])
//             DFS(G,w);
// }

// void BFSTraverse(MMGraph G, Status (*Visit)(int v)){
//     for(v=0;v<G.vexnum;v++)
//         visited[v]=FALSE;
//     InitQueue(Q);
//     for(v=0;v<G.vexnum;v++){
//         if(!visited[v]){
//             visited[v]=TRUE;
//             Visit(v);
//             EnQueue(Q,v);
//             while(!QueueEmpty(Q)){
//                 PopQueue(Q,v);
//                 for(w=FirstAdjVex(G,u);w>=0;w=nextarcAdjVex(G,u,w))
//                     if(!Visited[w]){
//                         visited[w]=TRUE;
//                         Visit(w);
//                         EnQueue(Q,w);
//                     }
//             }
//         }
//     }
// }

// #include<bits/stdc++.h>
// #include<iostream>               ///深度优先搜索，通过有向图的邻接表存储
// #include<malloc.h>               ///有向图的邻接表中，第i个链表的的结点数只是顶点vi的出度，为求入度，必须遍历整个邻接表或是建立有向图的逆邻接表
 
// #define MAX_VERTEX_NUM 20
// #define MAX_NAME 5
// #define OK 1
// #define TRUE 1
// #define FALSE -1
// typedef char VertexType[MAX_NAME];    
// typedef int InfoType;       
 
// using std::cin;
// using std::cout;
// using std::endl;
// typedef struct ArcNode                           //单链表中结点的类型
// {
// 	int adjvex;                              //该边指向的顶点在顺序表中的位置
// 	struct ArcNode *nextarcarc;  
// 	InfoType *info;                          //网的权值指针
// }ArcNode;
 
// typedef struct VNode                             //定义顶点类型
// {
// 	VertexType data;
// 	ArcNode *firstarc; 
// }VNode, AdjList[MAX_VERTEX_NUM];
 
// typedef struct      
// {	AdjList vertices;                        //顺序表
// 	int vexnum, arcnum;    
// 	int kind;
// }MMGraph;
// int LocateVex(MMGraph &G, VertexType &u)         //返回顶点u在vertices中的位置
// {
//    for(int i = 0;i < G.vexnum; ++i)
//    {
// 	   if(strcmp(G.vertices[i].data,u) == 0)
// 		   return i;
//    }
//    return FALSE ;
// }
 
// int CreateDG( MMGraph &G )                       //有向图的邻接表
// {
//    int  i,j,k,w;
//   VertexType v1,v2;
//    cout <<"node number:";
// 	cin >> G.vexnum;
// 	cout << "edge number:";
// 	cin >> G.arcnum;
//   cout <<"all nodes:\n";
//   for(i = 0; i < G.vexnum; ++i)
// 	{
// 	        //cout << "请输入第"<< i+1 << "个顶点:";
// 			scanf("%s",G.vertices[i].data);
// 		G.vertices[i].firstarc = NULL;
// 	}
//   cout <<"请输入弧，例如 v1-->v2\n";
//   for(k = 0; k < G.arcnum; ++k)
// 	{
//            cout << "请输入第" << k+1 << "条弧的弧尾";
// 	   cin >> v1;
// 	   cout << "请输入第" << k+1 << "条弧的弧头";
// 	   cin >> v2;
//            i = LocateVex(G,v1);
// 	   j = LocateVex(G,v2);
// 	   ArcNode *p;
// 	   p = (ArcNode *)malloc(sizeof(ArcNode));
// 	   if(!p)
// 	   {
// 		   cout << "Overflow";
// 		   return 0;
// 	   }
// 	   p->adjvex = j;
// 	   p->nextarcarc = G.vertices[i].firstarc;       //单链表的逆序构造，即输入的第一个结点会成为最后一个结点
// 	   G.vertices[i].firstarc  = p;
// 	   p->info = NULL;
// 	}   // for end
	  
 
       
//    return OK;
// }  // CreateDG() end
 
// void DFS(MMGraph G, int v, int *visited)              //如果该图是连通图，只需从G.vertices[0]出发便可以遍历图中的所有节点
// {                                                     
//         ArcNode *p;
// 	int w;
// 	visited[v] = TRUE;
// 	cout << v + 1 << "->";
// 	for(p = G.vertices[v].firstarc; p != NULL; p = p->nextarcarc)
// 	{
// 		if(visited[p->adjvex] == 0)
// 		{
// 			visited[p->adjvex] = 0;
// 			DFS(G, p->adjvex,visited);   //不断的访问节点的邻接点
// 		}
// 	}
 
		       
// }  // DFS() end
// void DFSTraverse( MMGraph &G )
// {
// 	int v;
// 	int visited[MAX_VERTEX_NUM];
// 	for( v = 0; v < G.vexnum; ++v )
// 		visited[v] = 0;                       //visited 为辅助数组用于标记顶点是否被访问
// 	for( v = 0; v < G.vexnum; ++v )
// 		if(visited[v] == 0 )
// 			DFS(G,v,visited); 
// }//DFSTraverse() end
// void DestroyMMGraph(MMGraph &G)                      //销毁分配的空间
// {
//     ArcNode *q;
//     for(int i = 0; i < G.vexnum; ++i)
// 	    for(ArcNode *p = G.vertices[i].firstarc; p != NULL;)
// 	    {
// 	      G.vertices[i].firstarc = NULL;
// 	      q = p;
//               p = p->nextarcarc;
//               free(q);
	      
// 	    }
// }
// int main()
// {
// 	MMGraph G;
// 	cout << endl << "DFSTraverse.cpp";
// 	cout << endl << "===================" << endl;
// 	CreateDG(G);   
// 	cout <<"DFS：\n";
// 	DFSTraverse(G);
//         DestroyMMGraph(G);
 
// }// main end


typedef char VertexType;
int visited[ MAX_VERTEX_NUM];

typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
	VertexType data;
	ArcNode *firstedge;
} VNode,AdjList[ MAX_VERTEX_NUM];

typedef struct MGraph {
	AdjList adjList;
	int vexnum,arcnum;
} MGraph,*MGraphList;

//================================================================================
typedef struct CircularQueue {
	int data[ MAX_VERTEX_NUM];
	int front,rear;
} CircularQueue,*Queue;

void initQueue(Queue &Q) {
	Q->front=Q->rear=0;
}

int QueueEmpty(Queue &Q) {
	if(Q->front == Q->rear) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int QueueFull(Queue &Q) {
	if((Q->rear+1)% MAX_VERTEX_NUM == Q->front) {
		return TRUE;
	} else {
		return FALSE;
	}
}



void EnQueue(Queue &Q,int e) {
	if(!QueueFull(Q)) {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear+1)% MAX_VERTEX_NUM;
	}
}



void PopQueue(Queue &Q,int *e) {
	if(!QueueEmpty(Q)) {
		*e = Q->data[Q->front];
		Q->front = (Q->front+1)% (MAX_VERTEX_NUM);
	}
}

//================================================================================

void CreateGraph(MGraphList &G) {
	int i, j, k;
	if(G==NULL) {
		G = (MGraphList)malloc(sizeof(MGraph));
	}
	scanf("%d%d",&G->vexnum,&G->arcnum);
    getchar();
	for (i=0; i<G->vexnum; ++i) {
		printf("Vertex %d: ",i+1);
		scanf("%c", &(G->adjList[i].data));
		G->adjList[i].firstedge = NULL;
        getchar();
	}
	ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));	//printf("===========================\n");
	for (k=0; k<G->arcnum; ++k) {
		printf("Input two vertexs of all edge:\n");
		scanf("%d%d",&i,&j);
		p->adjvex = j;
		p->nextarc = G->adjList[i].firstedge;
		G->adjList[i].firstedge = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = G->adjList[j].firstedge;
		G->adjList[j].firstedge = p;
	}
}

//================================================================================

void DFS(MGraphList &G, int v) {
	visited[v] = TRUE;
	printf("%c", G->adjList[v].data);

	ArcNode *p = G->adjList[v].firstedge;
	while(p) {

		if(!visited[p->adjvex]) {
			DFS(G,p->adjvex);
		}
		p= p->nextarc;
	}
}

void DFSTraverse(MGraphList &G) {
	int v;
	for (v=0; v<G->vexnum; ++v) {
		visited[v] = FALSE;
	}
	for (v=0; v<G->vexnum; ++v) {
		if(!visited[v]) {
			DFS(G,v);
		}
	}
    printf("\n");
}

//================================================================================

void BFSTraverse(MGraphList &G) {
	int v;
	Queue Q = (Queue)malloc(sizeof(CircularQueue));

	for (v=0; v<G->vexnum; ++v) {
		visited[v] = FALSE;
	}
	initQueue(Q);

	for (v=0; v<G->vexnum; ++v) {
		if(!visited[v]) {
			visited[v] = TRUE;
			printf("%c", G->adjList[v].data);
			EnQueue(Q, v);

			while (!QueueEmpty(Q)) {
				PopQueue(Q, &v);
				ArcNode *p = G->adjList[v].firstedge;
				while (p) {
					if (!visited[p->adjvex]) {
                        visited[p->adjvex] = TRUE;
						printf("%c", G->adjList[p->adjvex].data);
						EnQueue(Q, p->adjvex);
					}
					p = p->nextarc;
				}
			}
		}
	}
}

//================================================================================

int main() {
	MGraphList G=NULL;
	printf("Vertex num and edge num?\n");
	CreateGraph(G);
	printf("The sequence by DFS: ");
	DFSTraverse(G);
	printf("The sequence by BFS: ");
	BFSTraverse(G);


	return 0;
}
//================================================================================

/*
6 7
1
2
3
4
5
6
1 2
1 4
1 6
2 5
3 5
4 5
6 3
*/