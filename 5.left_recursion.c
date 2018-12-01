#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char str[100],alpha[100][100],beta[100][100];
	int i,c,a,b,ch;
	do{
	a=0;b=0;
	printf("Enter the input string:\n");
		scanf("%s",&str);
	//printf("%c %c\n",str[0],str[3]);
	if(str[0]!=str[3])
	{
		printf("There is no problem of left recursion\n");
		printf("%s",str);
		exit(0);
	}
	else
	{	printf("\n\n");
i=3;
		while(str[i]!='\0')
		{

if(str[i]==str[0])
			{
				i++;
				c=0;
				while(str[i]!='|' && str[i]!='\0') 
				{
					alpha[a][c]=str[i];
					c++;
					i++;
				}
				alpha[a][c]='\0';
				a++;
			}
			

else
			{
				c=0;
				while(str[i]!='|' && str[i]!='\0')
				{
					beta[b][c]=str[i];
					c++;
					i++;
				}
				beta[b][c]='\0';
				b++;
			}
			if(str[i]!='\0')
				i++;

			}
/*for(i=0;i<a;i++)
			printf("%s\n",alpha[i]);
		for(i=0;i<b;i++)
			printf("%s\n",beta[i]);*/
		printf("%c -> %s%c` ",str[0],beta[0],str[0]);
		for(i=1;i<b;i++)
			printf("| %s%c` ",beta[i],str[0]);
		printf("\n%c` ->",str[0]);
		for(i=0;i<a;i++)
			printf(" %s%c` | ",alpha[i],str[0]);
		printf("null\n");
	}
	for(i=0;i<strlen(str);i++)
	str[i]='\0';
	printf("Do you want to continue?\n");
	printf("Enter 1 if yes and 0 if no\n");
	scanf("%d",&ch);
}while(ch!=0);
}

