/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:19:55 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/28 11:03:32 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain{
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(std::string idea);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};

#endif