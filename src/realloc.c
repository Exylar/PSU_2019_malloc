/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/malloc.h"

block_t *compare_best_places(block_t *best_ptr, block_t *list)
{
    if (best_ptr == NULL ||
    (best_ptr != NULL && list->memory_size < best_ptr->memory_size)) {
        best_ptr = list;
    }
    return best_ptr;
}

void *best_fit_realloc(block_t *list, size_t size)
{
    block_t *best_ptr = NULL;

    for (; list != NULL;) {
        if (list->free == true && list->memory_size >= next_power(size)) {
            best_ptr = compare_best_places(best_ptr, list);
        }
    }
    return best_ptr;
}

void *return_pointer(block_t *list, size_t size, block_t *cpy, void *save_ptr)
{
    void *new_ptr = NULL;
    block_t *bestptr = NULL;

    bestptr = best_fit_realloc(list, size);
    list = list;
    if (bestptr != NULL) {
        bestptr = memcpy(bestptr->ptr, cpy->ptr, cpy->memory_size);
        cpy->free = true;
        list = save_ptr;
        return bestptr->ptr;
    }
    else {
        new_ptr = malloc(next_power(size));
        new_ptr = memcpy(new_ptr, cpy->ptr, cpy->memory_size);
        cpy->free = true;
        list = save_ptr;
        return new_ptr;
    }
}

void *check_best_fit(void *save_ptr, block_t *list, size_t size)
{
    block_t *cpy_ptr = NULL;

    if ((list->memory_size + list->next->memory_size) >= next_power(size))
        list->memory_size += list->next->memory_size;
    else {
        cpy_ptr = list;
        list = save_ptr;
        return return_pointer(list, size, cpy_ptr, save_ptr);
    }
    return NULL;
}