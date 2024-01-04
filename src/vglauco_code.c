/* 
   **************************************************************************************
Código desenvolvido para a disciplina - Sistemas Embarcados para veículos Aereos

Cria uma saida PWM para o hardware embarcado Toradex VF50 + Carrier Board Viola

Autores:
        Beatriz Ferreira de Oliveira Mendonça
Criação - 19/12/2023
   ***************************************************************************************
  
Alteração - 29/12/2023  - Glauco Caurin

+ Inserção de Comentarios
+ Inclusão de instrução export para inicializar a saida PWM
   ***************************************************************************************
*/  



#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char a[] = "500000";
int main(int argc, char *argv[]){
    int fd;
    
    // export PWM
    fd = open("/sys/class/pwm/pwmchip8/export", O_WRONLY);
    write(fd, "0", 1);
    close(fd);
 	
    // Select the period of the PWM signal. Value is in nanoseconds.
    fd = open("/sys/class/pwm/pwmchip8/pwm0/period", O_WRONLY);
    write(fd, "1000000", 7);
    close(fd);

    // Select the duty cycle. Value is in nanoseconds and must be less than the period.
    fd = open("/sys/class/pwm/pwmchip8/pwm0/duty_cycle", O_WRONLY);
    write(fd, "500000", 6);
    close(fd);
    
    // Change the polarity of the PWM signal (you can use "normal" or "inversed"). 
    // The polarity can only be changed if the PWM is not enabled.
    fd = open("/sys/class/pwm/pwmchip8/pwm0/polarity", O_WRONLY);
    write(fd, "normal", 6);
    close(fd);
    
    // Enable/disable the PWM signal, use 1 or 0 respectively:
    fd = open("/sys/class/pwm/pwmchip8/pwm0/enable", O_WRONLY);
    write(fd, "1", 1);
    close(fd);

    // Interactively change the duty cycle! Change LED Brigthness!
    // Type in a number corresponding to the new dutty cycle
    fd = open("/sys/class/pwm/pwmchip8/pwm0/duty_cycle", O_WRONLY);
    while (1) {
    scanf("%s", a);
    write(fd, a, 6);
    usleep(1000000);
    }


    return EXIT_SUCCESS;
}
