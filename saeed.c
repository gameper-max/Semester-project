#include<stdio.h>
#include<string.h>
#include <stdbool.h>
int ship_id; // most imp step global pointer toa cccess everytwhere
int ship_sunk=0;
int ship_size=1;//danail will tell column no in arr_ship_details
int PLAYER_ID = 0;
bool  turn_change_flag, game_end=false;
int arr_location[2][10][10];//danial provides these

int arr_ship_details[2][5][3];// danial provides 
// concept if ship hit write x otherwise  write -1 and 
// manipulate it in main  arr_location
// if locatrion already 99 or -1 do again thrpugh a flagcheck
// if cell 0 or any number btw 0 and 9 thren do hit or miss 
// turn base system 

int rows;//gets row user hits 
int columns;            //gets colums user hits

// take input modulele for hit to get thrpughh getcoords() provided by moiz
//  hit_coords sepertae them using kast and first digit mod logic
// --- FUNCTION PROTOTYPES ---

// Moiz's  cord generator's prototype 
void getcord(int *r, int *c);
void random_cordinate(int *r, int *c);

// Saeed's game_engine's prototypes for all functions 
void getcord_mechanism(int PLAYER_ID);
void hit_input_mechanism(int player_no);
bool check_allship_sunk(int player_no);
int winner_declare(int PLAYER_ID);
void turn_change();
void manipulate_arrlocation();

 
void getcord_mechanism(int PLAYER_ID) {  
    switch(PLAYER_ID) { 
        case 0: getcord(&rows,&columns);    
        break;
        case 1: random_cordinate(&rows,&columns); 
        break;
    }

}
 
void  hit_input_mechanism(int player_no){
    bool is_input=true;
    
     getcord_mechanism(PLAYER_ID);
    while(is_input== true){
              //  imp supposed five ships here be aware!!!!!!  imp
        if(arr_location[player_no][rows][columns] >=0 && arr_location[player_no][rows][columns] <=5 ){
                is_input= false;
     
      
        }else{ 
            getcord_mechanism(PLAYER_ID); 

           

        }
      
}
}
/*int hit_input_rows(){       
    int user_input=getcoords();
    int rows =user_input%10;
  
    return rows;

}
int hit_input_columns(){
    user_input/=10;
    int columns=user_input%10;
}  // &rows and &columns / */
void manipulate_arrlocation(){
  // i for inavlid target(eiher overlapping or out of bound ) , h for hit target and w for water 
    /*liten call correct  most impcorrection add parametres paramatres */
        turn_change_flag=false;
        int player_no =!PLAYER_ID;
         do {
             
             // i for inavlid target(either overlapping or out of bound ) , h for hit target and w for water 
               /*liten call correct */hit_input_mechanism(player_no);/*most impcorrection add parametres paramatres*/
                if (arr_location[player_no][rows][columns]==0){ 
                  printf(" Commander you missed the target. Recalibrate!\n");
               arr_location[player_no][rows][columns]=-1;
               turn_change_flag =true;

          }else if(arr_location[player_no][rows][columns]>0 &&arr_location[player_no][rows][columns]<=5){ 
            printf(" BULLSEYE! you hit the enemy ship")
             ship_id=arr_location[player_no][rows][columns];
            
            
            
            
            
            arr_location[player_no][rows][columns]=99;

              arr_ship_details[player_no][ship_id - 1][ship_size]-=1;
            o  if(arr_ship_details[player_no][ship_id - 1][ship_size]==0){ 
               printf(" You sunk their ship! congrats commander\n");
                ship_sunk++;
              }
              
          }
         }while(!check_allship_sunk( player_no) &&  turn_change_flag==false);             
             
    
if (check_allship_sunk( player_no)){
    game_end=true;
    winner_declare(PLAYER_ID);

}

         


}
// later initIALIZEPLAYER_ID AND SHIP)ID ACCORIDING TO INDEX USED BY DAINAL IN MAIN
// concept to make or acccess ship_id at that  point
//ship_size = ship_id 
bool  check_allship_sunk(int player_no){
   int flag=true;
   for(int i=0 ;i<5;i++){

    if (arr_ship_details[player_no][i][ship_size]== 0){
          
   }else{
      flag =false;
   }
}
   return flag;
}
int  winner_declare(int PLAYER_ID){
    int winner;
    
       switch(PLAYER_ID){
        case 0: printf("You are winner");
               winner=0;
               break;
        case 1: printf("BOT is winnner ");
               winner =1;
               break;

       

    }
    return winner ;
}

void turn_change(){
    if (turn_change_flag==true){
        switch(PLAYER_ID){
        case 0: PLAYER_ID=1;
        break;
        case 1:PLAYER_ID=0;
        break;

       } 
    }
    
}
int main(){
    while(!game_end){
        manipulate_arrlocation();
        if(!game_end){
            turn_change();
        }
    }
}
