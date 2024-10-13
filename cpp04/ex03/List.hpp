#ifndef LIST_HPP
# define LIST_HPP

#include "AMateria.hpp"
#include <iostream>

struct g_delete_list{
    AMateria        *member;
    g_delete_list   *next;
};

void add_node(AMateria *node);
void delete_node(void);
#endif