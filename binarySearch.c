#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

int ikili_arama_agaci_mi(struct bin_tree* node)
{
  if (node == NULL)
    return 1;

  if (node->left != NULL && node->left->data > node->data)
    return 0;

  if (node->right != NULL && node->right->data < node->data)
    return 0;

  if (!ikili_arama_agaci_mi(node->left) || !ikili_arama_agaci_mi(node->right))
    return 0;

  return 1;
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}
int tek_cocuklu_dugum_sayisi(struct bin_tree *root){

        int c=0;


        if (root == NULL){
                return c;
        }


        if (root->left != NULL && root->right == NULL ||
                root->left == NULL && root->right != NULL){
                c++;
        }


        c = c+ tek_cocuklu_dugum_sayisi(root->left)+tek_cocuklu_dugum_sayisi(root->right);


}

void main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 35);
    insert(&root, 60);
    insert(&root, 80);
    insert(&root, 10);
    insert(&root, 25);
    insert(&root, 40);
    insert(&root, 90);
    insert(&root, 25);
    insert(&root, 12);
    insert(&root, 17);

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    /* Search node into tree */
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

    printf("\n\n %d\n", tek_cocuklu_dugum_sayisi(root));
    printf("\n\n %d\n", ikili_arama_agaci_mi(root));
    /* Deleting all nodes of tree */
    deltree(root);
}
