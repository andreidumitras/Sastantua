/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:29:00 by adumitra          #+#    #+#             */
/*   Updated: 2023/09/12 19:45:06 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void sastantua(int size);

int main(int ac, char **av)
{
	// Use the command line argumebts to specify the size of the pytamid.
	sastantua(atoi(av[ac - 1]));
	return (0);
}
