#include<stdio.h>
int main()
{
	FILE *f1,*f2;
	char c;
	f1=fopen("input1.c","r");
	f2=fopen("without_comments.txt","w");
	c=fgetc(f1);
	while(c!=EOF) 
	{
		if(c=='/')
		{
			c=fgetc(f1);
			
				if(c=='/'){
				
		   		while(c!='\n')
	       		{
	       			c=fgetc(f1);
	    	 
		   		}
			}
		else if(c=='*')
         {
		 	c=fgetc(f1);
         	while(c!=EOF)
         	{
         		if(c=='*')
         		{
         			
         			c=fgetc(f1);
         			if(c=='/')
         			break;
				 }
				 c=fgetc(f1);
	       }
		}
         
        }
		else
		{
		  fputc(c,f2);
          printf("%c",c);
        
		}
           c=getc(f1);
           
    }    fclose(f1);
         fclose(f2);
}


