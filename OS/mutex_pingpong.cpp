#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int count;
pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_cond_t cond1;

void *First(void* argc)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(count >= 100)
        {
            pthread_cond_signal(&cond1);
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("before %d,thread:%d\r\n", count,(*(int*)argc));
        count++;
        pthread_cond_signal(&cond1);
        pthread_cond_wait(&cond,&mutex);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *Second(void* argc)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(count >= 100)
        {
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("before %d,thread:%d\r\n", count,(*(int*)argc));
        count++;
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond1,&mutex);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t first,second;
    int i = 1;
    int j = 2;
    pthread_create(&first,NULL,First,&i);
    pthread_create(&second,NULL,Second,&j);

    pthread_join(first,NULL);
    pthread_join(second,NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    //pthread_exit(NULL);
    return 0;
}
