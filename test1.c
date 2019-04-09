#include <stdio.h>
#include <string.h>

#define STR_LTH 25                                  //makes the length 25

char encrypt(char *wrd);                            //function for encrypting 

int main()
{
    char wrd[STR_LTH];
    FILE *TextToEncrypt;
    TextToEncrypt=fopen("TextToEncrypt.txt","r");
    File *EncryptedText;
    Encryptedtext=fopen("EncryptedText.txt","w");
    while(!feof(TextToEncrypt))
    {
        fscanf(TextToEncrypt,"%s",wrd);    
        encrypt(wrd);                                     //calls function
        printf("%s ",wrd);
        
    }
    printf("\n");

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
        wrd[i]=wrd[i]+3;                              //shifts char value up 2
    }
    return 0;
}