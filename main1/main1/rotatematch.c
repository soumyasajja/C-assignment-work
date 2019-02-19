#include <stdio.h>
#include <string.h>
void rotatematch();
int main()
{
    rotatematch();
    return 0;
}
void rotatematch()
{
      FILE *fp2;
      fopen(&fp2,"text.txt","w+"); 
      char str[20],temp,c[100];
      int i,j=0,len_str,k,l;
      printf("enter a word to match the file text:\n");
      gets(str);
      len_str=sizeof(str)/sizeof(str[0]);
      // loop to copy the contents of file to string
      for(;fp2!=EOF;fp2++)
      { 
          c[i]=fgetc(fp2);
          i++;
       } 
       // loop for rotation
      for(i=0;c[i]='\0'&&str[j]!='\0';i++)
      {
           if(c[i]==str[j])
            {
                 j++;
                 for(k=0,l=len_str-1;k<l;k++,l--)
                 {
                       temp=str[k];
                       str[k]=str[l];
                        str[l]=temp;
                  }
               
        }
      }
      printf("%s",str);
      // loop to copy the contents of string to file
     for(;fp2!=EOF;fp2++)
       { 
           for(i=0;str[i]!='\0';i++)
           {
            fputc(str[i],fp2);
           }
        }
      fclose(fp2);
}