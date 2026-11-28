// #include <stdio.h>
// int main() {
//     // Define a 2D array with 3 rows and 4 columns
//     int array[3][4] = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12}
//     };
//     // Print the 2D array
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 4; j++) {
//             printf("%d ", array[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }


// TAKING INPUT 
// #include <stdio.h>
// int main() {
//     int array[3][3];
//     // Print the 2D array
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++) {
//             scanf("%d", &array[i][j]);
//         }
//     }
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++) {
//             printf("%d ", array[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int rows, columns;
//     printf("Enter the number of rows: ");
//     scanf("%d", &rows);
//     printf("Enter the number of columns: ");    
//     scanf("%d", &columns);
//     int array[rows][columns];
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<columns; j++){
//             printf("Enter element [%d][%d]: ", i, j);
//             scanf("%d", &array[i][j]);
//         }
//     }
//     printf("The 2D array is:\n");
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<columns; j++){
//             printf("%d ", array[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// write a program to store roll number and marks obtained by 4 students by 4 students side by side in a matrix
// #include<stdio.h>
// int main(){
//     int students[4][2];
//     for(int i=0; i<4; i++){
//         printf("Enter roll number and marks for student %d: ", i+1);
//         scanf("%d %d", &students[i][0], &students[i][1]);
//     }
//     printf("Roll Number\tMarks\n"); 
//     for(int i=0; i<4; i++){
//         printf("%d\t\t%d\n", students[i][0], students[i][1]);
//     }
//     return 0;
// }

// write a program to store 5*5 matrix and initialize all elements to 10
// #include<stdio.h>
// int main(){
//     int arr[5][5];
//     for(int i=0; i<5; i++){
//         for(int j=0; j<5; j++){
//             arr[i][j] = 10;
//         }
//     }
//     for(int i=0; i<5; i++){
//         for(int j=0; j<5; j++){
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// write a program to find the sum of two 2*2 matrices
// #include<stdio.h>
// int main(){
//     int arr1[2][2],arr2[2][2],sum[2][2];
//     printf("Enter elements of first matrix:\n");
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             scanf("%d", &arr1[i][j]);
//         }
//     }
//     printf("Enter elements of second matrix:\n");
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             scanf("%d", &arr2[i][j]);
//         }
//     }
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             sum[i][j] = arr1[i][j] + arr2[i][j];
//         }
//     }
//     printf("Sum of the matrices:\n");
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             printf("%d ", sum[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// without third matrix
// #include<stdio.h>
// int main(){
//     int arr1[2][2],arr2[2][2];
//     printf("Enter elements of first matrix:\n");
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             scanf("%d", &arr1[i][j]);
//         }
//     }
//     printf("Enter elements of second matrix:\n");
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             scanf("%d", &arr2[i][j]);
//         }
//     }
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             printf("%d ",arr1[i][j] + arr2[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int row1, col1, row2, col2,srow,scol;
//     printf("Enter the number of rows and columns for first matrix: ");
//     scanf("%d %d", &row1, &col1);
//     printf("Enter the number of rows and columns for second matrix: ");
//     scanf("%d %d", &row2, &col2);
//     if(row1 != row2 || col1 != col2){
//         printf("Matrices cannot be added. Please enter the same dimensions for both matrices.\n");
//         return 0;
//     }
//     else
//    {
//     srow= row1;
//     scol= col1;
//     int arr1[row1][col1],arr2[row2][col2],sum[srow][scol];
//     printf("Enter elements of first matrix:\n");
//     for(int i=0; i<row1; i++){
//         for(int j=0; j<col1; j++){
//             scanf("%d", &arr1[i][j]);
//         }
//     }
//     printf("Enter elements of second matrix:\n");
//     for(int i=0; i<row2; i++){
//         for(int j=0; j<col2; j++){
//             scanf("%d", &arr2[i][j]);
//         }
//     }
//     for(int i=0; i<srow; i++){
//         for(int j=0; j<scol; j++){
//             sum[i][j] = arr1[i][j] + arr2[i][j];
//         }
//     }
//     printf("Sum of the matrices:\n");
//     for(int i=0; i<srow; i++){
//         for(int j=0; j<scol; j++){
//             printf("%d ", sum[i][j]);
//         }
//         printf("\n");
//     }
//     }
//     return 0;
// }

// write a program to find the transpose of a matrix
// #include<stdio.h>
// int main(){
//     int row, col;
//     printf("Enter the number of rows and columns: ");
//     scanf("%d %d", &row, &col);
//     int arr[row][col], transpose[col][row];
//     printf("Enter elements of the matrix:\n");
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for(int i=0; i<col; i++){
//         for(int j=0; j<row; j++){
//             transpose[i][j] = arr[j][i];
//         }
//     }
//     printf("Transpose of the matrix:\n");
//     for(int i=0; i<col; i++){
//         for(int j=0; j<row; j++){
//             printf("%d ", transpose[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// write a program to find the transpose of a matrix without using third matrix
// #include<stdio.h>
// int main(){
//     int row, col;
//     printf("Enter the number of rows and columns: ");
//     scanf("%d %d", &row, &col);
//     int arr[row][col];
//     printf("Enter elements of the matrix:\n");
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     printf("Transpose of the matrix:\n");
//     for(int i=0; i<col; i++){
//         for(int j=0; j<row; j++){
//             printf("%d ", arr[j][i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
//transpose in place
// #include<stdio.h>
// int main(){
//     int row,col;
//     printf("Enter the number of rows and columns: ");
//     scanf("%d %d", &row, &col); 
//     if(row!=col){
//         printf("Matrix is not square, cannot transpose in place.\n");
//     }
//     else{
//     int arr[row][col];
//     printf("Enter elements of the matrix:\n");
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for(int i=0; i<row; i++){
//         for(int j=i+1; j<col; j++){  // j=i+1 to avoid swapping back
//             int temp = arr[i][j];
//             arr[i][j] = arr[j][i];
//             arr[j][i] = temp;
//         }
//     }
//     printf("Transpose of the matrix:\n");
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     }
//     return 0;
// }

// write a program to find the sum of rectangle made by two points(r1,c1) and (r2,c2) in a matrix
#include<stdio.h>
int main(){
    int row, col,r1,r2,c1,c2,sum=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);
    printf("Enter the range of rows and columns to find sum of rectangle made by(r1 r2 c1 c2): ");
    scanf("%d %d %d %d", &r1, &r2, &c1, &c2);
    int arr[row][col];
    printf("Enter elements of the matrix:\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=r1;i<=r2;i++){
        for (int j=c1;j<=c2;j++){
            sum+=arr[i][j];
        }
    }
    printf("Sum of the rectangle made by (%d,%d) and (%d,%d) is: %d\n", r1, c1, r2, c2, sum);
    return 0;
}

// #include<stdio.h>
// int main(){
//     int rows, columns,sum=0,max_sum=0,row_index=0;
//     printf("Enter the number of rows: ");
//     scanf("%d", &rows);
//     printf("Enter the number of columns: ");    
//     scanf("%d", &columns);
//     int arr[rows][columns];
//     printf("Enter elements of the matrix:\n");
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<columns; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<columns; j++){
//             sum +=arr[i][j];
//         }
//         if (sum>max_sum){
//             max_sum=sum;
//             row_index=i;
//         }
//         sum=0;
//     }
//     printf("Row with maximum sum is: %d\n", row_index);
//     printf("Maximum sum is: %d\n", max_sum);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int row,col,count=0,max_count=0,index_row=0;
//     printf("Enter the number of rows: ");
//     scanf("%d", &row);
//     printf("Enter the number of columns: ");    
//     scanf("%d", &col);
//     int arr[row][col];
//     printf("Enter elements of the matrix:\n");
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             if(arr[i][j]==1){
//                 count++;
//             }
//         }
//         if(count>max_count){
//             max_count=count;
//             index_row=i;
//         }
//         count=0;
//     }
//     printf("Row with maximum of 1's is : %d",index_row);
//     return 0;
// }

//Rotate a matrix by 90 degrees clockwise pehele transpose phir row wise reverse
// #include<stdio.h>
// int main(){
//     int row,col;
//     printf("Enter the number of rows and columns: ");
//     scanf("%d %d", &row, &col); 
//     if(row!=col){
//         printf("Matrix is not square, cannot transpose in place.\n");
//     }
//     else{ 
//         int arr[row][col];
//     printf("Enter elements of the matrix:\n");
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for(int i=0; i<row; i++){
//         for(int j=i+1; j<col; j++){  // j=i+1 to avoid swapping back
//             int temp = arr[i][j];
//             arr[i][j] = arr[j][i];
//             arr[j][i] = temp;
//         }
//     }
//     for(int i=0;i<row;i++){
//         int j=0;
//         int k=row-1;
//         while(j<k){
//             int temp=arr[i][j];
//             arr[i][j]=arr[i][k];
//             arr[i][k]=temp;
//             j++;
//             k--;
//         }
//     }
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int row1,col1,row2,col2;
//     printf("Enter the number of rows: ");
//     scanf("%d",&row1);
//     printf("Enter the number of columns: ");    
//     scanf("%d",&col1);
//     printf("Enter the number of rows: ");
//     scanf("%d",&row2);
//     printf("Enter the number of columns: ");    
//     scanf("%d",&col2);
//     if(col1!=row2){
//         printf("Matrix multiplication is not possible.\n");
//         return 0;
//     }
//     else{
//     int arr2[row2][col2];
//     int arr1[row1][col1];
//     printf("Enter elements of the matrix1:\n");
//     for(int i=0; i<row1; i++){
//         for(int j=0; j<col1; j++){
//             scanf("%d",&arr1[i][j]);
//         }
//     }
//     printf("Enter elements of the matrix2:\n");
//     for(int i=0; i<row2; i++){
//         for(int j=0; j<col2; j++){
//             scanf("%d",&arr2[i][j]);
//         }
//     }
//     int arr3[row1][col2];
//     for(int k=0;k<row1;k++){
//         for(int l=0;l<col2;l++){
//             arr3[k][l]=0;
//             for(int m=0;m<col1;m++){
//                 // i row of arr1 and j column of arr2
//                 arr3[k][l]+=arr1[k][m]*arr2[m][l];
//             }
//         }
//     }
//     printf("Multiplication of the matrices:\n");
//     for(int m=0;m<row1;m++){
//         for(int n=0;n<col2;n++){
//             printf("%d ",arr3[m][n]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// }

