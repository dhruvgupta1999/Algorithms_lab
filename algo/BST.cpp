#include <stdio.h>
#include <stdlib.h>
 #include <strings.h>
#include <string>
#include <iostream>
#include <sstream>


typedef struct node
{
	int data;
	struct node * left;
	struct node * right;
int flag;
}node;



node * createNode(int data)
{
	node * tmp=(node *)malloc(sizeof(node));
	tmp->data=data;
	tmp->right=tmp->left=NULL;
     tmp->flag=0;
	return tmp;

}

node* insertNode( node* node, int key) 
{ 
    
    if (node == NULL) return createNode(key); 
    if (key < node->data) 
        node->left  = insertNode(node->left, key); 
    else
        node->right = insertNode(node->right, key); 
    return node; 
} 
node * initializeTree(node * root)
{
	std::string line;
	int tmp;
	getline( std::cin, line );
		
			
			std::istringstream iss( line );
                        
			while(iss>>tmp)
			{
				
				root=insertNode(root,tmp);
			}

 return root;
}

 node * minValueNode( node* tmp) 
{ 
    while (tmp->left != NULL) 
        tmp = tmp->left; 
    return tmp; 
} 
  
 node* deleteNode( node* root, int key) 
{ 
     
    if (root == NULL) return root; 
   
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
   
    else
    { 
        
        if (root->left == NULL) 
        { 
             node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
             node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
         node* temp = minValueNode(root->right); 
   
        root->data = temp->data; 
        root->flag=1;

        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

void printPostorder(node* tmp) 
{ 
    if (tmp == NULL) 
        return; 
    printPostorder(tmp->left);  
    printPostorder(tmp->right); 

    std::cout << tmp->data << " ";
if(tmp->flag==1)
std::cout << "Dhruv" << " "; 
} 

int main()
{
    node * root=NULL;
    printf("Initialize the tree:\n");
    root=initializeTree(root);
    while(1)
    {
    	printf("Enter 1 for insertion 2 for deletion 3 for post-order 4 to quit:\n");
    	int tmp;
    	scanf("%d",&tmp);
    	if(tmp==1)
    	{
    		printf("Enter value to insert:\n");
    		scanf("%d",&tmp);
    		insertNode(root,tmp);
    	}
    	else if (tmp==2)
    	{
    		printf("Enter value to delete:\n");
    		scanf("%d",&tmp);
    		deleteNode(root,tmp);

    	}
    	else if (tmp==3)
    	{
    		printPostorder(root);
                printf("\n");
    	}
    	else
    		break;



    }
//printf("root node: %d \n",root->data);


}
