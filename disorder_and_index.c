#include "push_swap.h"

static void	coordinate_compression(t_env *env)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < env->size)
	{
		rank = 0;
		j = 0;
		while (j < env->size)
		{
			if (env->arr_a[j] < env->arr_a[i])
				rank++;
			j++;
		}
		env->idx_a[i] = rank;
		i++;
	}
}

void	calculate_disorder_score(t_env *env)
{
	int	i;
	int	j;
	int	inversions;
	int	total_pairs;

	coordinate_compression(env);
	if (env->size < 2)
	{
		env->bench.disorder_score = 0.0;
		return ;
	}
	inversions = 0;
	i = 0;
	while (i < env->size - 1)
	{
		j = i + 1;
		while (j < env->size)
		{
			if (env->arr_a[i] > env->arr_a[j])
				inversions++;
			j++;
		}
		i++;
	}
	total_pairs = (env->size * (env->size - 1)) / 2;
	env->bench.disorder_score = (double)inversions / total_pairs;
}