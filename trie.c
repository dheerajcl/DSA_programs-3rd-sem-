#include<stdio.h>
#include<stdlib.h>


typedef struct trieNode
{
	struct trieNode* child[26];
	int EOW;
}NODE;

typedef struct trieStack
{
	NODE* n;
	int index;
}STACK;

char word[100];
int length;
STACK s[100];
int top;

NODE* getNode()
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	for(int i=0;i<26;i++)
		temp->child[i] = NULL;
	temp->EOW = 0;
	return temp;
}

void insert(NODE* root, char* key)
{
	NODE* p;
	int i, index;
	p = root;
	for(i=0;key[i]!='\0';i++)
	{
		index = key[i]- 'a';	//get ascii value of char
		if(p->child[index] == NULL)
			p->child[index] = getNode();
		p = p->child[index];
	}
	p->EOW = 1;
}

void display(NODE* p)//.........,int count
{
	int i,j;
	for(i=0;i<26;i++)
	{
		if(p->child[i]!=NULL)
		{
			word[length++] = i + 'a';//get ascii value of char
			
			if(p->child[i]->EOW == 1)
			{
				printf("\n");
				for(j=0;j<length;j++)
					printf("%c", word[j]);
			}
		
		display(p->child[i]);
		}
	}
	length--;
	return ;

}
void display_length(NODE* p, int count)
{
	int i,j;
	for(i=0;i<26;i++)
	{
		if(p->child[i]!=NULL)
		{
			word[length++] = i + 'a'; //get ascii value of char
			if((p->child[i]->EOW == 1) && (length==count))
			{
				printf("\n");
				for(j=0;j<length;j++)
					printf("%c", word[j]);
			}
		
		display_length(p->child[i], count);
		}
	}
	length--;
	return ;

}
void display_prefix(NODE* root, char* key)
{
	NODE* p = root;
	int i,j,index;
	for(i=0;key[i]!='\0';i++)
	{
		index = key[i] - 'a';

		if(p->child[index]!=NULL)
		{
			word[length++] = index + 'a';//get ascii value of char
			p = p->child[index];
		}
		else
			return;
	}
	if(p->EOW == 1)
	{
		printf("\n");
		for(j=0;j<length;j++)
			printf("%c", word[j]);
	}
		
	display(p);
		
}
int search(NODE* root, char* key)
{
	int i, index;
	NODE* p = root;
	for(i=0;key[i]!='\0';i++)
	{
		index = key[i]- 'a';	//get ascii value of char
		if(p->child[index] == NULL)
			return 0;
		p = p->child[index];
	}
	if(p->EOW == 1)
		return 1;
	return 0;
}

void push(NODE* x, int k)
{
	top++;
	s[top].n = x;
	s[top].index = k;
}

STACK pop()
{
	STACK temp;
	temp = s[top];
	top--;
	return temp;
}

int check(NODE* root)
{
	int i,count=0;
	NODE* p = root;
	for(i=0;i<26;i++)
		if(p->child[i]!=NULL)
			count++;
	return count;
}

void delete(NODE* root,char* key)
{
	int i,index,k;
	STACK x;
	NODE* p =root;
	for(i=0;key[i]!='\0';i++)
	{
		index = key[i]-'a';
		if(p->child[index]==NULL)
		{
			printf("word not found\n");
			return;
		}
		push(p,index);//before going to next node, to keep track of path
		p = p->child[index];//p->child[index] = NULL
	}
	
	p->EOW = 0;
	push(p,-1);
	
	while(1)
	{
		x = pop();
		if(x.index!=-1)
			x.n->child[x.index] = NULL;
		if(x.n == root)
			break;
		k = check(x.n);
	if (k>=1 || x.n->EOW == 1)
		break;
	else
		free(x.n);x.n=NULL;
	}
	return;
}

int main()
{
	char key[100];
	NODE* root = getNode();
	int ch;
while(1)
{	
	printf("\nenter 1- insert, 2- dispaly, 3-search, 4- display length 5-display_prefix, 6-delete\n");
	scanf("%d", &ch);	
	switch(ch)
	{
		case 1: printf("enter word\n");
			scanf("%s", key);
			insert(root,key);
			break;
		case 2: length =0 ;
			display(root);
			break;
		case 3: printf("\nenter word\n");
			scanf("%s", key);
			int r = search(root,key);
			if(r==1)
				printf("present\n");
			else
				printf("Not present\n");
			break;
		case 4: length =0 ;
			printf("enter the length of word to be displayed\n");
			int count;
			scanf("%d", &count);
			display_length(root, count);
			break;	
		case 5: length =0 ;
			printf("enter the word to be checked for\n");
			
			scanf("%s",key);
			display_prefix(root, key);
			break;	
		case 6: length =0 ;
			printf("enter the word to be deleted\n");
			
			scanf("%s",key);
			delete(root, key);
			break;	
	}
}
return 0;
}


/*
int countWordsWithPrefix(NODE* root, char* prefix)
{
    NODE* p = root;
    int index;

    // Traverse the trie to the node that represents the last character of the prefix
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        index = prefix[i] - 'a';
        if (p->child[index] == NULL)
        {
            return 0; // Prefix not found in trie
        }
        p = p->child[index];
    }

    // Count the number of words that start with the prefix
    return countWords(p);
}

int countWords(NODE* node)
{
    if (node == NULL)
    {
        return 0;
    }

    // Count this node if it represents the end of a word
    int count = node->EOW;

    // Count words in the subtrees
    for (int i = 0; i < 26; i++)
    {
        count += countWords(node->child[i]);
    }

    return count;
}
*/