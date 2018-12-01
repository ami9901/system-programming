#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
	char g[20],p1[20],p2[20],new1[20],mod[20];
	int i,j=0,k=0,l=0,pos;

	cout<<"\n enter grammer a->";
	gets(g);
	for(i=0;g[i]!='|';i++)
	{
	p1[j]=g[i];
	j++;
	}
	p1[j]='\0';
	j=i+1;
	for(i=0;g[j]!='\0';j++,i++)
	{
	p2[i]=g[j];
	}
	p2[i]='\0';


	for(i=0;i<strlen(p1) || i<strlen(p2);i++)
	{
		if(p1[i]==p2[i])
		{
		new1[k]=p1[i];
		k++;
		pos=i+1;
		}
	}
	new1[k]='A';
	new1[++k]='`';
	new1[++k]='\0';
	for(i=pos,j=0;p1[i]!='\0';j++,i++)
	{
	mod[j]=p1[i];
}
	mod[j++]='|';
	for(i=pos;p2[i]!='\0';j++,i++)
	{
	mod[j]=p2[i];
	}
	mod[i]='\0';
cout<<"\n A->"<<new1;
cout<<"\n A'->"<<mod;

	return 0;
}

