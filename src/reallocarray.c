/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (size == 0 || nmemb == 0)
        return NULL;
    return realloc(ptr, size * nmemb);
}
