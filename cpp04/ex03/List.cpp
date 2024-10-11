#include "List.hpp"

g_delete_list *g_head = NULL;

void add_node(AMateria *node){
    g_delete_list *new_node;
    g_delete_list *last_node;

    new_node = new g_delete_list;
    new_node->member = node;
    new_node->next = NULL;
    if (g_head == NULL)
        g_head = new_node;
    else
    {
        last_node = g_head;
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node ->next = new_node;
    }
}

void delete_node(void){
    g_delete_list *temp;

    while (g_head)
    {
        temp = g_head;
        g_head = g_head->next;
        delete temp->member;
        delete temp;
    }
    g_head = NULL;
}
