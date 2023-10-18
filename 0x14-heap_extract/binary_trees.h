#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Basic Binary Tree */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/* Function Prototypes */
int heap_extract(heap_t **root);

/* Helper Functions (not part of the task) */
binary_tree_t *_array_to_binary_tree(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void binary_tree_delete(binary_tree_t *tree);

#endif /* BINARY_TREES_H */