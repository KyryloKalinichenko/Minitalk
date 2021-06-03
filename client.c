#include "head.h"

int get_pid(char *str)
{
    int i;

    i = -1;
    while(str[++i])
    {
        if (!ft_isdigit(str[i]))
            exit(0);
    }
    printf("%s\n", str);
    return(ft_atoi(str));
}
/*
void    send_int(int i)
{

}*/

int    int_to_by(int i, int pid)
{
    int cnt;

    cnt = 32;
    while(cnt > -1)
    {
        if (((i >> cnt) & 1))
            kill(pid, SIGUSR2); // 1
        else
            kill(pid, SIGUSR1); // 0
        system("sleep 1");
        cnt--;
    }
    exit(0);
}

void    send_str(char *str, int pid)
{
    int i;
    int b;

    i = -1;
    b = 0;
    while(str[++i])
    {
        b = int_to_by(str[i], pid);
       // send_int(b);
    }
}

int main(int argc, char **argv)
{
    int pid;

    if (argc < 3 || argc > 3)
        exit(0);
    pid = get_pid(argv[1]);
    //send_str(argv[2], pid);
    int_to_by(50, pid);
    printf("%i\n", pid);
    return (0);
}