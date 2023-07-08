#include "nary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * create_node - create a nary tree node
 *
 * @str: content of node
 *
 * Return: a new node
 */
nary_tree_t *create_node(char const *str)
{
	nary_tree_t *new_node;

	new_node = malloc(sizeof(nary_tree_t));
	if (new_node == NULL)
		return (NULL);

	if (str != NULL)
		new_node->content = strdup(str);
	else
		new_node->content = NULL;

	new_node->parent = NULL;
	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;

	return (new_node);
}

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
	nary_tree_t *tmp, *node;

	tmp = create_node(NULL);
	node = create_node(str);

	if (parent == NULL)
		return (node);

	tmp = parent;
	if (tmp->children == NULL)
	{
		tmp->children = node;
		node->parent = parent;
		tmp->nb_children += 1;
		return (node);
	}
	if (tmp->children != NULL)
	{
		node->next = tmp->children;
		tmp->children = node;
		node->parent = tmp;
		tmp->nb_children += 1;
		return (node);
	}
	return (NULL);
}
