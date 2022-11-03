#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(){
    double five_tries[5];
    struct timeval current_time;
    struct timeval end_time;
    const int SIZEOFCACHE = 512000; //size of cache
    const double SIZEOFCACHED = 512000.0; //size of cache
    for (int i = 0; i < 5; i++){ //loop through 5 times
        gettimeofday(&current_time, NULL);
        char* space = malloc(SIZEOFCACHE); 
        for (int j=0; j < SIZEOFCACHE; j++){
            space[j]='a';
        }
        gettimeofday(&end_time, NULL);
        five_tries[i]=(SIZEOFCACHED)/(end_time.tv_sec-current_time.tv_sec);
    }
    printf("seconds : %ld\nmicro seconds : %ld", current_time.tv_sec, current_time.tv_usec);
    return 0;
}