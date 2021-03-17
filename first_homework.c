#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* Ga(void* avg);
void* Gb(void* avg);
int n = 10;

int main()
{
int r1,r2;
pthread_t t1,t2;
r1 = pthread_create(&t1,NULL,Ga,NULL);
r2 = pthread_create(&t2,NULL,Gb,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);

return 0;
}

void* Ga(void * avg){
        for(int i = 0; i < 3; i++){
                n = n + 1;
                printf("Thread t1: %d\n",n);
        }
}
void* Gb(void * avg){
        for(int i = 0; i < 3; i++){
                printf("Thread t2: %d\n",n);
                n = 0;
                printf("Thread t2: %d\n",n);
        }
}
                    