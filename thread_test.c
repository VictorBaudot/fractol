#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[10];

void* doSomeThing(void *arg)
{
	int i;

	i = (int) arg;
	unsigned long j;

    pthread_t id = pthread_self();
	if(pthread_equal(id,tid[i]))
        printf("\n Thread (.%d.) processing\n", i);
	i++;
/*
    if(pthread_equal(id,tid[0]))
        printf("\n First thread processing\n");
    else
    {
        printf("\n Second thread processing\n");
    }*/

   for(j=0; j<(0xFFFFFFFF);j++);

    return (NULL);
}

int main(void)
{
	int i;
	i = 0;
	int err;

	while(i < 10)
	{
		err = pthread_create(&(tid[i]), NULL, &doSomeThing, (void *)i);
		if (err != 0)
			printf("\ncan't create thread :[%s]", strerror(err));
		else
			printf("\n Thread created successfully\n");
		i++;
	}
	i = 0;
	while(i < 10)
	{
		if (pthread_join(tid[i], NULL)) {
			perror("pthread_join");
			return EXIT_FAILURE;
		}
		i++;
	}
	return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1(void *arg)
{
    printf("Nous sommes dans le thread.\n");
    (void) arg;
    pthread_exit(NULL);
}


int main(void)
{
    pthread_t thread1;
    printf("Avant la création du thread.\n");
    if (pthread_create(&thread1, NULL, thread_1, NULL)) {
	    perror("pthread_create");
	    return EXIT_FAILURE;
    }
    if (pthread_join(thread1, NULL)) {
	    perror("pthread_join");
	    return EXIT_FAILURE;
    }
    printf("Après la création du thread.\n");
    return EXIT_SUCCESS;
}
*/
