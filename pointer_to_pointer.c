//如果想要可以重新配置記憶體位置(大小)，function(plus1)就要輸入其位址(意思就是前面一定要有*)
//比如說是一個二維陣列，int **array要改中間那層的記憶體位址(ex:[[1],[1,2,3]]--->[[1,2],[1,2,3]])，那function(plus1)就可以直接放int **array，因為輸入已經是改的地方的位址了

#include <stdio.h>
#include <stdlib.h>

void plus1(int **a) {
    *a = calloc(3, sizeof(int));
    (*a)[0] = 1;
    (*a)[1] = 2;
    (*a)[2] = 3;
    return;
}

int main()
{
    int *a = malloc(sizeof(int)*2);
    a[0] = 0;
    a[1] = 0;
    plus1(&a);

    printf("%d", a[2]);
    return 0;
}



//EXAMPLE1: leetcode_102

int maxDepthTree (struct TreeNode* root);
void InOrder (struct TreeNode* root, int** array, int* nums, int depth);
void arrayAdd (int** array, int size);

//這裡的columnSizes是一個一維陣列，但是因為需要重新配置記憶體位置，所以輸入是columnSizes的位址
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
  int maxDepth = *returnSize = maxDepthTree (root); 
  int** array = (int**) calloc (maxDepth, sizeof (int*));
  *columnSizes = (int *) calloc (maxDepth, sizeof (int));
  for (int i = 0; i < maxDepth; i++)
    (*columnSizes)[i] = 0;
  InOrder (root, array, *columnSizes, 0);
  return array;
}

int maxDepthTree (struct TreeNode* root)
{
  if (root == NULL)
    return 0;
  int DepthL = maxDepthTree (root->left) + 1;
  int DepthR = maxDepthTree (root->right) + 1;
  return DepthL > DepthR ? DepthL : DepthR;
}

void InOrder (struct TreeNode* root, int** array, int* nums, int depth)
{
  if (root == NULL)
    return;
  InOrder (root->left, array, nums, depth + 1);
  arrayAdd (&array[depth], nums[depth]);
  array[depth][nums[depth]++] = root->val;
  InOrder (root->right, array, nums, depth + 1);
}

//這邊因為需要重新配置記憶體位址(大小)，所以要用int **array當輸入(array[depth]的記憶體位址 = &array[depth])，不然如果只是改值，用int *array就可以了
void arrayAdd (int** array, int size)
{
  int* temp = *array;
  *array = (int *) calloc (size + 1, sizeof (int));
  for (int i = 0; i < size; i++)
    (*array)[i] = temp[i];
  free (temp);
}


//EXAMPLE2: leetcode_102(二維陣列修改中間記憶體位置)

void inorder(int **ans, struct TreeNode *node, int depth, int *returnColumnSizes) {
    if (!node) return;
    int size = (returnColumnSizes[depth]++) + 1;
    //printf("%p\n", ans[depth]);
    int *temp = ans[depth];
    ans[depth] = malloc(size*sizeof(int));
    for (int i = 0; i < size-1; i++)
        ans[depth][i] = temp[i];
    ans[depth][size-1] = node->val;
    /*
    for (int i = 0; i < size; i++) {
        printf("%d ", ans[depth][i]);
    }
    printf("\n");
    */
    //free(temp);
    inorder(ans, node->left, depth+1, returnColumnSizes);
    inorder(ans, node->right, depth+1, returnColumnSizes);
    return;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int depth = finddepth(root);
    //printf("%d\n", depth);
    *returnSize = depth;
    *returnColumnSizes = calloc(depth, sizeof(int));
    int **ans = malloc(sizeof(int*)*depth);
    for (int i = 0; i < depth; i++)
        ans[i] = calloc(1, sizeof(int));
    inorder(ans, root, 0, *returnColumnSizes);
    return ans;
}
