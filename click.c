/* USAGE: ./click 90 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ONESEC 1000000
#define CLICK  "beep.wav &"
#define PLAYER "mpv "

int play();

int play()
{
    char command[20];
    strcpy(command, PLAYER);
    strcat(command, CLICK);
    return system(command);
}

int main(int argc, char **argv)
{
    int bpm = atoi(argv[1]);
    double onebpm = ONESEC * 60;
    double interval = onebpm / bpm;

    printf("bpm = %d\n", bpm);
    printf("onebpm = %f\n", onebpm);
    printf("interval = %f\n", interval);

    while (1) {
        play();

        usleep(interval);
    }

    return 0;
}


