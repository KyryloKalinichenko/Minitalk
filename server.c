# include "head.h"

t_list all;

void	ft_bzero(void *s, size_t n)
{
	unsigned char *n_s;

	n_s = s;
	while (n)
	{
		*n_s = '\0';
		n_s++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char *arr;

	arr = malloc(size * nmemb);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

void    int_read(int signum)
{
    //static int  i;
    //static int cnt;
    int         ind;
    //char        *s;

    ++all.cnt;
    ind = 0;
    printf("signum %10d \n", signum);
    if (all.cnt <= 32 && signum == 30) // 0
        all.cl_pid = all.cl_pid << 1;  
    else if (all.cnt <= 32 && signum == 31) // 1
        all.cl_pid = (all.cl_pid << 1) + 1;
    else if (all.cnt > 32 && signum == 30)
        all.len = all.len << 1;  
    else if (all.cnt > 32 && signum == 31)
        all.len = (all.len << 1) + 1;
    if (all.cnt == 64)
    {
        printf("THE pid %10i THE len %10i\n", all.cl_pid, all.len);
        all.str = ft_calloc(sizeof(char), all.len);
    }
    if (all.cnt > 64)
    {
        ind = (all.cnt - 64) / 32;
        //printf("%20i\n", ind);
        if (signum == 30) // 0
            all.tmp = all.tmp << 1;  
        else if (signum == 31) // 1
            all.tmp = (all.tmp << 1) + 1;
        if (!((all.cnt - 64) % 32))
        {
            printf("cond %30i %10i \n", all.tmp, ind - 1);
            all.str[ind - 1] = all.tmp;
            all.tmp = 0;
        }
        printf("STRING  ---%s---\n", all.str);
    }
    //printf("%d \n", all.cl_pid);
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