#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
}*root=NULL;
struct node* insert(struct node *p,struct node *root) {
	if(root==NULL) {
		root=p;
		return root;
	}
	else if(root->data>=p->data)
		root->left=insert(p,root->left);
	else
		root->right=insert(p,root->right);
}
void preorder(struct node *p) {
	if(p==NULL)
		return;
	printf("%d ",p->data);
	preorder(p->left);
	preorder(p->right);
}
void inorder(struct node *p) {
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
}
void postorder(struct node *p) {
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
}

int main() {
	char ch;
	int x;
	while(1) {
		scanf("%c",&ch);
		if(ch=='i') {
			scanf("%d",&x);
			struct node *p=(struct node *)malloc(sizeof(struct node));
			p->data=x;
			p->left=NULL;
			p->right=NULL;
			root=insert(p,root);
		}
		else if(ch=='p') {
			preorder(root);
			printf("\n");
		}
		else if(ch=='a') {
			inorder(root);
			printf("\n");}
		else if(ch=='b') {
			postorder(root);
			printf("\n");
		}
		else if(ch=='s')
			break;
	}
}
