#include <stdio.h>

int main() {
   
    int array[2][3][3] = {
        { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} },  // Page 1
        { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} }  // Page 2
    };
    
    int sumPage1 = 0;
    int sumPage2 = 0;

    
    for (int page = 0; page < 2; page++) {
        int pageSum = 0;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                pageSum += array[page][row][col];
            }//for col ends
        }// for row ends
        
       
        if (page == 0) {
            sumPage1 = pageSum;
        } 
        else {
            sumPage2 = pageSum;
        }
    }// for page ends

    printf("Sum of elements on Page 1: %d \n", sumPage1);
    printf("Sum of elements on Page 2: %d \n", sumPage2);

    return 0;
}