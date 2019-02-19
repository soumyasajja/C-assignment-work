#include <stdio.h>
void removecomm();
int main()
{
    removecomm();
    return 0;
}
void removecomm()
{
     FILE *fp1;
     fopen(&fp1,"text.txt","w+");
     char s1[4]="//";
     char s2[4]="/*";
     char s3[4]="*/";
     int i,j=0,k=0,l=0;
     char c[100];
     //loop to copy the contents of file to string
     for(;fp1!=EOF;fp1++)
     {     
            c[i]=fgetc(fp1);
             i++;
       }
       //loop to remove the comments from string
       for(i=0;c[i]!='\0';i++)
        {   
            if(c[i]==s1[j]&&c[i]!='\n')
            {
                  c[i]='\0';
                  j++;
              }
            else if(c[i]==s2[j])
             {
                    while(c[i]!=s3[l])
                      {
                            c[i]='\0';
                             l++;
                       }
               }
        }
        // loop to copy the contents of string to file
        for(;fp1!=EOF;fp1++)
       { 
           for(i=0;c[i]!='\0';i++)
           {
            fputc(c[i],fp1);
           }
        }
       printf("%s",c);
      fclose(fp1);
}

          