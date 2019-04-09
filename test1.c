#include <stdio.h>
#include <string.h>

#define STR_LTH 26                                      //makes the length 25

char encrypt(char *wrd, int key);                       //function for encrypting 

int main()
{
    char wrd[STR_LTH];                                  //declares string
    int key;
    FILE *TextToEncrypt;                                //sets a pointer to the file TextToEncrypt
    TextToEncrypt=fopen("TextToEncrypt.txt","r");       //opens and reads the file
    FILE *EncryptedText;
    EncryptedText=fopen("EncryptedText.txt","w");
    printf("Enter a value to rotate the letters by:\n");
    scanf("%d",&key);    
    
    while(!feof(TextToEncrypt))                         // makes a loop so that while the file is still going
    {
        fscanf(TextToEncrypt,"%s",wrd);                 //reads a word in the file then stores it in a string
        encrypt(wrd, key);                             //calls function to that string       
        printf("%s ",wrd);                              //prints the encrypted text to the console
        fprintf(EncryptedText, "%s ",wrd);              //prints encrypted text to the file EncryptedText
    }
    printf("\n");                                       //prints new line to the console
    fprintf(EncryptedText, "\n");                       //prints new line to file
    fclose(TextToEncrypt);                              //closes file
    fclose(EncryptedText);                              //closes file
  return 0;
}

char encrypt(char *wrd, int key)
{
    
    int i=0;                                            //declares i as an int
    for(i = 0;i < STR_LTH;i++)                          //for thr length of the string 
    {
        if(wrd[i] == '\0')                              //if the word ends return 0
        {
            return 0;
        }
        wrd[i]=wrd[i]+key;                                //shifts char value up by an amount
    }
    return 0;
}