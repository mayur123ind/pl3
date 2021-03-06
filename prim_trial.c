/*
	Title:Implement Prims algorithm using openmp
	Class:TE B
	Roll no:20
*/

#include<stdio.h>
#include<omp.h>
 
int a,b,u,v,n,i,j,ne=1,id;
int visited[10]={0},min,mindis=0,dis[10][10];
double start_time,total_time;
 
void main()
{
	//clrscr();
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
 			scanf("%d",&dis[i][j]);
 			if(dis[i][j]==0)
 				dis[i][j]=999;
		}
	}
	 
	printf("\n Adjacency matrix is:\n");
	for(i=1;i<=n;i++)
	{
	 	for(j=1;j<=n;j++)
	 	{
	 		printf("%d\t",dis[i][j]);
 	 	}
 	 	printf("\n");
 	}
	visited[1]=1;
 	printf("\n");
 	
 	start_time=omp_get_wtime();
      while(ne<n)
	{
		#pragma omp parallel sections
		{
			for(i=1,min=999;i<=n;i++)
 			{
				for(j=1;j<=n;j++)
 				{
					if(dis[i][j]<min)
 					{
						if(visited[i]!=0)
						{
							min=dis[i][j];
							a=u=i;
							b=v=j;
							id=omp_get_thread_num();
						}
					}
				}
			}
		}	 	
		if(visited[u]==0 || visited[v]==0)
 		{
 			printf("\n Thread %d: \n Edge %d:(%d %d) distance:%d \n",id,ne++,a,b,min);
 			mindis+=min;
 			visited[b]=1;
 		}
 		dis[a][b]=dis[b][a]=999;
 		for(i=1;i<=n;i++)
		{
	 		for(j=1;j<=n;j++)
	 		{
	 			printf("%d\t",dis[i][j]);
 	 		}
 	 		printf("\n");
 		}
 	}
 		
	total_time=omp_get_wtime()-start_time;
        printf("\nTotal Time :%f",total_time); 
 	printf("\n Minimum distance=%d \n",mindis);
}


/*Output:
unix@unix-HP-280-G1-MT:~$ gcc -fopenmp prim_trial.c
unix@unix-HP-280-G1-MT:~$ ./a.out

Enter the number of nodes:4

Enter the adjacency matrix:
0
4
2
5
4
0
4
3
2
4
0
6
5
3
6
0





Adjacency matrix is:
999	4	2	5	
4	999	4	3	
2	4	999	6	
5	3	6	999	


 Thread 2: 
 Edge 1:(1 3) distance:2 
999	4	999	5	
4	999	4	3	
999	4	999	6	
5	3	6	999	

 Thread 2: 
 Edge 2:(1 2) distance:4 
999	999	999	5	
999	999	4	3	
999	4	999	6	
5	3	6	999	

 Thread 0: 
 Edge 3:(2 4) distance:3 
999	999	999	5	
999	999	4	999	
999	4	999	6	
5	999	6	999	

Total Time :0.006347
 Minimum distance=9 
*/
 

