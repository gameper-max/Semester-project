#include<stdio.h>//2 3 3 4 5
int arr[2][10][10];
/*
int sad_2(int sad[3][5]){ // SAeed
    sad[0][0] = 50;sad[0][1] = 5; 
    //submarine
    sad[1][0] = 40;sad[1][1] = 4;
    //aircraft carrier
    sad[2][0] = 30;sad[2][1] = 3;
    //destroyer 1
    sad[3][0] = 31;sad[3][1] = 3;
    //destroyer 2
    sad[4][0] = 20;sad[4][1] = 2;
    //frigates

    int i,j;
    printf("\n\n");
    for (i = 0; i<5; i++){
        
        for (j = 0; j<2; j++){
            printf("%d\t",sad[i][j]);
    }
        printf("\n");
    }}
*/


int sae(int sat , int s_no , int saliv, int sadir, int saarr2[2][5][3]){
    //sat = 0 = red, sa = 1 blue 
    saarr2[sat][s_no][0] = saliv;
    saarr2[sat][s_no][1] = sadir;
}


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


void s3d_2d(int s3z, int s3zarr[2][10][10], int s2arr[10][10]){//3d into 2d
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




int sp(int sprow , int spcol , int spdir , int splen , int sptype , int sparr[10][10]){//1010 = okay , 444 = not okay.  sp = ship placement spdir =(0 = right, 1 = down, 2 = left, 3 = up) , splen=ship length
    //sptype type of ship that has splen e.g thre can be two ship if same length so this is to identify them
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
            sparr[sprow][spcol + spi] = (splen*10)+sptype;
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
            sparr[sprow + spi][spcol] = (splen*10)+sptype;
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
            sparr[sprow][spcol - spi] = (splen*10)+sptype;
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
            sparr[sprow - spi][spcol] = (splen*10)+sptype;
        }
        break;


    default:
        return 444;
}

return 1010;

}


void ms(int msrow , int mscol ,int msarr[10][10]){//hit miss , hit ship
    if (msarr[msrow][mscol]==0){
    msarr[msrow][mscol]= -1;}

    else if ((msarr[msrow][mscol]!=0) ||(msarr[msrow][mscol]!=-1) ){
    msarr[msrow][mscol]= (99*10) + msarr[msrow][mscol];}

    
}


void spir(int spirow , int spicol , int spiarr[spirow][spicol]){//array of ship print
    int i,j;
    printf("\n\n");
    for (i = 0; i<=9; i++){
        
        for (j = 0; j<=9; j++){
            printf("%d\t",spiarr[i][j]);
    }
        printf("\n");
    }}



void s2d_3d(int s2z, int s3zarr[2][10][10], int s2arr[10][10]){//3d into 2d
     int i,j;
    //printf("\n\n");
    for (i = 0; i<=9; i++){
        
        for (j = 0; j<=9; j++){
        s3zarr[s2z][i][j] = s2arr[i][j];      
    }
        //printf("\n");
    }
}

    /*
//destroyer submarine 
//{//moiz
int moiz_s(int msrow, int mscol, int ms_dir , int msarr[msrow][mscol]){//submarine
    sp(msrow,mscol,ms_dir,5,0,msarr);
}


int moiz_a(int marow, int macol, int ma_dir , int maarr[marow][macol]){//aircraft crariier
    sp(marow,macol,ma_dir,4,0,maarr);
}


int moiz_d(int mdrow, int mdcol, int md_dir , int mdarr[mdrow][mdcol]){//destroyer 1st type
    sp(mdrow,mdcol,md_dir,3,0,mdarr);
}

//int moiz_d2(int md2row, int md2col, int md2_dir , int md2arr[md2row][md2col]){//destroyer 2nd type
//    sp(md2row,md2col,md2_dir,3,1,md2arr);
//}

int moiz_f(int mfrow, int mfcol, int mf_dir , int mfarr[mfrow][mfcol]){//Frigates
    sp(mfrow,mfcol,mf_dir,2,0,mfarr);
}
//}*/



int main(){
    int arr3[2][10][10];//3D array
    board(arr3);
    int arr2red[10][10];//z = 0
    int arr2blu[10][10];//z = 1
    s3d_2d(0,arr3,arr2red);
    s3d_2d(1,arr3,arr2blu);
    //here moiz function so that sp is called 



return 0;

}
