#include<stdio.h>
#include<string.h>
int adj[20][20]={0},visited[20]={0},n;
void dfs(int node)
{
    int i;
    visited[node]=1;
    printf("%d ",node+1);
    for(i=0;i<n;i++)
    {
        if(adj[node][i]==1 && visited[i]==0)
            dfs(i);
    }
}
void bfs(int node)
{
    int q[20],f=-1,r=-1,nd,i;
    visited[node]=1;
    q[++r]=node;
    while(f!=r)
    {
        nd=q[++f];
        printf("%d ",nd+1);
        for(i=0;i<n;i++)
        {
            if(adj[nd][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                q[++r]=i;
            }
        }
    }
}



void main()
{
    int e,i,v1,v2,node,ch=1;


    printf("Enter no of nodes: ");
    scanf("%d",&n);
    printf("Enter no of edges: ");
    scanf("%d",&e);
    printf("Enter the vertices of each edge:\n");
    for(i=0;i<e;i++)
    {
        printf("Enter the vertices of edge %d: ",i+1);
        scanf("%d %d",&v1,&v2);
        adj[v1-1][v2-1]=adj[v2-1][v1-1]=1;
    }
    printf("Enter starting vertex: ");
    scanf("%d",&node);
    while(ch!=0)
    {
        printf("Enter choice 1:DFS 2:BFS --> ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: memset(visited,0,sizeof(visited));
                         printf("DFS: ");
                         dfs(node-1);
                         break;
            case 2: memset(visited,0,sizeof(visited));
                          printf("BFS: ");
                          bfs(node-1);
                          break;
            default:printf("Invalid Choice\n");
                          break;
        }
        printf("\nDo you want to continue 0.No 1.YES: ");
        scanf("%d",&ch);
    }
    
}


/*

OUTPUT:

Enter no of nodes: 6                                                                                                                                                                                                                 
Enter no of edges: 5                                                                                                                                                                                                                 
Enter the vertices of each edge:                                                                                                                                                                                                     
Enter the vertices of edge 1: 1 2                                                                                                                                                                                                    
Enter the vertices of edge 2: 1 3                                                                                                                                                                                                    
Enter the vertices of edge 3: 2 4                                                                                                                                                                                                    
Enter the vertices of edge 4: 3 5                                                                                                                                                                                                    
Enter the vertices of edge 5: 3 6                                                                                                                                                                                                    
Enter starting vertex: 1                                                                                                                                                                                                             
Enter choice 1:DFS 2:BFS --> 1                                                                                                                                                                                                       
DFS: 1 2 4 3 5 6                                                                                                                                                                                                                     
Do you want to continue 0.No 1.YES: 1                                                                                                                                                                                               
Enter choice 1:DFS 2:BFS --> 2                                                                                                                                                                                                       
BFS: 1 2 3 4 5 6      
Do you want to continue 0.No 1.YES: 0
THANKYOU
*/