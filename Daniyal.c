#include<stdio.h>

 

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


    //int usae[5];
    usae[0][2] = dir_s;
    usae[1][2] = dir_ac;
    usae[2][2] = dir_d;
    usae[3][2] = dir_f;

}



void sae(int saarr[5][3]){
    //sae arr for direction live and Unique id 
    //unique id at x axis 0 live at x axis 1 and direction at x axis 2

    for(int j = 0;j <4;j++){
        saarr[j][0] = (5-j);
        saarr[j][1] = 5-j;
    
}
    
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
    //int arr2_blu[10][10];
    int sar[2][5][3];
    int sar_red[5][3];
    int sar_blu[5][3];


    board(arr3);
    
    s3d_2d_ma(0,arr3,arr2_red);
    spir(arr2_red);
    user_da(arr2_red,sar_red);   
    int sarr[2][5][3];
        

    return 0;


}
