#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

double evaluate(TreeNode* root) {
    if (root == NULL) {
        return 0.0;
    }
    if (root->data >= '0' && root->data <= '9') {
        return (double)(root->data - '0'); // ���� ����� ��� ���� ��ȯ
    }

    double leftValue = evaluate(root->left);
    double rightValue = evaluate(root->right);

    switch (root->data) {
    case '+':
        printf("%.2lf + %.2lf = %.2lf\n", leftValue, rightValue, leftValue + rightValue);
        return leftValue + rightValue;
    case '-':
        printf("%.2lf - %.2lf = %.2lf\n", leftValue, rightValue, leftValue - rightValue);
        return leftValue - rightValue;
    case '*':
        printf("%.2lf * %.2lf = %.2lf\n", leftValue, rightValue, leftValue * rightValue);
        return leftValue * rightValue;
    case '/':
        printf("%.2lf / %.2lf = %.2lf\n", leftValue, rightValue, leftValue / rightValue);
        return leftValue / rightValue;
    default:
        return 0.0;
    }
}

int main() {
    TreeNode* root = createNode('+');
    root->left = createNode('-');
    root->right = createNode('9');
    root->left->left = createNode('+');
    root->left->right = createNode('/');
    root->left->left->left = createNode('+');
    root->left->left->right = createNode('*');
    root->left->left->left->left = createNode('2');
    root->left->left->left->right = createNode('3');
    root->left->left->right->left = createNode('4');
    root->left->left->right->right = createNode('5');
    root->left->right->left = createNode('6');
    root->left->right->right = createNode('7');

    printf("���� Ʈ�� ��� ����:\n");
    double result = evaluate(root);
    printf("��� ���: %.2lf\n", result);

    // �޸� ����
    // (���� ���ø����̼ǿ����� �޸� ������ �� �Ű��� �մϴ�)
    free(root->left->left->left);
    free(root->left->left->right);
    free(root->left->left);
    free(root->left->right->left);
    free(root->left->right->right);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
