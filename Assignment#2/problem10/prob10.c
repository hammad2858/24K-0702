#include<stdio.h>
/*
 * This program prints a diamond-shaped pattern of stars.
 *
 * The pattern consists of:
 *  - A top half with increasing number of stars in each row.
 *  - A middle row with the maximum number of stars.
 *  - A bottom half with decreasing number of stars in each row.
 *
 * The length of each side of the diamond is determined by the input value N.
 * The center of the diamond is located at the middle row and middle column.
 */

int main(){
    int space , a , spaceinner , star , i , j , l;

    printf("Enter any number :");
    scanf("%d", &a);

    space = (a*2)-2;
    spaceinner = 0;


    for(i = 0; i <  a-1; i++){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < spaceinner; l++){
            printf(" ");
        }

        if(l != 0)
            printf("*");
        

        printf("\n");

        space--;
        if(i == 0)
            spaceinner++;
        else
            spaceinner+=2;
    }


    for(i = 0 ;  i < a; i++){
        printf("*");
    }

    for(i = 0;  i < spaceinner; i++){
        printf(" ");
    }

    for(i = 0 ;  i < a; i++){
        printf("*");
    }


    printf("\n");
    spaceinner = (spaceinner*2)-1;
    space = 1;

    for(i = 0; i < a-1;  i++){
        for(j = 0; j  < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0 ; l < spaceinner; l++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        spaceinner-=2;
        space++;

    }
    

    space = a-2;
    spaceinner = 1;
    for(i = 0; i < a-2; i++){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < space; l++){
            printf(" ");
        }
        printf("*");
        for(j = 0;  j < spaceinner; j++){
            printf(" ");
        }
        printf("*");
        for( j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        space --;
        spaceinner+=4;

    }
    spaceinner+=2;
    printf("*");
    for(j = 0; j < spaceinner; j++){
        printf(" ");
    }
    printf("*");
    return 0;
}
