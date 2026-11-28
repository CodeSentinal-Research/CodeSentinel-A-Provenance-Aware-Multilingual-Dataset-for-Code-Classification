/*

Problem 2: Reverse Only Letters

Description:
Given a string s, reverse the string only when the characters are letters. 
Keep all non-letter characters in their original positions.

Function Signature (C):
char* reverseOnlyLetters(char* s);

Instructions:
1. Use two pointers: one at the start, one at the end.
2. Move each pointer until both point to letters.
3. Swap the letters and continue inward.
4. Skip over digits and special characters.

Example:
Input:  s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Test Cases:
Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

Input: "Ab-cd"
Output: "dc-bA"

*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

char* reverseOnlyLetters(char* str);


int main(){
    
   char str[50];
   printf("Input: ");
   scanf(" %[^\n]", str);
   
   char *rev = reverseOnlyLetters(str);
   printf("Output: %s", rev);
    
}

char* reverseOnlyLetters(char* str){
    int length = strlen(str);
    int i = 0;
    int j = length - 1;
    while(i < j){
        if(!isalpha(str[i])){
            i++;
            continue;
        }
        if(!isalpha(str[j])){
            j--;
            continue;
        }
        
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    
    return str;
}


