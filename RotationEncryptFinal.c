//This code reads from a file full of capital letters and encrypts it with a key given by the user. It must be ran in terminal

#include <stdio.h>
#include <string.h>

#define STR_LTH 26                                      //makes the length 26 so the string can hold 25 letters which is within the usual letter count for english words 

char encrypt(char *wrd, int key);                       //function prototype used for encrypting 

int main()
{
    char wrd[STR_LTH];                                  //declares string with length STR_LTH defined above
    int key=0;                                          //Stores key as and integer zero 
    FILE *TextToEncrypt;                                //sets a pointer to the file TextToEncrypt where the text you wish to encrypt is held
    TextToEncrypt=fopen("TextToEncrypt.txt","r");       //opens and reads the file
    FILE *EncryptedText;                                //sets pointer to the file EncryptedText to output the encrypted text
    EncryptedText=fopen("EncryptedText.txt","w");       //opens such file
    printf("Enter a positive non-zero value to rotate the letters by:\n");  //gives user directions to enter a key for rotating the letters by
    scanf("%d",&key);                                                       //scans the user input and stores it at key
    if(key!=0)                                             //ensures that the user enters a functioning key
    {
    while(!feof(TextToEncrypt))                         // makes a loop so it reads the file till the end then stops 
    {
        wrd[0]='\0';
        fscanf(TextToEncrypt,"%s",wrd);                 //reads a word in the file then stores it in a string
        encrypt(wrd, key);                              //calls function to encrypt the string wrd       
        printf("%s ",wrd);                              //prints the encrypted text to the console
        fprintf(EncryptedText, "%s ",wrd);              //prints encrypted text to the file EncryptedText
    }
    printf("\n");                                       //prints new line to the console for easier user interface 
    fprintf(EncryptedText, "\n");                       //prints new line to file
    fclose(TextToEncrypt);                              //closes file
    fclose(EncryptedText);                              //closes file
    }
    else
    {
        printf("Try again using a non-zero number\n");  //if the user enters a non function number the code ends 
    }

  return 0;
}

char encrypt(char *wrd, int key)                        //function receives information about the text needed for encryption and how much to shift it by 
{
    
    int i=0;                                            //declares i as an int as zero to be used to navigate the string and as a counter to when the string ends 
    for(i = 0;i < STR_LTH;i++)                          //for the length of the string the code will shift the letters 
    {
        
        if(wrd[i] == '\0')                              //if the word ends the code returns and goes onto the next word
        {
            return 0;
        }
        else if(wrd[i]>96 && wrd[i]<123)
        {
            wrd[i]=wrd[i]-32;
        }
        else if(((wrd[i]<65 && wrd[i]!=39) && (wrd[i]<65 && wrd[i]!=34))  || wrd[i]>90)                 //if the value of wrd[i] is punctuation, there will be no change
        {
            return 0;
        }
       
        wrd[i]=wrd[i]+key;                              //shifts char value of a letter value up by an amount changing it to a new letter
        
        if(wrd[i]-key==39)
        {
            wrd[i]=39;
        }
        if(wrd[i]-key==34)
        {
            wrd[i]=34;
        }
        if(wrd[i]>90)                                   //if the char value is above Z then it shifts it back to the start of the alphabet beginning with A 
        {
            wrd[i]=wrd[i]-26;
        }
        else if(wrd[i]<65 && wrd[i]!=34 && wrd[i]!=39)                              //if the char value is below A then it shifts it back to the end of the alphabet at Z
        {
            wrd[i]=wrd[i]+26;
        }
        
    }
    return 0;
}
