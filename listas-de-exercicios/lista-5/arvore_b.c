#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_b.h"

static int btree_read_disk(btree *tree, int seek, btree_node *node)
{
    seek += sizeof(int) + sizeof(int);
    if(fseek(tree->fp, seek, SEEK_SET) == -1)
        return BTREE_ERR;
    char *read_buf = calloc(1, sizeof(btree_node));
    if(fread(read_buf, sizeof(btree_node), 1, tree->fp) == -1)
        return BTREE_ERR;
    memcpy(node, read_buf, sizeof(btree_node));
    return BTREE_OK;
}

static int btree_write_disk(btree *tree, int seek, btree_node *node)
{
    seek += 2*sizeof(int);
    if(fseek(tree->fp, seek, SEEK_SET) == -1)
        return BTREE_ERR;
    if(fwrite((void *)node, sizeof(btree_node), 1, tree->fp) == -1)
        return BTREE_ERR;
    return BTREE_OK;
}

static int write_header(btree *tree)
{
    int seek = 0;
    if(fseek(tree->fp, seek, SEEK_SET) == -1)
    {
        printf("ERRO ESCRITA CABEÇALHO\n");
        exit(1);
    }
    if(fwrite(&(tree->root_position), sizeof(int), 1, tree->fp) == -1)
    {
        printf("ERRO ESCRITA CABEÇALHO\n");
        exit(1);
    }
    if(fwrite(&(tree->tamanho), sizeof(int), 1, tree->fp) == -1)
    {
        printf("ERRO ESCRITA CABEÇALHO\n");
        exit(1);
    }
    
}

static int read_header(btree *tree)
{
    int seek = 0;
    if(fseek(tree->fp, seek, SEEK_SET) == -1)
    {
        printf("ERRO LEITURA CABEÇALHO\n");
        exit(1);
    }
    char *read_buf = calloc(1, sizeof(int));
    if(fread(read_buf, sizeof(int), 1, tree->fp) == -1)
    {
        printf("ERRO LEITURA CABEÇALHO\n");
        exit(1);
    }
    memcpy(&(tree->root_position), read_buf, sizeof(int));

    if(fread(read_buf, sizeof(int), 1, tree->fp) == -1)
    {
        printf("ERRO LEITURA CABEÇALHO\n");
        exit(1);
    }
    memcpy(&(tree->tamanho), read_buf, sizeof(int));
    
}


static int btree_key_index(btree_node *node, int key)
{
    int low = 0;
    int high = node->key_num - 1;
    int middle = (low + high) / 2;
    while(low <= high)
    {
        if(node->key[middle] == key)
            return middle;
        else if(node->key[middle] > key)
            high = middle - 1;
        else
            low = middle + 1;
        middle = (low + high) / 2;
    }
    return high + 1;
}

static int btree_end_seek_of_file(btree *tree)
{
    if(fseek(tree->fp, 0, SEEK_END) == -1)
        return BTREE_ERR;
    return ftell(tree->fp);
}

static void btree_view(btree *tree, btree_node *node)
{
    int i;
    for(i = 0; i < node->key_num; i++)
        printf("key:%d, self:%d, parent:%d, seek[0]:%d\n", node->key[i], node->self, node->parent, node->seek[0]);
    if(node->seek[0] != -1)
    {
        btree_node *child = calloc(1, sizeof(btree_node));
        if(child == NULL)
            return;
        for(i = 0; i < node->key_num + 1; i++)
        {
            if(btree_read_disk(tree, node->seek[i], child) == BTREE_ERR)
                return;
            btree_view(tree, child);
        }
    }
}

static btree_node *btree_node_create()
{
    btree_node *node = malloc(sizeof(btree_node));
    node->self = -1;
    node->parent = -1;
    int i;
    for(i = 0; i < 2 * T - 1; i++)
        node->key[i] = 0;
    for(i = 0; i < 2 * T; i++)
        node->seek[i] = -1;
    node->key_num = 0;
    return node;
}

static int btree_successor(btree *tree, btree_node *node, btree_node *successor, int index)
{
    if(node->seek[0] == -1)
        return BTREE_ERR;
    if(btree_read_disk(tree, node->seek[index], successor) == BTREE_ERR)
        return BTREE_ERR;
    while(successor->seek[0] != -1)
        if(btree_read_disk(tree, successor->seek[0], successor) == BTREE_ERR)
            return BTREE_ERR;
    return BTREE_OK;
}

int file_exists(const char *file)
{
    FILE *fp;
    if (fp = fopen(file, "r+"))
    {
        fclose(fp);
        return 1;
    }
    return 0;
}

btree *btree_create(const char *file)
{
    btree *tree = calloc(1, sizeof(btree));
    if(tree == NULL)
        return NULL;
    
    FILE *fp;
    tree->fp = fp;
    tree->root_position = -1;
    tree->tamanho = 0;

    if (file_exists(file))
    {
        tree->fp = fopen(file, "r+");
        read_header(tree);
        tree->root = btree_node_create();
        btree_read_disk(tree, tree->root_position, tree->root);
    }
    else
    {
        tree->fp = fopen(file, "w+");
        write_header(tree);
    }
    
    if(!fp)
        return NULL;
    
    if (tree->root_position == -1)
    {
        tree->root = btree_node_create();
        tree->root->self = 0;
        tree->realizando_teste_busca = 0;
        tree->passos_teste_busca = 0;
        if(btree_write_disk(tree, tree->root->self, tree->root) == BTREE_ERR)
        {
            return NULL;
        }
        tree->root_position = tree->root->self;
        tree->tamanho = 1;
        write_header(tree);
    }
    
    return tree;
}

btree_node *btree_search(btree *tree, int key)
{
    btree_node *node = calloc(1, sizeof(btree_node));
    if(node == NULL)
        return NULL;
    *node = *tree->root;
    if (tree->realizando_teste_busca)
        tree->passos_teste_busca += 1;

    int key_index = btree_key_index(node, key);
    while(node->seek[0] != -1 && node->key[key_index] != key)
    {
        if (tree->realizando_teste_busca)
            tree->passos_teste_busca += 1;

        if(btree_read_disk(tree, node->seek[key_index], node) == BTREE_ERR)
            return NULL;

        key_index = btree_key_index(node, key);
        
        
    }

    if(node->key[key_index] == key)
    {
        return node;
    }
    
    return NULL;
}

int* ler_aleatorios(int quantidade, const char* input_name) {
    
    int* vetor_aleatorio = malloc(quantidade*sizeof(int));
    FILE *fp;
    fp = fopen(input_name, "r");
    if (fp == NULL) {
        return NULL;
    }
    for(int i = 0; i < quantidade; i++) {
        int valor;
        fscanf(fp, "%d", &valor);
        vetor_aleatorio[i] = valor;
    }
    fclose(fp);
    return vetor_aleatorio;

}


int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("FALTOU ARQUIVO COM BASE DE TESTES\n");
        return 0;
    }
    char* nome_arq = argv[1];

    // le arquivo
    int quantidade = 1000;
    int* vetor_aleatorio = ler_aleatorios(quantidade, nome_arq);

    // inicializa a arvore e insere
    int i;
    btree *tree = btree_create("bd_file");
    for(i = 0; i < quantidade; i++)
        btree_insert(tree, vetor_aleatorio[i]);




    // marca que o teste sera feito para armazenar o número de passos gastos
    tree->realizando_teste_busca = 1;
    
    // realiza as buscas
    for(i = 0 ; i < quantidade; i++) {
        btree_search(tree, vetor_aleatorio[i]);
    }
    printf("%d\n", tree->passos_teste_busca);

    free(vetor_aleatorio);

    return 0;
}

int btree_insert(btree *tree, int key)
{
    btree_node *node = calloc(1, sizeof(btree_node));
    if(node == NULL)
        return BTREE_ERR;
    *node = *tree->root;
    if(btree_split(tree, node) == BTREE_ERR)
        return BTREE_ERR;
    
    int key_index = btree_key_index(node, key);
    while(node->seek[0] != -1)
    {
        if(btree_read_disk(tree, node->seek[key_index], node) == BTREE_ERR)
            return BTREE_ERR;
        if(btree_split(tree, node) == BTREE_ERR)
            return BTREE_ERR;

        key_index = btree_key_index(node, key);
    }
    int i;
    for(i = node->key_num; i > key_index; i--)
        node->key[i] = node->key[i - 1];
    node->key[key_index] = key;
    node->key_num++;
    if(btree_write_disk(tree, node->self, node) == BTREE_ERR)
        return BTREE_ERR;
    if(tree->root->self == node->self)
    {
        *tree->root = *node;
        tree->root_position = tree->root->self;
    }
    tree->tamanho += 1;
    write_header(tree);
    return BTREE_OK;
}

int btree_split(btree *tree, btree_node *node)
{
    if(node->key_num < 2 * T - 1)
        return BTREE_OK;
    btree_node *brother = btree_node_create();
    brother->self = btree_end_seek_of_file(tree);
    int save_key = node->key[T - 1];
    int i;
    for(i = T; i < node->key_num; i++)
        brother->key[i - T] = node->key[i];
    if(node->seek[0] != -1)
        for(i = T; i < node->key_num + 1; i++)
        {
            brother->seek[i - T] = node->seek[i];
            btree_node *child = calloc(1, sizeof(btree_node));
            if(child == NULL)
                return BTREE_ERR;
            if(btree_read_disk(tree, node->seek[i], child) == BTREE_ERR)
                return BTREE_ERR;
            child->parent = brother->self;
            if(btree_write_disk(tree, child->self, child) == BTREE_ERR)
                return BTREE_ERR;
        }
    node->key_num = brother->key_num = T - 1;
    btree_node *parent = calloc(1, sizeof(btree_node));
    if(parent == NULL)
        return BTREE_ERR;
    if(node->parent == -1)
    {
        parent = btree_node_create();
        tree->root = parent;
        parent->self = brother->self + sizeof(btree_node);
        node->parent = parent->self;
        tree->root_position = tree->root->self;
    }
    else
        if(btree_read_disk(tree, node->parent, parent) == BTREE_ERR)
            return BTREE_ERR;
    
    int key_index = btree_key_index(parent, node->key[0]);

    for(i = parent->key_num; i > key_index; i--)
        parent->key[i] = parent->key[i - 1];
    
    parent->key[i] = save_key;
    for(i = parent->key_num + 1; i > key_index + 1; i--)
        parent->seek[i] = parent->seek[i - 1];
    
    parent->seek[key_index] = node->self;
    parent->seek[key_index + 1] = brother->self;
    parent->key_num++;
    brother->parent = node->parent;

    btree_write_disk(tree, parent->self, parent);
    btree_write_disk(tree, brother->self, brother);
    btree_write_disk(tree, node->self, node);
    if(btree_read_disk(tree, tree->root->self, tree->root) == BTREE_ERR)
        return BTREE_ERR;
    *node = *parent;
    write_header(tree);
    return BTREE_OK;
}

int btree_delete(btree *tree, int key)
{
    btree_node *node = btree_search(tree, key);
    if(node == NULL)
        return BTREE_ERR;

    int key_index = btree_key_index(node, key);
    
    if(node->seek[0] != -1)
    {
        btree_node *successor = btree_node_create();
        if(btree_successor(tree, node, successor, key_index + 1) == BTREE_ERR)
            return BTREE_ERR;
        node->key[key_index] = successor->key[0];
        if(btree_write_disk(tree, node->self, node) == BTREE_ERR)
            return BTREE_ERR;
        if(node->self == tree->root->self)
        {
            *tree->root = *node;
            tree->root_position = tree->root->self;
        }
        node = successor;
        key_index = 0;
    }
    int i;
    for(i = key_index; i < node->key_num - 1; i++)
        node->key[i] = node->key[i + 1];
    node->key_num--;
    btree_write_disk(tree, node->self, node);
    while(node->key_num < T - 1 && node->self != tree->root->self)
    {
        btree_node *parent = btree_node_create();
        if(btree_read_disk(tree, node->parent, parent) == BTREE_ERR)
            return BTREE_ERR;

        key_index = btree_key_index(parent, node->key[0]);
        
        if(parent->key_num == key_index + 1 && parent->key[key_index] == node->key[0])
            key_index++;
        btree_node *brother = btree_node_create();
        if(key_index == parent->key_num)
        {
            if(btree_read_disk(tree, parent->seek[key_index - 1], brother) == BTREE_ERR)
                return BTREE_ERR;
            if(brother->key_num > T - 1)
            {
                for(i = node->key_num; i > 0; i--)
                    node->key[i] = node->key[i - 1];
                for(i = node->key_num + 1; i > 0; i--)
                    node->seek[i] = node->seek[i - 1];
                node->key[0] = parent->key[parent->key_num - 1];
                node->seek[0] = brother->seek[brother->key_num];
                if(node->seek[0] != -1)
                {
                    btree_node *child = btree_node_create();
                    if(btree_read_disk(tree, brother->seek[brother->key_num], child) == BTREE_ERR)
                        return BTREE_ERR;
                    child->parent = node->self;
                    if(btree_write_disk(tree, child->self, child) ==  BTREE_ERR)
                    return BTREE_ERR;
                }
                node->key_num++;
                parent->key[parent->key_num - 1] = brother->key[brother->key_num - 1];
                brother->key_num--;
            }
            else
                btree_merge(tree, brother, node, parent);
        }
        else
        {
            if(btree_read_disk(tree, parent->seek[key_index + 1], brother) == BTREE_ERR)
                return BTREE_ERR;
            if(brother->key_num > T - 1)
            {
                node->key[node->key_num] = parent->key[key_index];
                parent->key[key_index] = brother->key[0];
                node->key_num++;
                for(i = 0; i < brother->key_num - 1; i++)
                    brother->key[i] = brother->key[i + 1];
                node->seek[node->key_num] = brother->seek[0];
                if(node->seek[node->key_num] != -1)
                {
                    btree_node *child = btree_node_create();
                    if(btree_read_disk(tree, brother->seek[0], child) == BTREE_ERR)
                        return BTREE_ERR;
                    child->parent = node->self;
                    if(btree_write_disk(tree, child->self, child) == BTREE_ERR)
                    return BTREE_ERR;
                }
                for(i = 0; i < brother->key_num; i++)
                    brother->seek[i] = brother->seek[i + 1];
                brother->key_num--;
            }
            else
                btree_merge(tree, node, brother, parent);
        }
        btree_write_disk(tree, parent->self, parent);
        btree_write_disk(tree, node->self, node);
        btree_write_disk(tree, brother->self, brother);
        if(tree->root->self == parent->self)
        {
            *tree->root = *parent;
            tree->root_position = tree->root->self;
        }
        *node = *parent;
    }
    if(tree->root->self == node->self)
    {
        *tree->root = *node;
        tree->root_position = tree->root->self;
    }
    write_header(tree);
    return BTREE_OK;
}

int btree_merge(btree *tree, btree_node *left, btree_node *right, btree_node *parent)
{
    int key_index = btree_key_index(parent, left->key[0]);
    int save_key = parent->key[key_index];
    int i;
    
    for(i = key_index; i < parent->key_num - 1; i++)
        parent->key[i] = parent->key[i + 1];
    for(i = key_index + 1; i < parent->key_num + 1; i++)
        parent->seek[i] = parent->seek[i + 1];
    parent->key_num--;

    left->key[left->key_num] = save_key;
    left->key_num++;
    for(i = 0; i < right->key_num; i++)
        left->key[i + left->key_num] = right->key[i];
    if(right->seek[0] != -1)
        for(i = 0; i < right->key_num + 1; i++)
        {
            left->seek[i + left->key_num] = right->seek[i];
            btree_node *child = calloc(1, sizeof(btree_node));
            if(child == NULL)
                return BTREE_ERR;
            if(btree_read_disk(tree, right->seek[i], child) == BTREE_ERR)
                return BTREE_ERR;
            child->parent = left->self;
            if(btree_write_disk(tree, child->self, child) == BTREE_ERR)
                return BTREE_ERR;
            free(child);
        }
    left->key_num += right->key_num;
    if(tree->root->self == parent->self && parent->key_num == 0)
    {
        left->parent = -1;
        *tree->root = *left;
        tree->root_position = tree->root->self;
    }
    btree_write_disk(tree, parent->self, parent);
    btree_write_disk(tree, left->self, left);
    btree_write_disk(tree, right->self, right);
    write_header(tree);
    return BTREE_OK;
}