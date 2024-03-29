#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Structures */
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

/* Function prototypes */
avl_t *sorted_array_to_avl(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
