#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void* myTurn(void *arg) {
    int *v = (int*)malloc(sizeof(int));
    *v = 5;
    for (int i = 0; i < 8; i++) {
        sleep(1);
        printf("My turn %d %d\n", i, *v);
        (*v)++;
    }
    return v;
}

void yourTurn() {
    for (int i = 0; i < 3; i++) {
        sleep(1);
        printf("Your turn %d\n", i);
    }
}

int main() {
    // myTurn();
    // yourTurn();

    pthread_t newThread;
    int *result;

    pthread_create(&newThread, NULL, myTurn , NULL);
    yourTurn();

    pthread_join(newThread, (void *)&result);
    printf("Thread done: *result=%d\n", *result);

    return 0;
}