#include<stdio.h>
#include<string.h>

int *ship_id; // most imp step global pointer toa cccess everytwhere
int *ship_sunk=0;
int *ship_size;//danail will tell column no in arr_ship_details
bool  *turn_change_flag=false,*game_end=false;

int arr_location[][][];//danial provides these
int arr_ship_details[][][];// danial provides 
// concept if ship hit write x otherwise  write -1 and 
// manipulate it in main  arr_location
// if locatrion already 99 or -1 do again thrpugh a flagcheck
// if cell 0 or any number btw 0 and 9 thren do hit or miss 
// turn base system 
void hit_input_mechanism(arr_location,sizeof(arr_location));
int hit_input_rows();//gets row user hits 
int hit_input_columns();//gets colums user hits
void manipulate_arrlocation(hit_input_rows,hit_input_columns,int arr_location,sizeof(arr_location),char*cell_status);
// take input modulele for hit to get thrpughh getcoords() provided by moiz
//  hit_coords sepertae them using kast and first digit mod logic

int main(){


      
}
void  hit_input_mechanism(int arr_location,sizeof(arr_location),int *rows/*write &rows in parametre */,int *columns/*similar*/,int player_no){
    bool is_input=True;
     
    while(is_input== True){
              //  imp*** supposed five ships here be aware!!!!!! ****** imp
        if(arr_location[player_no][rows][columns] >=0 && arr_location[player_no][rows][columns] <=5 ){
                is_input= false;
     
      
        }else{
            *rows=hit_input_rows();
            *columns=hit_input_columns();

        }
      
}
}
int hit_input_rows(){
    int user_input=getcoords();
    int rows =user_input%10;
  
    return rows;

}
int hit_input_columns(){
    user_input/=10;
    int columns=user_input%10;
}  //&cell_status and &rows and &columns
void manipulate_arrlocation(int arr_location,sizeof(arr_location),char *cell_status,player_no){
  // i for inavlid target(either overlapping or out of bound ) , h for hit target and w for water 
    /*liten call correct */hit_input_mechanism();/**most imp***correction add parametres paramatres*/
       
         do {
                if (arr_location[player_no][*rows][*columns]==0){
               arr_location[player_no][*rows][*columns]=-1;
               *turn_change_flag =true;

          }elseif(arr_location[player_no][*rows][*columns]>0 &&arr_location[player_no][*rows][*columns]<5){
             *ship_id=arr_location[player_no][*rows][*columns];
            
            
            
            
            
            arr_location[player_no][*rows][*columns]=99;

              arr_ship_details[player_no][*ship_id][*ship_size]-=;
              
          }
         }while(check_allship_sunk( player_id, *ship_id)|| turn_change_flag==true);             
             
    
if (check_allship_sunk( player_id, *ship_id)){
    *game_end=true;
}

         


}
// later initIALIZE PLAYER_ID AND SHIP)ID ACCORIDING TO INDEX USED BY DAINAL IN MAIN
// concept to make or acccess ship_id at that  point
//ship_size = ship_id 
bool  check_allship_sunk(int player_id,int *ship_id){
   int flag=true
   for(int i=0 =;i<5;i++){

    if (arr_ship_details[player_id][i][*ship_size]== 0){
          *ship_sunk++;
   }else{
      flag =false;
   }
}
   return flag;
}
