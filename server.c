# include "head.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[++i])
        ;
    return (i);
}

void    int_read(int signum)
{
    static int  i;
    static int cnt;

    ++cnt;
    if (signum == 30)
    {
        i = i << 1;  
        printf("HEre we are %d\n", 0);
    }
    else if (signum == 31)
    {
        i = (i << 1) + 1;
        printf("HEre we are %d\n", 1);
    }
    if (cnt == 32)
    {
        printf("the end %i\n", i);
        exit(1);
    }
    printf("%d \n", i);
}

int get_amount(void)
{
    static int cnt;

    signal(SIGUSR1, int_read);
    signal(SIGUSR2, int_read);
    //signal(SIGUSR2, int_read);
    while (1)
    {
        //rintf("kek\n");
        usleep(10000);
        if (cnt == 32)
        {
            printf("THE END %d\n", cnt);
            exit(1);
        }
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
    get_amount();
    while (1)
    {
        //printf("lol\n");
        usleep(10000);
    }
}