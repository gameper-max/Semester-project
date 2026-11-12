#include <stdio.h>  
#include <ctype.h> 
#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <sys/time.h>



//moiz


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


//function that displays the users board


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


unsigned get_microseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}


void rc(int *rc_row , int *rc_col){
    srand(get_microseconds());
    *rc_row = rand()%10;
    Sleep(2);
    *rc_col = rand()%10;
    Sleep(2);
}


void random_cordinate(int *rac_row , int *rac_col, int rac_arr[10][10]){
    do { rc(rac_row,rac_col);}while(rac_arr[*rac_row][*rac_col] != 99 || rac_arr[*rac_row][*rac_col] != -1 );
}



/*
{








































}*/



//Daniyal

void board(int barr[2][10][10]){
    int i,j,k;
    for (k = 0; k<2; k++){
        for (i = 0; i<=9; i++){
            for (j = 0; j<=9; j++){
                barr[k][i][j] = 0;
        }
    }
}

}



void sae(int saarr[5][3]){
    //sae arr for direction live and Unique id 
    //unique id at x axis 0 live at x axis 1 and direction at x axis 2

    for(int j = 0;j <4;j++){
        saarr[j][0] = (5-j)*10;
        saarr[j][1] = 5-j;
    
}
    
}



void s3d_2d_sa(int s3mz , int s3mzarr[2][5][3] , int s2mzarr[5][3]){
    int i,j;
    
    for (i = 0; i<=4; i++){
        
        for (j = 0; j<=2; j++){
            s2mzarr[i][j] = s3mzarr[s3mz][i][j];
}}}


void  s3d_2d_ma(int s3z, int s3zarr[2][10][10], int s2arr[10][10]){//3d into 2d
     int i,j;
    //printf("\n\n");
    for (i = 0; i<=9; i++){
        
        for (j = 0; j<=9; j++){
        s2arr[i][j] = s3zarr[s3z][i][j];      
    }
        //printf("\n");
    }
}


int vd(int vdrow , int vdcol , int vdarr[10][10]){// 1111 = okay , 77 = not okay
    if (vdarr[vdrow][vdcol] == 0){
        return 1111;
    }
    
    else if (vdarr[vdrow][vdcol] != 0){
        return 77;
    }

    }


int sp(int sprow , int spcol , int spdir , int splen , int sparr[10][10]){//1010 = okay , 444 = not okay.  sp = ship placement spdir =(0 = right, 1 = down, 2 = left, 3 = up) , splen=ship length
    //  type of ship that has splen e.g thre can be two ship if same length so this is to identify them
    int spi,spj;
    
//if situation is to validte that the ship is not going out of board
switch (spdir)
{
    // RIGHT
    case 0:
        if ((spcol + splen - 1 >= 10))
            return 444;

        for (spi = 0; spi < splen; spi++)
        {
            if (vd(sprow, spcol + spi,sparr) == 77)
                return 444;
        }

        for (spi = 0; spi < splen; spi++)
        {
            sparr[sprow][spcol + spi] =  splen ;
        }
        break;


    // DOWN
    case 1:
        if (sprow + splen - 1 >= 10)
            return 444;

        for (spi = 0; spi < splen; spi++)
        {
            if (vd(sprow + spi, spcol,sparr) == 77)
                return 444;
        }

        for (spi = 0; spi < splen; spi++)
        {
            sparr[sprow + spi][spcol] =  splen ;
        }
        break;


    // LEFT
    case 2:
        if (spcol - (splen - 1) < 0)
            return 444;

        for (spi = 0; spi < splen; spi++)
        {
            if (vd(sprow, spcol - spi,sparr) == 77)
                return 444;
        }

        for (spi = 0; spi < splen; spi++)
        {
            sparr[sprow][spcol - spi] =  splen ;
        }
        break;


    // UP
    case 3:
        if (sprow - (splen - 1) < 0)
            return 444;

        for (spi = 0; spi < splen; spi++)
        {
            if (vd(sprow - spi, spcol,sparr) == 77)
                return 444;
        }

        for (spi = 0; spi < splen; spi++)
        {
            sparr[sprow - spi][spcol] =  splen ;
        }
        break;


    default:
        return 444;
}

return 1010;

}


void spir(int spiarr[10][10]){//array of ship print
    int i,j;
    printf("\n\n");
    for (i = 0; i<=9; i++){
        
        for (j = 0; j<=9; j++){
            printf("%d\t",spiarr[i][j]);
    }
        printf("\n");
    }}


void user_da(int uarr[10][10], int usae[5][3]){
    int urows, ucols;
    int dir_s;//direction of submarine  
    int dir_sps;
    printf("\nEnter the Cordinate of Submarine LEn 5");
    
    do{
    
    getcord(&urows,&ucols);
    dir_s = getdir();
    dir_sps = sp(urows,ucols,dir_s,5,uarr);
    
    if (dir_sps == 444){
        printf("\nEror");
    }
    }while(dir_sps == 444);
    spir(uarr);

    int urowac, ucolac;
    int dir_ac;//direction of aircraft carrier
    int dir_spac;
    printf("\nEnter The cordinates OF Aircraft Craierr Len 4 : ");
    
    do{
    
        getcord(&urowac,&ucolac);
    dir_ac = getdir();
    dir_spac = sp(urowac,ucolac,dir_ac,4,uarr);
    
    if (dir_spac == 444){
        printf("\nEror");
    }
    }while(dir_spac == 444);
    spir(uarr);

    int urowd, ucold;
    int dir_d;//direction of destroyer
    int dir_spd;
    printf("\nEnter The cordinates OF Destoryer Len 3 : ");
    
    do{
    
        getcord(&urowd,&ucold);
    dir_d = getdir();
    dir_spd = sp(urowd,ucold,dir_d,3,uarr);
    
    if (dir_spd == 444){
        printf("\nEror...\n");
    }
    }while(dir_spd == 444);
    
    spir(uarr);

    int urowf, ucolf;
    int dir_f;//direction of frigates
    int dir_spf;
    printf("\nEnter The cordinates OF Frigates Len 2 : ");
    
    do{
    
        getcord(&urowf,&ucolf);
    dir_f = getdir();
    dir_spf = sp(urowf,ucolf,dir_f,2,uarr);
    
    if (dir_spf == 444){
        printf("\nEror");
    }
    }while(dir_spf == 444);
    spir(uarr);



    sae(usae);
    //int usae[5];
    usae[0][2] = dir_s;
    usae[1][2] = dir_ac;
    usae[2][2] = dir_d;
    usae[3][2] = dir_f;

}


int dir_ai(){
    int d_ai;

    srand(get_microseconds());
    Sleep(2);
    d_ai = rand()%4;

    return d_ai;}
    

int sp_ai(int sairow, int saicol, int sadir, int sa_len, int saiarr[10][10])
{
     int spi,spj;
    
//if situation is to validte that the ship is not going out of board
switch (sadir)
{
    // RIGHT
    case 0:
        if ((saicol + sa_len - 1 >= 10))
            return 444;

        for (spi = 0; spi < sa_len; spi++)
        {
            if (vd(sairow, saicol + spi,saiarr) == 77)
                return 444;
        }

        for (spi = 0; spi < sa_len; spi++)
        {
            saiarr[sairow][saicol + spi] =  sa_len ;
        }
        break;


    // DOWN
    case 1:
        if (sairow + sa_len - 1 >= 10)
            return 444;

        for (spi = 0; spi < sa_len; spi++)
        {
            if (vd(sairow + spi, saicol,saiarr) == 77)
                return 444;
        }

        for (spi = 0; spi < sa_len; spi++)
        {
            saiarr[sairow + spi][saicol] =  sa_len ;
        }
        break;


    // LEFT
    case 2:
        if (saicol - (sa_len - 1) < 0)
            return 444;

        for (spi = 0; spi < sa_len; spi++)
        {
            if (vd(sairow, saicol - spi,saiarr) == 77)
                return 444;
        }

        for (spi = 0; spi < sa_len; spi++)
        {
            saiarr[sairow][saicol - spi] =  sa_len ;
        }
        break;


    // UP
    case 3:
        if (sairow - (sa_len - 1) < 0)
            return 444;

        for (spi = 0; spi < sa_len; spi++)
        {
            if (vd(sairow - spi, saicol,saiarr) == 77)
                return 444;
        }

        for (spi = 0; spi < sa_len; spi++)
        {
            saiarr[sairow - spi][saicol] =  sa_len ;
        }
        break;


    default:
        return 444;
}

return 1010;
}


void ai_da(int spafarr[10][10] , int aisae[5][3]){//all ship
// name before = sp_ai = ship placement ai final

    // len 5 = submarine
    int sp_afsrow, sp_afscol, sp_aifsdir, sp_afs_spai;
    
    do{
        sp_aifsdir = dir_ai();
        rc(&sp_afsrow,&sp_afscol);
        sp_afs_spai = sp_ai(sp_afsrow, sp_afscol, sp_aifsdir, 5, spafarr);
    }while(sp_afs_spai == 444);



// len 4  = aircraft carier
    int sp_afarow, sp_afacol, sp_afadir, sp_afa_spai;
    
    do{
        sp_afadir = dir_ai();
        rc(&sp_afarow,&sp_afacol);
        sp_afa_spai = sp_ai(sp_afarow, sp_afacol, sp_afadir , 4, spafarr);
    }while(sp_afa_spai == 444);



// len 3 = destroyer
    int sp_afdrow, sp_afdcol, sp_afddir, sp_afd_spai;
    
    do{
        sp_afddir = dir_ai();
        rc(&sp_afdrow,&sp_afdcol);
        sp_afd_spai = sp_ai(sp_afdrow, sp_afdcol, sp_afddir , 3, spafarr);
    }while(sp_afd_spai == 444 );



// len 2 = frigates
    int sp_affrow, sp_affcol, sp_affdir, sa_aff_spai;
    
    do{
    sp_affdir = dir_ai();
    rc(&sp_affrow,&sp_affcol);
    sa_aff_spai = sp_ai(sp_affrow, sp_affcol, sp_affdir , 2, spafarr);
    }while(sa_aff_spai == 444);

    sae(aisae);
    //int aisae[5];
    aisae[0][2] = sp_aifsdir;
    aisae[1][2] = sp_afadir;
    aisae[2][2] = sp_afddir;
    aisae[3][2] = sp_affdir;


}



void s2d_3d_sa(int s2mz , int s3mzarr[2][5][3] , int s2mzarr[5][3]){
    int i,j;
    
    for (i = 0; i<=4; i++){
        
        for (j = 0; j<=2; j++){
            s3mzarr[s2mz][i][j] = s2mzarr[i][j];
}}}


void  s2d_3d_ma(int s2z, int s3zarr[2][10][10], int s2arr[10][10]){//3d into 2d
     int i,j;
    //printf("\n\n");
    for (i = 0; i<=9; i++){
        
        for (j = 0; j<=9; j++){
        s3zarr[s2z][i][j] = s2arr[i][j];      
    }
        //printf("\n");
    }
}





int main(){
    
    int arr3[2][10][10];
    int arr2_red[10][10];
    int arr2_blu[10][10];
    int sar[2][5][3];
    int sar_red[5][3];
    int sar_blu[5][3];


    board(arr3);

    s3d_2d_ma(1,arr3,arr2_blu);//retreving blu from 3d
    s3d_2d_sa(1,sar,sar_blu);
    ai_da(arr2_blu,sar_blu);//to fill blu array of ships
    printf("\n\n\n AI \n\n\n");
    spir(arr2_blu);

    s3d_2d_ma(0,arr3,arr2_red);
    s3d_2d_sa(0,sar,sar_red);
    user_da(arr2_red,sar_red); 
    printf("\n\n\n User \n\n\n");  
    spir(arr2_red);

    //stiching back 

    s2d_3d_ma(0,arr3,arr2_red);
    s2d_3d_ma(1,arr3,arr2_blu);

    s3d_2d_sa(0,sar,sar_red);
    s3d_2d_sa(1,sar,sar_blu);

    return 0;


}
