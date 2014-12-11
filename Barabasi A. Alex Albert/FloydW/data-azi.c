#include <time.h>
#include <stdio.h>
#include <time.h>

int main() {

    time_t t = time(0);   // get time now

    struct tm * now = localtime( & t );
    printf(" azi este: ");
    printf("%d-%d-%d\n",now->tm_mday, (now->tm_mon + 1),(now->tm_year + 1900));

}
