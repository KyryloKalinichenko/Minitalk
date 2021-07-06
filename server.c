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
    int         ind;

    ++all.cnt;
    ind = 0;
    if (all.cnt <= 32 && signum == 30) // 0
        all.cl_pid = all.cl_pid << 1;  
    else if (all.cnt <= 32 && signum == 31) // 1
        all.cl_pid = (all.cl_pid << 1) + 1;
    else if (all.cnt > 32 && signum == 30 && all.cnt <= 64)
        all.len = all.len << 1;  
    else if (all.cnt > 32 && signum == 31 && all.cnt <= 64)
        all.len = (all.len << 1) + 1;
    if (all.cnt == 64)
    {
        all.str = ft_calloc(sizeof(char), all.len);
    }
    if (all.cnt > 64 && ft_strlen(all.str) != all.len)
    {
        ind = (all.cnt - 64) / 32;
        if (signum == 30) // 0
            all.tmp = all.tmp << 1;  
        else if (signum == 31) // 1
            all.tmp = (all.tmp << 1) + 1;
        if (!((all.cnt - 64) % 32))
        {
            all.str[ind - 1] = all.tmp;
            all.tmp = 0;
        }
        if (ft_strlen(all.str) == all.len)
        {
            //printf("STRING  ---%s---\n", all.str);
            write(1, all.str, all.len);
            write(1, "\n", 1);
            free(all.str);
            all.cnt = 0;
            all.len = 0;
            all.cl_pid = 0;
            all.tmp = 0;
        }
    }
    else if (all.cnt > 64)
    {
        write(1, "Error\n", 6);
        exit(0);
    }
}

void get_amount(void)
{
    signal(SIGUSR1, int_read);
    signal(SIGUSR2, int_read);
}

int main(void)
{
    char *pid;

    pid = ft_itoa(getpid(), 10);
    if (!pid)
        exit(0);
    write(1, pid, ft_strlen(pid));
    write(1, "\n", 1);
    free(pid);
    get_amount();
    while (1)
        usleep(1000);
}