#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(){
    double five_tries[5];
    struct timeval current_time;
    struct timeval end_time;

    //L1: 512KB or 512000 bytes
    //L2: 4MB or 4000000 bytes
    //L3: 32MB or 32000000 bytes

    const int SIZEOFCACHE = 512000; //will enter size of cache here
    const double SIZEOFCACHED = 512000.0; //for avg calculation

    //5 runs
    for (int i = 0; i < 5; i++){ //loop through 5 times
        gettimeofday(&current_time, NULL); //get current epoch time
        char* space = malloc(SIZEOFCACHE); //allocate space of the size of the cache (a char is 1 byte so fill cache with x amount of characters)
        for (int j=0; j < SIZEOFCACHE; j++){
            space[j]='a';
        }
        gettimeofday(&end_time, NULL); //get end epoch time
        five_tries[i]=((SIZEOFCACHED)/(end_time.tv_usec-current_time.tv_usec))/1000; //speed = [(size of cache) / (end time- current)] / 1000 ***in GB/s***
    }                                                                                //divide by 100 to get GB/s conversion
    //GET AVG OF 5 TRIES
    double sum=0;
    for (int i = 0; i < 5; i++){ //find sum of 5 tries
        sum += five_tries[i];
    }
    //calc avg
    double avg=0;
    avg = sum / 5;
    
    printf("Size of cache %u (KB or MB)\n", SIZEOFCACHE);
    //print out 5 runs
    for (int i = 0; i < 5; i++){
        int try=i+1; //get try # starting from 1 
        printf("Try #%u: %lf GB/s\n", try, five_tries[i]);
    }
    //PRINT OUT AVG
    printf("Avg: \t%lf GB/s\n", avg);
    //printf("seconds : %ld\nmicro seconds : %ld", current_time.tv_sec, current_time.tv_usec);
    return 0;
}