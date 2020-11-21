/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "../include/malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *address = malloc(size * nmemb);

    if (address == NULL)
        return NULL;
    return memset(address, 0, size * nmemb);
}
