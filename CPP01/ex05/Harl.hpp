/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:19:41 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/16 14:50:02 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl{
    private:
        void error(void);
        void debug(void);
        void warning(void);
        void info(void);
    public:
        Harl();
        ~Harl();

        void complain(std::string level);
};

#endif