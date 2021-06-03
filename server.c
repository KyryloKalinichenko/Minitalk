# include "head.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[++i])
        ;
    return (i);
}

int main(void)
{
    char *pid;

    pid = ft_itoa(getpid(), 10);
    printf("%d\n", getpid());
    write(1, pid, ft_strlen(pid));
    printf("%s\n", pid);
    while (1)
    {
        system("sleep 1");
        exit(1);
    }
}