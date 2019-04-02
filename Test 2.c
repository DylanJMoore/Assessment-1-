#include <stdio.h>
#include <string.h>

char encrypt(char wrd[25],char wrd1[25]);

int main()
{
  char wrd[25], wrd1[25],wrd2[25];             //makes 4 strings to store a word each 
  scanf("%s %s %s",wrd[25],wrd1[25],wrd2[25]);          //scans the iput of words and stores them
  encrypt(wrd);
  encrypt (wrd1);
  encrypt (wrd2);
  printf("%s %s %s",wrd[25],wrd1[25],wrd2[25]);         //prints the words 
  return 0;
}

char encrypt(char)
{
    char n=0;
    char i=0;
    while(char &wrd[i] != 0);
        {
            i=n;
            n+4=n;
            i++;
            return n;
        }

}