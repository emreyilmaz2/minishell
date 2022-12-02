#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int isgnum)
{
    if(isgnum == SIGINT)
        write(1, "ne basiyon kanka bu kadar kircan tusu", 40);
}

int main()
{
    struct sigaction test;
    test.sa_mask = handler;
    while(1)
    {
        printf("|| dostu bekliyoz ||\n");
        sleep (1);
    }
    if(sigaction(SIGINT, &test, NULL)== -1)
        perror("signal actioned");
    return(0);
}
