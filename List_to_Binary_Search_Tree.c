/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int finddepth(struct TreeNode *node) {
    if (!node) return 0;
    int df = finddepth(node->left) + 1;
    int dr = finddepth(node->right) + 1;
    return df>dr?df:dr;
}

void insert(struct TreeNode *root, struct ListNode *node) {
    struct TreeNode *leaf = malloc(sizeof(struct TreeNode));
    leaf->right = NULL;
    leaf->left = NULL;
    leaf->val = node->val;
    struct TreeNode *temp = root;
    int value = node->val;
    while (1){
        if (temp->val > value) {
            if (!(temp->left)) {
                temp->left = leaf;
                break;
            }
            else temp = temp->left;
        }
        else {
            if (!(temp->right)) {
                temp->right = leaf;
                break;
            }
            else temp = temp->right;
        }
    }
}

struct TreeNode *findnode(struct TreeNode *root) {
    if (!root) return NULL;
    int df = finddepth(root->left);
    int dr = finddepth(root->right);
    struct TreeNode *t1 = findnode(root->left);
    struct TreeNode *t2 = findnode(root->right);
    if (!t1 && !t2 && abs(df-dr) < 2) return NULL;
    else if (t1) return t1;
    else if (t2) return t2;
    else return root;
}


struct TreeNode *toBST(struct TreeNode *root, struct ListNode *node) {
    if (!node) return root;
    insert(root, node);
    int status = 4;
    struct TreeNode *cur = findnode(root); 
    if (!cur) status = 0;
    else {
        status = 4;
        if (cur->val > node->val) {
            if (cur->left->val > node->val) status = 1;
            else status = 2;
        }
        else {
            if (cur->right->val > node->val) status = 3;
            else status = 4;
        }
    }
    //printf("status: %d\n", status);   
    if (status == 0) {
        return toBST(root, node->next);
    }
    else {
        switch (status) {
            case 1: {
                int v1 = cur->val;
                int v2 = cur->left->val;
                struct TreeNode *n1 = cur->left;
                struct TreeNode *n2 = cur->left->left;
                struct TreeNode *temp = cur->left->right;
                cur->val = v2;
                cur->left->val = v1;
                cur->left = n1->left;
                cur->right = n1;
                n1->left = n1->right;
                n1->right = temp;
                return toBST(root, node->next);
            }
            case 2: {
                int v1 = cur->val;
                int v3 = cur->left->right->val;
                struct TreeNode *n1 = cur->left->right;
                struct TreeNode *temp = cur->right;
                cur->val = v3;
                n1->val = v1;
                cur->right = n1;
                cur->left->right = n1->left;
                n1->left = n1->right;
                n1->right = temp;
                return toBST(root, node->next);
            }
            case 3: {
                int v1 = cur->val;
                int v3 = cur->right->left->val;
                struct TreeNode *n1 = cur->right->left;
                struct TreeNode *temp = cur->left;
                cur->val = v3;
                n1->val = v1;
                cur->left = n1;
                cur->right->left = n1->right;
                n1->right = n1->left;
                n1->left = temp;
                return toBST(root, node->next);
            }
            case 4: {
                int v1 = cur->val;
                int v2 = cur->right->val;
                struct TreeNode *n1 = cur->right;
                struct TreeNode *n2 = cur->right->right;
                struct TreeNode *temp = cur->left;
                cur->val = v2;
                cur->left = n1;
                cur->right = n2;
                cur->left->val = v1;
                n1->right = n1->left;
                n1->left = temp;
                return toBST(root, node->next);
            }
        }
    }
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if (!head) return NULL;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->right = NULL;
    root->left = NULL;
    root->val = head->val;
    return toBST(root, head->next);
}
