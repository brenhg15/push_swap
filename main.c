#include "push_swap.h"

static void	init_environment(t_env *env)
{
	env->arr_a = NULL;
	env->idx_a = NULL;
	env->arr_b = NULL;
	env->idx_b = NULL;
	env->size = 0;
	env->top_a = 0;
	env->top_b = 0;
	env->bench_mode = 0;
	env->strat = STRAT_ADAPTIVE;
	env->bench.total_ops = 0;
	env->bench.sa = 0;
	env->bench.sb = 0;
	env->bench.ss = 0;
	env->bench.pa = 0;
	env->bench.pb = 0;
	env->bench.ra = 0;
	env->bench.rb = 0;
	env->bench.rr = 0;
	env->bench.rra = 0;
	env->bench.rrb = 0;
	env->bench.rrr = 0;
}

static void	free_environment(t_env *env)
{
	if (env->arr_a)
		free(env->arr_a);
	if (env->idx_a)
		free(env->idx_a);
	if (env->arr_b)
		free(env->arr_b);
	if (env->idx_b)
		free(env->idx_b);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		return (0);
	init_environment(&env);
	if (!parse_arguments(argc, argv, &env))
	{
		write(2, "Error\n", 6);
		free_environment(&env);
		return (1);
	}
	calculate_disorder_score(&env);
	execute_sorting_strategy(&env);
	display_benchmarks(&env);
	free_environment(&env);
	return (0);
}