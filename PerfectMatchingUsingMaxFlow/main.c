/*
Student Name: Burçak Aðrýdað
Student Number: 201140030
Project Number: 4
Operating System: {Windows[7]}
Compile Status: {Compiling}
Program Status: {Working}

*/

#include <stdio.h>
#include <stdlib.h>
#define max 1000
#define inf 10000000000000
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,node;  //n= the first input from the input file; node= number of nodes
int i, j;
int capacity[max][max]; //capacity matrix
int flow[max][max]; //flow matrix
int visited[max];
int pred[max];
int array[max][max]; //array taken from the user
int nArray[max][max]; //node*node array created
int pArray[max][max]; //perfect matching array(n*n)
int eArray[max][max]; // an empty array to print out when there is no perfect matching
int min(int x, int y)
{
    return x<y ? x: y;
}

int head, tail;
int q[max+2];
void enqueue(int x)
{
    q[tail]= x;
    tail++;
    visited[x]= GRAY;
}
int dequeue()
{
    int x= q[head];
    head++ ;
    visited[x]= BLACK;
    return x;
}

int bfs(int start, int target)
{
    int u, v;
    for(u= 0; u<node ; u++)
    {
        visited[u]= WHITE;
    }
    head= tail= 0;
    enqueue(start);
    pred[start]= -1;
    while(head!=tail)
    {
        u=dequeue();
        for(v= 0; v<node; v++)
        {
            if(visited[v]==WHITE && capacity[u][v]-flow[u][v]>0)
            {
                enqueue(v);
                pred[v]= u;
            }
        }
    }
    return visited[target]== BLACK;
}

int maxFlow(int source, int sink)
{

    int i,j,u;
    int maxFlow= 0;// empty flow
    for( i= 0; i<node ; i++)
    {
        for(j= 0; j<node; j++)
        {
            flow[i][j]= 0;
              pArray[i][j]= 0;
        }
    }
    while(bfs(source, sink))
    {
        int increment = inf;
        for(u= node-1; pred[u]>=0; u=pred[u])
        {
            increment= min(increment, capacity[pred[u]][u]-flow[pred[u]][u]);
        }
        for(u= node-1; pred[u]>=0; u=pred[u])
        {
            flow[pred[u]][u]+= increment;
            flow[u][pred[u]]-= increment;


        }
        int h;
        int ha;
        for(h= 0; h<node; h++)
        {
            for(ha= 0; ha<node; ha++)
            {
                if(flow[h][ha]==1) // if there is a flow btw two nodes, hold that nodes in pArray
                {
                     pArray[h][ha]=1;
                }
            }

        }
        maxFlow+= increment;

    }
    return maxFlow;


}

void read_input_file(const char* inputFile ) {
    int c,i,j;

FILE* input = fopen(inputFile,"r");
fscanf(input,"%d" ,&n);
for(i= 0; i<n ; i++)
    {
        for(j=0; j<n; j++)
        {
            fscanf(input, "%d", &array[i][j]); //reads the given array from the user and stores it in array
        }
    }
node=2*n+2; //total number of nodes

    /*nArray matrix turns the given nxn array into node x node array and initializes
    the sink and source nodes' connections */
    for (i=0; i<node; i++)
    {
	for (j=0; j<node; j++)
        {
	    capacity[i][j] = 0;// empty capacity matrix initialized
	    nArray[i][j]= 0;//all the elements of nArray are initialized to zero
	    eArray[i][j] = 0; //all the elements of nArray are zero
        }
    }

    for(i= 1; i<=n; i++)
    {
        nArray[0][i]=1; //source is connected to the nodes on the left side
    }
    for(i=node-2; i>=n+1; i--)
    {
 nArray[i][node-1]=1;// sink is connected to the nodes on the right side
    }


    for(i= 0; i<n ; i++)
    {
        for(j=0; j<n; j++)
        {
            if(array[i][j]==1)
            {
                nArray[i+1][j+(n+1)]=1; //if there is a connection btw. nodes puts a "1" in nArray
            }
        }
    }
/*initializes the capacities of the connected nodes*/
 for (i=0; i<node; i++)
    {
for(j= 0; j<node; j++)
        {
    if(nArray[i][j]==1)
            {
        capacity[i][j]=1;
            }
        }
    }
    fclose(input);
}
 void print_output_file1(const char* outputFile)
    {
       FILE* output= fopen(outputFile, "wt");
     fprintf(output, "%d\n", n);


    for(i= 1; i<=n; i++)
    {
    for(j= n+1; j<=node-2; j++)
        {
        fprintf(output,"%d", eArray[i][j]);
        }
    fprintf(output,"\n");
    }

fprintf(output,"\n");
}
void print_output_file2(const char* outputFile)
    {

       FILE* output= fopen(outputFile, "wt");
     fprintf(output, "%d\n", &n);


    for(i= 1; i<=n; i++)
    {
    for(j= n+1; j<=node-2; j++)
        {
        fprintf(output, "%d", pArray[i][j]);
        }
    fprintf(output,"\n");
    }

fprintf(output,"\n");
}

int main () {

    read_input_file(argv[1]);

/*for(i= 0; i<n; i++)
    {
    for(j= 0; j<n; j++)
        {
        printf("%d", array[i][j]);

        }
    printf("\n");
    }
    printf("\n");
*/

// printf("%d\n",maxFlow(0,node-1));

if(maxFlow(0,node-1)<3)//If the max flow is not equal to 3, there is no perfect matching
{
    print_output_file1(argv[2]);
}
else
{
   print_output_file2(argv[2]);
/* for(i= 0; i<node; i++)
    {
    for(j= 0; j<node; j++)
        {
        printf("%d", nArray[i][j]);
        }
    printf("\n");
    }
   printf("\n");
 for(i= 0; i<node; i++)
    {
    for(j= 0; j<node; j++)
        {
        printf("%d", nArray[i][j]);
        }
    printf("\n");
    }

printf("\n");
*/



    return 0;
}
}



