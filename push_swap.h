#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_strat
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strat;

typedef struct s_bench
{
	double	disorder_score;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

typedef struct s_env
{
	int		*arr_a;
	int		*idx_a;
	int		*arr_b;
	int		*idx_b;
	int		size;
	int		top_a;
	int		top_b;
	t_strat	strat;
	int		bench_mode;
	t_bench	bench;
}	t_env;

// Core Infrastructure & Parsing
int     parse_arguments(int argc, char **argv, t_env *env);
void    calculate_disorder_score(t_env *env);
void    execute_sorting_strategy(t_env *env);
void    display_benchmarks(t_env *env); // Ensure the 's' is present here

// Algorithm Entry Points
void	sort_simple(t_env *env);
void	sort_medium(t_env *env);
void	sort_complex(t_env *env);

// Basic Utilities
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str, int *error);
int		ft_isdigit(int c);

// Push Swap Operational Interface
void	sa(t_env *env);
void	sb(t_env *env);
void	ss(t_env *env);
void	pa(t_env *env);
void	pb(t_env *env);
void	ra(t_env *env);
void	rb(t_env *env);
void	rr(t_env *env);
void	rra(t_env *env);
void	rrb(t_env *env);
void	rrr(t_env *env);

#endif