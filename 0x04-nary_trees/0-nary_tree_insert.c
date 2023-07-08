#include "nary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * nary_tree_insert - inserts node in a n-ary tree
 *
 * @parent: parent of node to insert/create
 * @str: data to store in the node
 *
 * Return: new tree
 */

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	char *dup;
	nary_tree_t *tmp, *node;

	dup = strdup(str);
	tmp = malloc(sizeof(nary_tree_t));
	if (tmp == NULL)
		return (NULL);

	node = malloc(sizeof(nary_tree_t));
	if (node == NULL)
		return (NULL);

	node->content = dup;

	if (parent == NULL)
		return (node);

	if (parent->children == NULL)
	{
		parent->children = node;
		node->parent = parent;
		parent->nb_children += 1;
		return (node);
	}
	if (parent->children != NULL)
	{
		node->next = parent->children;
		parent->children = node;
		node->parent = parent;
		parent->nb_children += 1;
		return (node);
	}
	return (NULL);
}
