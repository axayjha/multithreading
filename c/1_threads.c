#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void* myTurn(void *arg) {
    for (int i = 0; i < 8; i++) {
        sleep(1);
        printf("My turn %d\n", i);
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

    pthread_create(&newThread, NULL, myTurn , NULL);
    yourTurn();

    pthread_join(newThread, NULL);

    return 0;
}