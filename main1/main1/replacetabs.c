#include <stdio.h>
void replacetabs();
int main()
{
    replacetabs();
    return 0;
}
void replacetabs()
{
     FILE *fp3;
     fopen(&fp3,"text.txt","w+");
     char s='\t',c[100];
      int i;
      // loop to copy contents of file to string
      for(;fp3!=EOF;fp3++)
      {
            c[i]=fgetc(fp3);
            i++;
       }
       // loop to replace tabs
        for(i=0;c[i]!='\0';i++)
        {
            if(c[i]=='	')
            {
                c[i]='\t';   
             }
        }
       printf("%s",c);
       // loop to copy string contents to file
       for(;fp3!=EOF;fp3++)
       { 
           for(i=0;c[i]!='\0';i++)
           {
            fputc(c[i],fp3);
           }
        }
        fclose(fp3);
}