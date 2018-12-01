#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char st[100];
int top=-1;
int ss[100];
int to=-1;

void pu(int i)
{
	ss[++to]=i;
}
int po()
{
    int d=ss[to];
    to--;
return d;
}
void push(char a)
{
    top++;
    st[top]=a;

}
char pop()
{

	char c=st[top];
		top--;
	return c;

}
int main()
{
    int j,l,i,d;
	char a,b;
	char s[100],r[3];
	scanf("%s",s);

	i=0;j=1;
	l=strlen(s);
	while(i!=l)
	{
    	if(isdigit(s[i])||isalpha(s[i]))
		{
        	push(s[i]);
    	}else
		{
        	printf("\n%c\t",s[i]);
			a=pop();
    		if(a=='t')
    		{	d=po();
        		printf("%c%d\t",a,d);
    		}else
			{
        		printf("%c\t",a);
        	}

       		 b=pop();
        	if(b!='t')
       	 	{	printf("%c\t",b);  
			}	
			else
			{
        	 	d=po();
        		printf("%c%d\t",b,d);
			}

  		 printf("t%d",j);
   		push('t');
  		 pu(j);
    		j++;
    	}

    	i++;

	}

return 0;
}

