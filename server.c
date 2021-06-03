# include "head.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[++i])
        ;
    return (i);
}

void    print_str(int signum)
{
    if (signum == 30)
        printf("HEre we are %d\n", 0);
    else if (signum == 31)
        printf("HEre we are %d\n", 1);
    else
    {
        printf("rerror\n");
        exit(0);
    }
}

int main(void)
{
    char *pid;

    pid = ft_itoa(getpid(), 10);
    if (!pid)
        exit(0);
    write(1, pid, ft_strlen(pid));
    write(1, "\n", 1);
    signal(SIGUSR1, print_str);
    signal(SIGUSR2, print_str);
    while (1)
    {
        printf("lol\n");
        system("sleep 5");
    }
}