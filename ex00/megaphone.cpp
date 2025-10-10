/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:04:28 by relgheit          #+#    #+#             */
/*   Updated: 2025/09/22 16:37:50 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>

int	main(int arc, char **arv)
{
	if (arc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (arc >= 2)
	{
		for (int j = 1; j < arc; j++)
		{
			for (int i = 0; arv[j][i]; i++)
				std:: cout << (char)toupper(arv[j][i]);
		}
		std::cout << std::endl;
	}
	return (0);
}