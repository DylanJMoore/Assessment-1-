/*This code performs a decrytpiton on a rotation cypher. It will do this granted that the key of the cypher is known.
It requires a input of the key then the message can be read. It must be run in terminal.
Ensure that there is no spaces at the end of the read file*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LTH 26                                      //makes the length of the string 26 so it can store words with up to 25 letters

char decrypt(char *wrd, int key);                       //this is the function for encrypting 

int main()
{
    char wrd[STR_LTH];                                  //declares string as a char to store the letters as ASCII
    int key=0;                                          //declares the key as an interger equal to zero so the code knows that there was no input
    FILE *EncryptedText;                                //sets a pointer to the file EncryptedText so it can read off it
    EncryptedText=fopen("EncryptedText.txt","r");       //opens and reads the file
    FILE *DecryptedText;
    DecryptedText=fopen("DecryptedText.txt","w");       //sets a pointer to the file DecryptedText so it can write to it
    printf("Enter the value of the rotation cypher:\n");//prompts the user to input the key of the cypher
    scanf("%d",&key);                                   //reads the users input and stores it at key
    if(key!='\0')                                       //only continues if there is an input from the user
    {
        while(!feof(EncryptedText))                         // makes a loop so that while the file is still going it will read and decrypt the message
        {
            
            fscanf(EncryptedText,"%s",wrd);                 //reads a word in the file then stores it in a string on wrd
            decrypt(wrd, key);                              //calls the decrypt function to that string wrd       
            printf("%s ",wrd);                              //prints the decrypted text to the console
            fprintf(DecryptedText, "%s ",wrd);              //opens and writes the decrypted text in the file over the previous stored data
        
        }
        printf("\n");                                       //prints new line to the console for easier veiwing 
        fprintf(DecryptedText, "\n");                       //prints new line to file
        fclose(EncryptedText);                              //closes file to stop an infinite loop
        fclose(DecryptedText);                              //closes file to stop an infinite loop
    }
    else if(key=='\0')
    {
        printf("Try again entering the cypher value though the terminal again\n"); // reads if there was no input
    }
    else if(key==0)
    {
        printf("Enter a number other than zero\n");                               //prompts the user to try again using a key value 
    }

  return 0;
}

char decrypt(char *wrd, int key)                         //definition to the function
{
    
    int i=0;                                            //declares i as an int to act as a counter to move through the string wrd and also to finsh encoding when the string is over
    for(i = 0;i < STR_LTH;i++)                          //for the length of the string the following code will execute 
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
       
        wrd[i]=wrd[i]-key;                              //shifts char value of a letter value up by an amount changing it to a new letter
        
        if(wrd[i]+key==39)
        {
            wrd[i]=39;
        }
        if(wrd[i]+key==34)
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
        }                            //if the value is below A(65) as a result of the shift then it goes to the end of the alphabet
        
    }
    return 0;
}
