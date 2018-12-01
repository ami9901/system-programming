#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char str[100],alpha[100][100],beta[100][100];
int i,c,a,b,ch;
do{
a=0;b=0;
printf("Enter the input string:\n");
scanf("%s",&str);
if(str[0]!=str[3])
{
printf("There is no problem of left recursion\n");
printf("%s",str);
exit(0);
}
else

{
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
printf("%c -> %s{%s}*",str[0],beta[0],alpha[0]);
}
for(i=0;i<strlen(str);i++)
str[i]='\0';
printf("Do you want to continue?\n");
printf("Enter 1 if yes and 0 if no\n");
scanf("%d",&ch);

}while(ch!=0);
}

