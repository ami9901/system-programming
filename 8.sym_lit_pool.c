#include<stdio.h>
#include<string.h>
int strcomp(char *s1,char *s2)
{
	int c1=0;
	if(strlen(s1)!=strlen(s2))
		return 0;
	while(s1[c1]!='\0')
	{
		if(s1[c1]!=s2[c1])
		return 0;
		c1++;
	}
	return 1;
}
void incr(char lc[])
{
        if(lc[2]=='9')
        {
            lc[1]++;
            lc[2]='0';
        }
        else
            lc[2]++;
}
int main()
{
	FILE *s;
	char ch,str[10],str2[10],lc[4],temp[4];
    char SYMTAB[10][20],LITTAB[10][10];
	int POOLTAB[10],total=0;
    int c=1,flag,i=0,j,l=1,p=2;
	char opcodes[14][10]={"START","READ","MOVER","MULT","MOVEM","STOP","DS","END","ORIGIN","ADD","SUB","BC","LTORG","EQU"};
	s=fopen("input8.txt","r");
	ch='0';
	while(feof(s)==0)
	{
		i=0;
		ch=getc(s);
        while(ch!=' '&&ch!='\n')
		{
			str[i]=ch;
			ch=getc(s);
			i++;
		}
		str[i]='\0';
		if(strcmp(str,opcodes[0])==0)
        {
            ch=getc(s);
            i=0;
            while(ch>='0'&&ch<='9')
            {
                lc[i]=ch;
                ch=getc(s);
                i++;
            }
            continue;
        }
        if(strcmp(str,"END")==0)
		{
			for(i=POOLTAB[p-1];i<=l;i++)
            {
                strcat(LITTAB[i],"\t");
                strcat(LITTAB[i],lc);
            }
			goto abc;
		}
		if(strcomp(str,"LTORG"))
		{
			POOLTAB[1]=1;
			POOLTAB[p]=l;
			for(i=POOLTAB[p-1];i<POOLTAB[p];i++)
            {
                strcat(LITTAB[i],"\t");
                strcat(LITTAB[i],lc);
                incr(lc);
            }
			p++;
			continue;
		}
		flag=0;
		for(j=0;j<14;j++)
		{
			if(strcomp(str,opcodes[j])==1)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			strcpy(SYMTAB[c],str);
			strcat(SYMTAB[c],"\t");
			if(strlen(str)<4)
                strcat(SYMTAB[c],"\t");
            fscanf(s,"%s",str);

			strcat(SYMTAB[c],lc);
			if(strcomp(str,"DS")==1)
            {
                strcat(SYMTAB[c],"\t");
                fscanf(s,"%s",str);
                strcat(SYMTAB[c],str);
                goto l2;
            }
			l1:strcat(SYMTAB[c],"\t1");
			l2:strcat(SYMTAB[c],"\0");
			c++;
		}
		if(ch==' ')
		{
			while(ch!='\n')
			{
				ch=getc(s);
				if(ch=='=')
				{
					i=0;
					while(ch!='\n')
					{
						str2[i]=ch;
						i++;
						ch=getc(s);
					}
					strcpy(LITTAB[l],str2);
					l++;
				}
			}
		}
		incr(lc);
	}
	abc:
	printf("\tSYMTAB\n");  	printf("\t------\n");
	for(i=1;i<c;i++)
	{
		printf("\t%d   %s\n",i,SYMTAB[i]);
	}
	printf("\n\tLITAB\n");  	printf("\t------\n");
	for(i=1;i<l;i++)
	{
		printf("\t%d   %s\n",i,LITTAB[i]);
	}
	printf("\n\tPOOLTAB\n");  	printf("\t------\n");
	for(i=1;i<p-1;i++)
	{
		printf("\t%d   %d\n",i,POOLTAB[i]);
	}
	return 0;
}

