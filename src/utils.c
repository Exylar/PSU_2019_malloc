/*
** EPITECH PROJECT, 2019
** malloc_rebirth
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/malloc.h"

unsigned next_power(unsigned n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return ++n;
}

block_t *init_memory(block_t *list, size_t size, int nb_pages,
size_t actualSizeMemory)
{
    int nb = size / getpagesize() * 2;

    list = sbrk(next_power((nb + 1) * getpagesize() * 2));
    nb_pages = (nb + 1) + nb_pages;
    list->ptr = list + sizeof(block_t);
    list->free = false;
    list->prev = NULL;
    list->next = NULL;
    list->memory_size = next_power(size);
    actualSizeMemory += list->memory_size + sizeof(block_t);
    return list;
}

block_t *best_fit_search(block_t *list, size_t size)
{
    block_t *save_ptr = list;
    block_t *best_ptr = NULL;

    while (list->next != NULL) {
        if (list->free == true && list->memory_size >= next_power(size) &&
        (best_ptr == NULL || (best_ptr != NULL && list->memory_size <
        best_ptr->memory_size))) {
            best_ptr = list;
        }
        list = list->next;

    }
    list = save_ptr;
    return best_ptr;
}

void *create_block_memory(block_t *list, size_t size, int nb_pages,
size_t actualSizeMemory)
{
    block_t *save_ptr = list;
    block_t *node;

    if ((size_t)(actualSizeMemory + sizeof(block_t) +
    next_power(size)) > (size_t)(nb_pages * (2 * getpagesize()))) {
        int nb = size / getpagesize() * 2;
        nb_pages += (nb + 1);
        sbrk(next_power((nb_pages + nb + 1) * (getpagesize() * 2)));
    }
    while (list->next != NULL)
        list = list->next;
    node = list->ptr + list->memory_size;
    node->ptr = node + sizeof(block_t);
    node->memory_size = next_power(size);
    node->free = false;
    node->next = NULL;
    node->prev = list;
    list->next = node;
    list = save_ptr;
    actualSizeMemory += node->memory_size + sizeof(block_t);
    return node->ptr;
}