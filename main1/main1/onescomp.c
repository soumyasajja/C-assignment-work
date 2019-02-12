#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
       if(argc!=2)
       {
          printf("invalid number of arguments");
        }
      FILE *fp;
      fp=fopen(argv[1],"w+");
      char ch[20],a;
      unsigned char ch1;
      int len;
      if(fp==NULL)
      {
            printf("cannot open file\n");
            return;
       }
           gets(ch);
           len=strlen(ch);
          for(int i=0;i<len;i++)
           {
                a=ch[i]; 
                fputc(a,fp);
        }
       fseek(fp,-(len),SEEK_END);
       while(!feof(fp))
        {
                ch1=fgetc(fp);         
               printf("%u ",~ch1);
               //fputc(~ch1,fp);
        }
         fclose(fp);
         return 0;
}