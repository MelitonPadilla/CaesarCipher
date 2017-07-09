//////////////////////////////////////////////////////////////////////////////
/*

   FileName: caesarCipher.cpp

   Description: 
    Caesar Cipher decryption tool. The input ciphertext can be of any 
    size; can handle symbols that are not English letters; Given a ciphertext, 
    can print out all possible plaintext under different off sets (keys)

   Author: Meliton Padilla

   Version: 1

   Data: March, 2, 2016

*/
///////////////////////////////////////////////////////////////////////////////

// Headers
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Globals

// Functions

   /** decrypt will decrypt the ciphertext taken in from input
       @param: Input provided from user 
       @pre none
       @post will run through all possible keys for cesar cipher
       @return char that will be added to new decrypted  string*/
    char decrypt(char input, int key);


    /** outputKeys will cycle through all possible keys and return each possible 
        one to the user
        @param: Input provided from user 
        @pre none
        @post will run through all possible keys for cesar cipher
        @return char that will be added to new decrypted  string */
    void allKeys(string display,int shift);



// Main

int main()
{

   // Initialize Variables
     int num = 0;
     int key = 0;
     string ciphertext;
     string output ="";

   // Ask user to provide ciphertext to decrypt
     cout<<" Input ciphertext to be decrypted "<<endl;

   // store text and start decrpt function
     getline(cin,ciphertext);

   // output plaintext and other possible key decrypts
     
     // Loop through all possible keys under 26 letters of alphabet
      for( key = 0; key < 26; key++)
        {

       // Clear output for next key generation 
        output = '\0';
       // Loop through provided input to send one character at a time
        for(num = 0; num < ciphertext.length(); num++)
          {

             output += decrypt(ciphertext[num],key);

          }

          // output all possible keys for ciphertext dycrption
          cout<<"key: "<<key<<endl;
          cout<<output<<endl<<endl;

        }

  return 0;
}


// Function Implmentation 

char decrypt(char input, int shift){

   // Initialize Variables
	int temp;

   // Test to see if it is a letter
     if( isalpha(input))
       {

         // Convert to uppercase to make sure we stick to one set of the alphabet
            input = toupper(input); 

         // change value to a postive intger to stay within 26 letters of ascii
            //temp = abs((input-65) - shift);
            temp = (input+65) - shift;

         // Cesar shift to decrypt charcter key, will change to determine offset 
            input = ( temp % 26) +65;
       }

    // if not a letter return back to be stored in proper location in plaintext
       return input;

   }
