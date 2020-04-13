/* USAGE: ./click 90 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ONESEC 1000000
#define ONEBPM 60000000
#define CLICK  "beep.wav &"
#define PLAYER "mpv "

double CalcInterval(int bpm);
int play();

double CalcInterval(int bpm)
{
    return ONEBPM / bpm;
}

int play()
{
    char command[20];
    strcpy(command, PLAYER);
    strcat(command, CLICK);
    return system(command);
}

int main(int argc, char **argv)
{
    double interval = CalcInterval(atoi(argv[argc - 1]));

    while (1) {
        play();

        usleep(interval);
    }

    return 0;
}


