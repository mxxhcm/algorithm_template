#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<sys/time.h>
#include<unistd.h>


//struct timeval
//{
//     long tv_sec;//秒域
//     long tv_usec;//微秒域
//}
//int getimeofday(struct timeval* tv,NULL);


int main()
{

    struct timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);
    sleep(1);
    gettimeofday(&tv2, NULL);

    printf ("Total time = %f seconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));
    return 0;
}
