#include <stdio.h>  
#include <ctype.h> 

void getcord( int *row, int *col) { 
   printf(" please enter your row for e.g. (B)\n");  
   char inputr;  
   int inputc;
   int lettervalid; 
   int numbervalid;
   scanf(" %c",&inputr)  ;
   inputr= toupper(inputr); 
   if( inputr >='A' && inputr <='J') { 
      lettervalid=0;
   } else { 
      do { 
         printf(" please enter  a correct row \n") ;
         scanf(" %c",&inputr); 
         inputr=toupper(inputr);
      } while(inputr < 'A' || inputr >'J');
   }
   printf(" please enter your column for e.g. (4)\n")  ;
   scanf("%d",&inputc);  
   if(inputc >= 1 && inputc<=10 ) {  
      numbervalid =0 ; 
      
   } else { 
      do { 
         printf(" please enter a correct column ");  
         scanf("%d",&inputc); 
      } while(inputc < 1 || inputc > 10)  ;

   }
   *row=inputr - 'A'; 
   *col=inputc - 1; 
   
   } 
   int main() {
    int row, col;

    getcord(&row, &col);

    printf("Row: %d, Column: %d\n", row, col);

    return 0;
} 

   
