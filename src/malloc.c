/*
** EPITECH PROJECT, 2019
** malloc_rebirth
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/malloc.h"

block_t *list = NULL;
int nb_pages = 0;
size_t actualSizeMemory = 0;

void *realloc(void *ptr, size_t size)
{
    void *save_ptr = list;

    for (; list->ptr != ptr;) {
        if (list->next != NULL)
            list = list->next;
        else
            break;
    }
    if (list->ptr != ptr)
        exit(84);
    else if (list->memory_size == next_power(size) ||
    list->memory_size < next_power(size)) {
        return list->ptr;
    }
    else {
        if (list->next != NULL && list->next->free == true)
            return check_best_fit(save_ptr, list, size);
    }
    return NULL;
}

void free(void *ptr)
{
    block_t *save_ptr = list;

    if (ptr == NULL)
        return;
    while (save_ptr != NULL) {
        if (save_ptr->ptr == ptr) {
            save_ptr->free = true;
            break;
        }
        save_ptr = save_ptr->next;
    }
}

void *malloc(size_t size)
{
    block_t *best_ptr = NULL;

    if (size == 0)
        return NULL;
    if (list == NULL) {
        list = init_memory(list, size, nb_pages, actualSizeMemory);
        return list->ptr;
    }
    best_ptr = best_fit_search(list, size);
    if (best_ptr != NULL) {
        best_ptr->free = false;
        return best_ptr->ptr;
    }
    return create_block_memory(list, size, nb_pages, actualSizeMemory);
}