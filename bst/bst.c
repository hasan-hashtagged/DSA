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
struct node *find(int x,struct node *p) {
	if(p==NULL)
		return NULL;
	else if(p->data==x)
		return p;
	else if(p->data>x)
		find(x,p->left);
	else
		find(x,p->right);
}
struct node *find_min(struct node *p) {
	if(p==NULL)
		return p;
	while(p->left)
		p=p->left;
	return (p);
}
struct node *find_max(struct node *p) {
	if(p==NULL)
		return p;
	while(p->right)
		p=p->right;
	return p;
}
struct node *predecessor(int x,struct node *p) {
	struct node *q=find(x,root);
	if(q->left)
		return (find_max(q->left));
	else {
		struct node *pre=NULL,*temp=p;
		while(q!=temp) {
			if(temp->data < q->data) {
				pre=temp;
				temp=temp->right;
			}
			else
				temp=temp->left;
		}
		return pre;
	}
}
struct node *successor(int x,struct node *p) {
	struct node *q=find(x,root);
	if(q->right)
		return (find_min(q->right));
	else {
		struct node *succ=NULL,*temp=p;
		while(q!=temp) {
			if(q->data < temp->data) {
				succ=temp;
				temp=temp->left;
			}
			else
				temp=temp->right;
		}
		return succ;
	}
}
struct node *delete(int x,struct node *p) {
	if(p->data > x)
		p->left=delete(x,p->left);
	else if(p->data < x)
		p->right=delete(x,p->right);
	else {
		if(p->left==NULL) {
			struct node *q=p->right;
			p->right=NULL;
			return q;
		}
		else if(p->right==NULL) {
			struct node *q=p->left;
			p->left=NULL;
			return q;
		}
		else {
			struct node *q=find_min(p->right),*r=p->right;
			q->left=p->left;
			p->left=NULL;
			p->right=NULL;
			return r;
		}
	}
	//return p;
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
			if(find(x,root)!=NULL)
				printf("Found\n");
			else
				printf("Not Found\n");
		}
		else if(ch=='m') {
			struct node *p=find_min(root);
			if(p)
				printf("%d\n",p->data);
			else
				printf("-1\n");
		}
		else if(ch=='M') {
			struct node *p=find_max(root);
			if(p)	
				printf("%d\n",p->data);
			else
				printf("-1\n");
		}
		else if(ch=='r') { //inorder predecessor
			scanf("%d",&x);
			if(root==NULL || (find(x,root)==NULL)) //the number is not present
				printf("NOT FOUND\n");
			else {
				struct node *p=predecessor(x,root);
				if(p)
					printf("%d\n",p->data);
				else
					printf("NIL\n"); //No predecessor
			}
		}
		else if(ch=='s') { //inorder successor
			scanf("%d",&x);
			if(root==NULL || (find(x,root)==NULL))
				printf("NOT FOUND\n");
			else {
				struct node *p=successor(x,root);
				if(p)
					printf("%d\n",p->data);
				else
					printf("NIL\n"); //No successor
			}
		}
		else if(ch=='d') {
			scanf("%d",&x);
			if(find(x,root)==NULL)
				printf("-1\n");
			else
				root=delete(x,root);
		}
		else if(ch=='z')
			break;
	}
}
