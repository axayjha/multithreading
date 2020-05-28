#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void* myTurn(void *arg) {
    int *v = (int*)(arg);
    for (int i = 0; i < 8; i++) {
        sleep(1);
        printf("My turn %d %d\n", i, *v);
        (*v)++;
    }
    return NULL;
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
    int v = 5;

    pthread_create(&newThread, NULL, myTurn , &v);
    yourTurn();

    pthread_join(newThread, NULL);
    printf("Thread done: v=%d\n", v);

    return 0;
}