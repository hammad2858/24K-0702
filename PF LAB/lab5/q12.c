#include <stdio.h>

int main() {
 float attendance,assign_score,exam,weightage;
 char grade;
 
 printf("Enter Attendance : ");
 scanf("%f",&attendance);
 printf("Enter Assignment Score : ");
 scanf("%f",&assign_score);
 printf("Enter Exam Score : ");
 scanf("%f",&exam);
   
   weightage = assign_score*0.2 + attendance*0.3 + exam*0.5;
   
   if (weightage>=90){
       grade = 'A';
   }
   else if (weightage> 80){
       grade = 'B';
   }
   else if(weightage> 60){
       grade = 'C';
   }
   else {
       grade = 'F';
   }
  printf("Final weightage :  %f \n",weightage);
  printf("Final Grade : %c \n",grade);
  
  return 0;
