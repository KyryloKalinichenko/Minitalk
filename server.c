# include "head.h"

t_list all;

void    int_read(int signum)
{
    static int  i;
    static int cnt;

    ++cnt;
    printf("signum %10d \n", signum);
    if (cnt <= 32 && signum == 30) // 0
        all.cl_pid = all.cl_pid << 1;  
    else if (cnt <= 32 && signum == 31) // 1
        all.cl_pid = (all.cl_pid << 1) + 1;
    else if (cnt > 32 && signum == 30)
        i = i << 1;  
    else if (cnt > 32 && signum == 31)
        i = (i << 1) + 1;
    if (cnt == 64)
    {
        printf("the end %10i %10i \n", i, all.cl_pid);
        exit(1);
    }
    printf("%d \n", all.cl_pid);
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
            //exit(1);
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