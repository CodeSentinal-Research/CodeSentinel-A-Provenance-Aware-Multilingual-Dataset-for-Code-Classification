/*
    Converts an integer from one base to another.

    Dan Ross
    Aug 2022

    Supports any base between 3 and 36.  Integers are represented
    as strings consisting of a subset of the following character mapping:

    0         1         2         3
    012345678901234567890123456789012345
    0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    EXAMPLE: 42 base10 = 101010 base2 = 2A base16 = 60 base 7 = 16 base36

    Also converts 3-letter base 4 sequences of the following digits

    GATC
    3210

    EXAMPLES:
        CCC = 0x4^2 + 0x4^1 + 0x4^0 =  0 +  0 + 0 =  0
        GGG = 3x4^2 + 3x4^1 + 3x4^0 = 48 + 12 + 3 = 63
        ACT = 2x4^2 + 0x4^1 + 1x4^0 = 32 +  0 + 1 = 33

    Also adds strings representing numbers in any base up to 35
    Examples:

    BEEF base 35 + FEED base 35 = QSSS base 35
    ABBA base 16 + ACDC base 16 = 15896 base 16
    PROF base 22 + ROSS base 22 = 2A99L base 22


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning( disable : 4996) 
#pragma warning( disable : 4244) 

// Used for conversion between character and numeric values
// digits[0] = '0'; digits[10] = 'A', etc
//const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Actually not used because I found a better way, keeping for posterity

/*
Calculates base raised to the power exp
*/
int my_pow(int base, int  exp)
{
    int x = 1;
    for (int i = 0; i < exp; i++)
        x *= base;

    return x;
}

int idx_from_digit(char c){
    // I was going to iterate through the array but this is faster
    // Suggested by Copilot in VSCode
    // Normally I would do it my way, but this is just way better.
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else
        return -1; // error
}

/*
Converts an alphanumeric string 's' representation of a base 'base' number
to internal binary format.
Returns the value as a 32 bit integer
*/
long my_atoi(char* s, int base)
{
    long total = 0;
    int position = 0;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--){ // For each character in the input string
        // Find the numeric value of the character
        int val = idx_from_digit(s[i]);
        val = val * my_pow(base, position);
        // Add to a running total
        total += val;
        position++;
    }
    return total;
}

/*
Converts a 32 bit integer 'n' into an alphanumeric string 'sOut'
representation of a base 'base' number
*/
void my_itoa(long n, char* sOut, int base)
{
    int len = strlen(sOut);
    char temp[len];
    int quotient = n;
    int remainder = 0;
    int i = 0;
    do {
        remainder = quotient % base;
        quotient = quotient / base;
        // Convert the regular number into our special-base number
        // by converting to a character
        if (remainder < 10) temp[i++] = '0' + remainder;
        else                temp[i++] = 'A' + (remainder - 10);

    } while (quotient > 0);
    // Now reverse the string
    int j = 0;
    while (i > 0){
        sOut[j++] = temp[--i];
    }

}


/*
Converts an integer to base 4 codon format
*/
void itoDNAcodon(char* codon, int i)
{
    long asInteger = my_atoi(codon, 4); // get a base 10 integer from the codon
    for(int i = 0; i < strlen(codon); i++) {
        switch(asInteger % 4) {
        case 0:
            codon[strlen(codon) - 1 - i] = 'C'; break;
        case 1:
            codon[strlen(codon) - 1 - i] = 'T'; break;
        case 2:
            codon[strlen(codon) - 1 - i] = 'A'; break;
        case 3:
            codon[strlen(codon) - 1 - i] = 'G'; break;
        }
    }
}


/*
Returns the base 4 value of a codon
*/
int DNAcodontoi(char codon[4])
{
    int d0, d1, d2, value;

    switch (codon[2])
    {
    case 'C':
        d0 = 0; break;
    case 'T':
        d0 = 1; break;
    case 'A':
        d0 = 2; break;
    case 'G':
        d0 = 3; break;
    }

    switch (codon[1])
    {
    case 'C':
        d1 = 0; break;
    case 'T':
        d1 = 1; break;
    case 'A':
        d1 = 2; break;
    case 'G':
        d1 = 3; break;
    }

    switch (codon[0])
    {
    case 'C':
        d2 = 0; break;
    case 'T':
        d2 = 1; break;
    case 'A':
        d2 = 2; break;
    case 'G':
        d2 = 3; break;
    }

    // the base 4 value of the codon
    value = d2 * 16 + d1 * 4 + d0;

    return value;
}



/*
Adds 2 numbers in any base.

Arguments:
input s1, s2, base, return sum
*/
void addInBase(char s1[], char s2[], char sum[], int base)
{
    // error check base
    if (base < 2 || base > 36){
        strcpy(sum, "Error");
        return;
    }

    // Operand, Operand, Result
    char n1[30], n2[30], n3[30];

    // initialize numerical arrays to all zeros
    {
        for (int i = 0; i < 30; i++){
            n1[i] = 0;
            n2[i] = 0;
            n3[i] = 0;
        }
    }

    // copy chars to numerical arrays in reverse order
    {
        // Right-Padding code was suggested by Github Copilot
        int len1 = strlen(s1);
        int len2 = strlen(s2);

        for (int i = 0; i < 30; i++) {
            // Right-align and pad with zeros
            n1[i] = (i < 30 - len1) ? 0 : idx_from_digit(s1[i - (30 - len1)]);
            n2[i] = (i < 30 - len2) ? 0 : idx_from_digit(s2[i - (30 - len2)]);
        }
    }

    // do the actual addition
    // loop thru the numerical array
    {
        for(int i = 30 - 1; i >= 0; i--){
            n3[i] += n1[i] + n2[i];
            // Carry handling implementation suggested by GitHub Copilot
            if (n3[i] >= base){
                n3[i] -= base;
                if(i > 0) n3[i - 1]++; // carry the one
                else printf("Overflow, result too big!\n");
            }
        }
    }

    // find first non zero from "left"
    int firstNonZeroIndex = -1;
    for (int i = 0; i < 30 - 1; i++){
        if(n3[i] == 0){ n3[i] = ' '; } // replace leading zeros with spaces
        else {
            firstNonZeroIndex = i;
            break;
        }
    }

    // copy numbers back to string and reverse order
    {
        for(int i = firstNonZeroIndex, j = 0; i < 30; i++, j++){
            sum[j] = n3[i] + '0'; // add '0'
            if (n3[i] > 9) sum[j] += 7; // if number > 9 then add another 7
        }
    }
    // add the null terminator
    sum[30 - firstNonZeroIndex] = 0;

}

int main()
{
    char sIn[] = "16";
    char sOut[80];
    long n = 0;

    // convert some wacky base to internal representation
    n = my_atoi(sIn, 36);
    printf("%s base 36 is %d base 10\n", sIn, n);

    // convert back to some wacky base
    my_itoa(n, sOut, 11);
    printf("%d base 10 is %s base 11\n", n, sOut);

    // DO SEVERAL MORE

    // now do it with DNA 
    char muhGenes[4] = "ACT";
    n = DNAcodontoi(muhGenes);
    printf("%s in DNA is %d base 10\n", muhGenes, n);

    // back to DNA cuz we can
    char buffy[4];
    itoDNAcodon(buffy, n);
    printf("%d base 10 is %s in DNA\n", n, muhGenes);

    // test adding strings in arbitrary bases
    char s1[] = "543";
    char s2[] = "210";
    char sum[20];
    int b = 6;
    addInBase(s1, s2, sum, b);
    printf("%s + %s in base %d is %s\n", s1, s2, b, sum);
}