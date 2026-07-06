#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Kernel ah handover panniyaachu. UserSpace start aagiruchu.");

    while(1){
        sleep(1);
    }
    return 0;
}