#include "push_swap.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static void	ft_putdouble_percent_fd(double score, int fd)
{
	int	pct_whole;
	int	pct_frac;

	pct_whole = (int)(score * 100);
	pct_frac = (int)((score * 100 - pct_whole) * 100);
	if (pct_frac < 0)
		pct_frac = -pct_frac;
	ft_putnbr_fd(pct_whole, fd);
	ft_putstr_fd(".", fd);
	if (pct_frac < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(pct_frac, fd);
	ft_putstr_fd("%\n", fd);
}

void	display_benchmarks(t_env *env)
{
	if (!env->bench_mode)
		return ;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putdouble_percent_fd(env->bench.disorder_score, 2);
	ft_putstr_fd("[bench] strategy:   ", 2);
	if (env->strat == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O^(n2)\n", 2);
	else if (env->strat == STRAT_MEDIUM)
		ft_putstr_fd("Adaptive / O(n*sqrt(n))\n", 2);
	else if (env->strat == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(env->bench.total_ops, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(env->bench.sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(env->bench.sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(env->bench.ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(env->bench.pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(env->bench.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(env->bench.ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(env->bench.rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(env->bench.rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(env->bench.rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(env->bench.rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(env->bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}