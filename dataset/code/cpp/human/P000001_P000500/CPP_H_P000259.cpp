#include <iostream>
#include <cctype>


using namespace std;



void convertToUppercase(char *);
void printCharacters(const char *);

int main()
{

    char phrase[] = "The dove was singing his favorite song";

    printCharacters(phrase);

    cout<<phrase<<endl;

    convertToUppercase(phrase);



    cout<<phrase;





    return 0;
}
void convertToUppercase(char *sPtr){

    while ( *sPtr != '\0'){
        if (islower(*sPtr)){
            *sPtr = toupper(*sPtr);

        }

        *sPtr++;

    }

}
void printCharacters(const char *sPtr){
    for(; *sPtr != '\0'; *sPtr++){

    }


}
