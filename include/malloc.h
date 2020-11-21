/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef PSU_2019_MALLOC_MALLOC_H
#define PSU_2019_MALLOC_MALLOC_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum {true, false} bool;

typedef struct block_s {
    void *ptr;
    size_t memory_size;
    bool free;
    struct block_s *prev;
    struct block_s *next;
} block_t;

block_t *init_memory(block_t *list, size_t size, int nb_pages,
size_t actualSizeMemory);
void *best_fit_realloc(block_t *list, size_t size);
void *check_best_fit(void *save_ptr, block_t *list, size_t size);
block_t *best_fit_search(block_t *list, size_t size);
void *create_block_memory(block_t *list, size_t size, int nb_pages,
size_t actualSizeMemory);
block_t *compare_best_places(block_t *best_ptr, block_t *list);

unsigned next_power(unsigned n);
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *my_realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif //PSU_2019_MALLOC_MALLOC_H
