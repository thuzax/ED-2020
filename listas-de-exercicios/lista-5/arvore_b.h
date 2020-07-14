// Modified from: https://gist.github.com/lylemalik/4283086

#ifndef BTREE_HPP
#define BTREE_HPP

#define T 25
#define BTREE_OK 0
#define BTREE_ERR -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct btree_node
{
     int key_num;
     int key[2 * T - 1];
     int seek[2 * T];
     int self;
     int parent;
}btree_node;


typedef struct btree
{
     struct btree_node *root;
     FILE *fp;
     int passos_teste_busca;
     int realizando_teste_busca;
}btree;


int btree_insert(btree *tree, int key);
int btree_split(btree *tree, btree_node *node);
btree_node *btree_search(btree *tree, int key);
btree *btree_create(const char *file);
int btree_delete(btree *tree, int key);
int btree_merge(btree *tree, btree_node *left, btree_node *right, btree_node *parent);
#endif