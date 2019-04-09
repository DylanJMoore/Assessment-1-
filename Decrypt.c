#include <stdio.h>
#include <string.h>

#define STR_LTH 26                                      //makes the length 25

char decrypt(char *wrd, int key);                       //function for encrypting 

int main()
{
    char wrd[STR_LTH];                                  //declares string
    int key=0;
    FILE *EncryptedText;                                //sets a pointer to the file TextToEncrypt
    EncryptedText=fopen("EncryptedText.txt","r");       //opens and reads the file
    FILE *DecryptedText;
    DecryptedText=fopen("DecryptedText.txt","w");
    printf("Enter the value of the rotation cypher:\n");
    scanf("%d",&key);    
    if(key!=0)
    {
    while(!feof(EncryptedText))                         // makes a loop so that while the file is still going
    {
        fscanf(EncryptedText,"%s",wrd);                 //reads a word in the file then stores it in a string
        decrypt(wrd, key);                             //calls function to that string       
        printf("%s ",wrd);                              //prints the encrypted text to the console
        fprintf(DecryptedText, "%s ",wrd);              //prints encrypted text to the file EncryptedText
    }
    printf("\n");                                       //prints new line to the console
    fprintf(DecryptedText, "\n");                       //prints new line to file
    fclose(EncryptedText);                              //closes file
    fclose(DecryptedText);                              //closes file
    }
    else
    {
        printf("Try again entering the cypher value again\n");
    }

  return 0;
}

char decrypt(char *wrd, int key)
{
    
    int i=0;                                            //declares i as an int
    for(i = 0;i < STR_LTH;i++)                          //for thr length of the string 
    {
        if(wrd[i] == '\0')                              //if the word ends return 0
        {
            return 0;
        }
        wrd[i]=wrd[i]-key;                                //shifts char value up by an amount
    }
    return 0;
}
