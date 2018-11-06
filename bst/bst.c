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
int find(int x,struct node *p) {
	if(p==NULL)
		return -1;
	else if(p->data==x)
		return 1;
	else if(p->data>x)
		find(x,p->left);
	else
		find(x,p->right);
}
int find_min(struct node *p) {
	if(p==NULL)
		return -1;
	while(p->left)
		p=p->left;
	return (p->data);
}
int find_max(struct node *p) {
	if(p==NULL)
		return -1;
	while(p->right)
		p=p->right;
	return (p->data);
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
		else if(ch=='f') {
			scanf("%d",&x);
			if(find(x,root)==1)
				printf("Found\n");
			else
				printf("Not Found\n");
		}
		else if(ch=='m') {
			x=find_min(root);
			printf("%d\n",x);
		}
		else if(ch=='M') {
			x=find_max(root);
			printf("%d\n",x);
		}
		else if(ch=='s')
			break;
	}
}
