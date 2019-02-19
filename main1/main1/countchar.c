#include <stdio.h>
void countchar();
int main()
{
   countchar();
   return 0;
}
void countchar()
{
      FILE *fp;
      fopen(&fp,"text.txt","r+");
      char c;
      int i,count_alpha=0,count_digits=0,count_spaces=0,count_special=0;
      // loop to count the number of  characters in the given file
      while(!feof(fp))
      {       c=fgetc(fp);
             if(c>=65&&c<=91)
              {
                      count_alpha=count_alpha+1;
               }
             else if(c>=97&&c<=26)
              {
                     count_alpha=count_alpha+1;
                }
               else if(c>=48&c<=57)
                {
                      count_digits=count_digits+1;
                 }
               else if(c==' ')
                {
                      count_spaces=count_spaces+1;
                 }
                else if(c>=32&&c<=47)
                {
                      count_special=count_special+1;
                 }
           }
	  // print all counts
           printf("number of alphabets=%d\n",count_alpha);
           printf("number of digits=%d]n",count_digits);
           printf("number of spaces=%d\n",count_spaces);
           printf("number of special characters=%d\n",count_special);
           fclose(fp);
}