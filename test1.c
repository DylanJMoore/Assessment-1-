#include <stdio.h>
#include <string.h>

#define STR_LTH 25
char encrypt(char *wrd);

int main()
{
  char wrd[STR_LTH]={'h','e','l','l','o','\0'};                   
  encrypt(wrd);
  printf("%s",wrd);                             //prints the words 
  return 0;
}

char encrypt(char *wrd)
{
    
    int i=0;
    for(i = 0;i < STR_LTH;i++)
    {
        if(wrd[i] == '\0')
        {
            return 0;
        }
        wrd[i]=wrd[i]+5;
        i++;
    }
    return 0;
}