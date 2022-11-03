#include <stdio.h>
#include <sys/time.h>

int main(){
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    for (int i = 0; i < 5; i++){

    }
    printf("seconds : %ld\nmicro seconds : %ld", current_time.tv_sec, current_time.tv_usec);
    return 0;
}