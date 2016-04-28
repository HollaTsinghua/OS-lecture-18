#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <cstring>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define M 2
#define N 8
sem_t thread_mutex;
int A_num=M+1,B_num=0;
int sleeptimeA[3]={1,3,9};
int sleeptimeB[3]={9,3,1};
void * threadA(void* arg)
{
	int pid = *(int*)(arg);
	while (A_num+B_num<100)
	{
		while (A_num-B_num>=N-1);
		sem_wait(&thread_mutex);
		A_num++;
		printf("threadA has written data, now A length:%d, B length:%d, difference:%d\n",A_num,B_num,A_num-B_num);
		sem_post(&thread_mutex);
		int i=rand()%3;
		Sleep(sleeptimeA[i]*200);
	}
    return NULL;
}

void * threadB(void* arg)
{
	int pid = *(int*)(arg);
	while (A_num+B_num<100)
	{
		while (A_num-B_num<=M+1);
		sem_wait(&thread_mutex);
		B_num++;
		printf("threadB has written data, now A length:%d, B length:%d, difference:%d\n",A_num,B_num,A_num-B_num);
		sem_post(&thread_mutex);
		int i=rand()%3;
		Sleep(sleeptimeB[i]*200);
	}
    return NULL;
}

int main()
{
	srand((unsigned int)(time(0)));
	printf("M=%d N=%d\n",M,N);
	printf("now A length:%d, B length:%d, difference:%d\n",A_num,B_num,A_num-B_num);
	sem_init(&thread_mutex,0,1);
	pthread_t id[2];
	pthread_create(&id[0],NULL,threadA,new int(0));
	pthread_create(&id[1],NULL,threadB,new int(1));
	pthread_join(id[0],0);
	pthread_join(id[1],0);
	return 0;
}
