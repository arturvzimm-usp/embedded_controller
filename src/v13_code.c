#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    int fd;
 
    fd = open("/sys/class/pwm/pwmchip8/pwm0/period", O_WRONLY);
    write(fd, "1000000", 7);
    close(fd);

    fd = open("/sys/class/pwm/pwmchip8/pwm0/duty_cycle", O_WRONLY);
    write(fd, "500000", 6);
    close(fd);

    fd = open("/sys/class/pwm/pwmchip8/pwm0/polarity", O_WRONLY);
    write(fd, "normal", 6);
    close(fd);

    fd = open("/sys/class/pwm/pwmchip8/pwm0/enable", O_WRONLY);
    write(fd, "1", 1);
    usleep(1000000);
    write(fd, "0", 1);
    usleep(1000000);
    close(fd);

    return EXIT_SUCCESS;
}