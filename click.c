#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ONESEC 1000000

int main(int argc, char **argv)
{
    int bpm = atoi(argv[1]);
    double onebpm = ONESEC * 60;
    double interval = onebpm / bpm;

    printf("bpm = %d\n", bpm);
    printf("onebpm = %f\n", onebpm);
    printf("interval = %f\n", interval);

    while (1) {
        system("mpv beep.wav &");

        usleep(interval);
    }

    return 0;
}
