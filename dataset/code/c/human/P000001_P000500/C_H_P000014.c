/******************************************************
 * File         :   Area.c
 * Description  :   C Program calculate area of rectangle 
 *                  perimeter of rectangle  
 * Author       :   Sarju S
 * Version      :   1.0
 * Date         :   28/05/2021
 * ***************************************************/
#include<stdio.h>
int main(){
    int length, breadth,areaOfRectangle,perimeter;
    int radius;
    float areaOfCircle;
    float circumference;
    printf("\nEnter the Length of the rectangle:");
    scanf("%d",&length);
    printf("\nEnter the Breadth of the rectangle:");
    scanf("%d",&breadth);

   

    //Area of Rectangle
    areaOfRectangle = length * breadth;
    printf("Area of Rectangle with Length=%d and Breadth=%d is:%d",length,breadth,areaOfRectangle);

    



    return 0;
}