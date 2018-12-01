#include<stdio.h>
#include<string.h>
struct sym_table{
    char name[100];
    int value;
    char type[10];
    int size;
    int address;
};
void main()
{
	FILE *s;
	s=fopen("input3.c","r");
	char key[4][20]={"int","float","double","char"};
	char ch;
	int c,i,flag=0,j,n=0,k,m,len,dec,count;
    char str1[50],str2[50],str3[3];
    struct sym_table arr[10];
    int add=100;
    for(i=0;i<10;i++)
    {
        arr[i].value=0;
    }
	ch=getc(s);
	while(ch!=EOF)
	{
		c=0;
		flag=0;
		while(ch!=' ' && ch!='\n')
        {
            if(ch=='"')
            {
                ch=getc(s);
                while(ch!='"')
                    ch=getc(s);
            }
            else
            {
                str1[c]=ch;
                c++;
            }
            ch=getc(s);
        }

        for(i=0;i<4;i++)
        {
            if(strcmp(str1,key[i])==0)
            {
                flag=1;
                break;
        	}
        }

        if(flag==1)
        {
            ch=getc(s);
        	while(ch!=';')
			{
				k=0;
        		while(ch!=',' && ch!=';')
        		{
        		    if(ch!='=' )
                    {
                        str2[k]=ch;
                        k++;
                        ch=getc(s);
                    }
        		    else if(ch=='=')
                    {
                        ch=getc(s);
                        str3[0]=ch;
                        m=1;
                        ch=getc(s);
                        while(ch!=';' && ch!=',')
                        {
                            str3[m]=ch;
                            m++;
                            ch=getc(s);

                        }
                        str3[m]='\0';
                        len=strlen(str3);
                        dec=0;
                        for(count=0;count<len;count++)
                            dec=dec*10+(str3[count]-'0');

                        arr[n].value=dec;
                       }
                }
				str2[k]='\0';
                strcpy(arr[n].name,str2);
                strcpy(arr[n].type,str1);
                for(i=0;i<4;i++)
                {
                    if(strcmp(str1,key[i])==0)
                    {
                        if(i==0)
                            arr[n].size=sizeof(int);
                        else if(i==1)
                            arr[n].size=sizeof(float);
                        else if(i==2)
                            arr[n].size=sizeof(double);
                        else
                            arr[n].size=sizeof(char);
                        arr[n].address=add+arr[n].size;
                        add+=arr[n].size;
                        break;
                    }
                }
				n++;
				for(j=0;j<k;j++)
                {
                str2[j]='\0';
                }
				if(ch!=';')
                    ch=getc(s);
			}
		}
        for(j=0;j<c;j++)
        {
            str1[j]='\0';
        }
		ch=getc(s);
	}
	printf("\n\t\t\t     SYMBOL TABLE\n");
	printf("\n\t\tName\tValue\tType\tSize\tAddress\n");
	printf("\t\t---------------------------------------\n");
	for(i=0;i<n;i++)
	{
             	printf("\t\t%s\t%d\t%s\t%d\t%d\n",arr[i].name,arr[i].value,arr[i].type,arr[i].size,arr[i].address);
	}
	printf("\n\n\n\n");
}

