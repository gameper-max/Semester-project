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


int getdir() {  
    int inputd; 
    printf(" please enter your direction { 0=Right,1=Down,2=Left,3=Up}\n");  
    scanf("%d",&inputd);  
    while(inputd<0 || inputd>3) { 
        printf(" please enter a valid direction \n"); 
        scanf("%d",&inputd); 
    }  

    return inputd;
    
 
    
}

  
 void displayplayerboard(int dpbarr[2][10][10])  {  
   //dpbz = layer
     int i; 
     int j;  
     printf("    1  2  3  4  5  6  7  8  9  10\n");
  for(i=0;i<10;i++)
     {printf("%c  ",'A'+i);
    for(j=0;j<10;j++) {   
         ; 
        if( dpbarr[0][i][j] == 0) { 
            printf(" . ");
        } else if ( dpbarr[0][i][j]>=1 && dpbarr[0][i][j]<=5) { 
            printf(" S "); 
        } else if ( dpbarr[0][i][j]==99) { 
            printf(" X "); 

        } else if ( dpbarr[0][i][j]== -1) { 
            printf(" O ");
        }
         

    } printf("\n");
  }
 } 


#include <stdio.h> 
 void displaycpuboard(int dcbarr[2][10][10]) { 
   
    int i; 
    int j; 
    printf("   1  2  3  4  5  6  7  8  9  10\n"); 
    for(i=0;i<10;i++) {
        printf("%c ",'A'+i);
        for(j=0;j<10;j++) { 
            if(dcbarr[1][i][j]==0) {
                printf(" . ");
            } if(dcbarr[1][i][j]==-1) { 
                printf(" O ");
            } if(dcbarr[1][i][j]==99) {
                printf(" X ");
            } if(dcbarr[1][i][j]>=1 && dcbarr[1][i][j]<=5 ) { 
                printf(" . ");
            }
        } printf("\n");
    }
 } 






int main() { 
    int dir; 
    dir = getdir(); 
    printf("direction selected = %d \n",dir); 
    return 0; 
}
