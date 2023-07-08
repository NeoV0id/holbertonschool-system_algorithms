#include "nary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * nary_tree_delete - deallocate an entire nary tree
 *
 * @tree: tree to deallocate
 *
 * Return: nothing
 */
void nary_tree_delete(nary_tree_t *tree)
{
	if (tree->children == NULL)
	{
		if (tree->next == NULL)
			free(tree);
		nary_tree_delete(tree->next);
	}
	nary_tree_delete(tree->children);
}
