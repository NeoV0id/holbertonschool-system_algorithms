#include "nary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 */
size_t nary_tree_traverse(nary_tree_t const *root, void (*action)(nary_tree_t const *node, size_t depth))
{
	nary_tree_t *tmp;

	tmp = malloc(sizeof(nary_tree_t));
	if (tmp == NULL)
		return (0);
	
	while (root->next != NULL)
	{

	}
}
