#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void child(){

        char name[40];
        printf(" Enter a name:");
        scanf("%s", name);
        printf("\n Hello %s. \n", name);
        exit(0);
}

void parent(){

        printf("\n Job is done\n");
}

int main(void) {

        for ( int k=1; k<5; k++) {

        pid_t pid = fork();

        if ( pid == 0 ) {

                child(); }

        else if(k==4) {

                wait(NULL);
                parent();   }

        else { wait (NULL); }

        }

        return EXIT_SUCCESS;

}

