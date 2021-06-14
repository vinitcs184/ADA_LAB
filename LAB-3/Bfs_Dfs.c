#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int n;

// Implementation of queue for bfs
int queue[10] , front = -1 , rear = -1;

bool q_empty()
{
    if(front == rear && front == -1)
        return true;
    return false;
}

void insert(int n)
{
    if(q_empty())
        front = 0;
    queue[++rear] = n;
}

int delete()
{
    int x = queue[front];
    if(!q_empty())
    {
        if(front == rear)
            front = rear = -1;
        else
            ++front;
    }
    return x;
}

// Implementation of stack for dfs
int stack[100] , top = -1;

bool s_empty()
{
    if(top == -1)
        return true;
    return false;
}

void push(int n)
{
    stack[++top] = n;
}

int pop()
{
    return stack[top--];
}

// Breadth First Search
void bfs(int node , bool visited[] , int adj[n][n])
{
    int x;
    insert(node);
    visited[node] = true;
    while(!q_empty())
    {
        x = delete();
        printf("%d ",x);
        for(int i = 0; i < n; i++)
        {
            if(adj[x][i] == 1 && (!visited[i]))
            {
                insert(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// Depth First Search
void dfs(int node , bool *visited , int adj[n][n])
{
    int x;
    push(node);
    visited[node] = true;
    while(!s_empty())
    {
        x = pop();
        for(int i = 0; i < n; i++)
        {
            if(adj[x][i] == 1 && (!visited[i]))
            {
                push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int node , cnt = 0;
    clock_t start,end;
    double t;

    // Number of nodes in the graph
    scanf("%d",&n);

    int adj[n][n];
    bool visited[n];

    // Adjacency matrix
    for(int i = 0; i < n ; i++)
    {
        visited[i] = false;
        for(int j = 0; j < n; j++)
            scanf("%d",&adj[i][j]); 
    }

    // Starting node
    scanf("%d",&node);

    // Printing nodes that are reachable from a given node
    printf("The nodes reachable are: ");
    start = clock();
    bfs(node,visited,adj);
    end = clock();
    t=((double)(end-start))/(double)CLOCKS_PER_SEC; 
    printf("Time taken for bfs is %.5f\n",t);

    for(int i = 0; i < n; i++)
        visited[i] = false;

    // Finding the number of connected components
    start = clock();
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            ++cnt;
            dfs(i,visited,adj);
        }
    }
    end = clock();
    t=((double)(end-start))/(double)CLOCKS_PER_SEC;
    printf("The number of connected components in the graph is : %d\n",cnt);
    printf("Time taken for dfs is %.5f\n",t);
}
