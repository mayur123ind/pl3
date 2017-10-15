#include<stdio.h>
#include<omp.h>

void main()
{
	int id,i;
	printf("Hello\n");
	#pragma omp parallel
	{
		for(i=1;i<5;i++)
		{
			id=omp_get_thread_num();
			printf("Hi%d %d\n",i,id);
		}	
	}
}

