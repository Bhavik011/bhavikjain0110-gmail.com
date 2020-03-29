#include<stdio.h>
#include<stdlib.h>
//header required to implement multi-threading
#include<pthread.h>
//function created to create another thread which will
//display prime numbers.
void *show(void *num)
{
	printf("\n\n  Output Thread :\n");
	printf("  **************\n");
	printf("\n\nPrime Numbers are : \n");
	int i,j,flag;
	//storing value of number entered by user.
	int *n=(int *)num;
	//checking prime numbers:
	//selecting a number:
	for(i=1;i<=*n;i++)
	{
		flag=0;
		//selecting rest of numbers one by one:
		for(j=1;j<=*n;j++)
		{//checking if first selected number is prime:
			if(i%j==0)
		 {//if number gets factorized increment flag:
			flag=flag+1;
		 }
	    }
	    //if the numbers is prime then it will have only two factors
	    //so seperate the numbers having only two factors:
		if(flag==2)
		{//print the prime numbers:
			printf("%d ",i);
		}
	}
	
}
int main()
{
	int n;
	printf("\n\n  Input Thread :\n");
	printf("  *************\n");
	printf("\n\n  Enter a number upto which prime numbers are required:-\n");
	scanf("%d",&n);
	//defining sructure of thread:
	pthread_t tid;
	//creating a new thread:
	//ARGUMENT:-
	//first takes structure of thread
	//second takes its attributes
	//third takes the function name of new thread
	//fourth takes the arguments of that function
	pthread_create(&tid,NULL,show,&n);
	//allowing  the application to wait for a thread to terminate
	pthread_join(tid,NULL);
	return 0;}
