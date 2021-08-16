/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:55:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/16 20:21:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, const char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->arg = (t_arg *)malloc(sizeof(t_arg));
	if (philo->arg == NULL || philo == NULL)
		exit(1);
	if ((init(argc, argv, philo)) == IS_ERROR)
		exit(1);
	if ((philo_func(philo)) == IS_ERROR)
		exit(1);
	pthread_mutex_destroy(&g_mutex);
	return (0);
}
