#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *fi,*fo,*fop,*fk;
	int flag=0,i=1;
	char c,t,a[15],ch[15],file[20];
	fi=fopen("input2.c","r");
	fo=fopen("inter.c","w");
	fop=fopen("oper.c","r");
	fk=fopen("key.c","r");
	c=getc(fi);
	while(!feof(fi))
	{
		if(isalpha(c)||isdigit(c)||(c=='['||c==']'))
			fputc(c,fo);
		else
		{
			if(c=='\n')
				fprintf(fo,"\t$\t");
			else
				fprintf(fo,"\t%c\t",c);
		}
		c=getc(fi);
	}
	fclose(fi);
	fclose(fo);
	fi=fopen("inter.c","r");
	printf("\t\tLEXICAL ANALYSIS\n");
	fscanf(fi,"%s",a);
	printf("\n line: %d\n",i++);
	while(!feof(fi))
	{
		if((strcmp(a,"$")==0))
		{
			printf("\nline: %d\n",i++);
			fscanf(fi,"%s",a);
		}
		fscanf(fop,"%s",ch);
		while(!feof(fop))
		{
			if(strcmp(ch,a)==0)
			{
				fscanf(fop,"%s",ch);
				printf("\t\t%s\t\t%s\n",a,ch);
				flag=1;
			}
			fscanf(fop,"%s",ch);
		}
		rewind(fop);
		fscanf(fk,"%s",ch);
		while(!feof(fk))
		{
			if(strcmp(ch,a)==0)
			{
				fscanf(fk,"%s",ch);
				printf("\t\t%s\t:\tkeyword\n",a);
				flag=1;
			}
			fscanf(fk,"%s",ch);
		}
		rewind(fk);
		if(flag==0)
		{
			if(isdigit(a[0]))
			printf("\t\t%s\t:\tconstant\n",a);
			else
			printf("\t\t%s\t:\tidentifier\n",a);
		}
		flag=0;
		fscanf(fi,"%s",a);
	}
	return 0;
}
