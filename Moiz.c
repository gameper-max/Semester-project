#include <stdio.h> 
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
int main() { 
    int dir; 
    dir = getdir(); 
    printf("direction selected = %d \n",dir); 
    return 0; 
}
