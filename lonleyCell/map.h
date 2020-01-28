//
//  map.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/25/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef map_h
#define map_h

#include "cellSingle.h"
#include <stdlib.h>
#include <time.h>

unsigned int n;

//    enum


enum blocks { ENERGY = 1, MITOSIS, FORBIDDEN, NORMAL};

void map(void);
void map_read(FILE *p);
void map_write(void);
void map_editor(void);
void map_creator(void);
void initial_coordinate(struct cell *);





void map(){
    
    FILE *p;
    p=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/map.bin", "rb");
    
    if (p==NULL) {
        printf("error");
    }
    
    map_read(p);
}







//    read map


    void map_read(FILE *p){
        
        
        fread(&n, sizeof(unsigned int), 1, p);
//        printf("%d",n);
        
        
        unsigned char arr[n][n];
        fread(arr, sizeof(unsigned char), n*n , p);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                printf("%c",arr[i][j]);
            }
        }
        printf("\n");
        
        fclose(p);
    }









    
//    random


void initial_coordinate(struct cell *cel){



    cel->x=rand()%n;
    cel->y=rand()%n;

//    if (arr[cel->x][cel->y]!= FORBIDDEN ) {
//        initial_coordinate(cel);
//    }

}










//    map editor


void map_editor(){
    
    
    printf("do you want create a new map?\n");
    printf("y or n?\n");
    char answer='n';
    scanf("%c",&answer);
    getchar();
    
    if (answer == 'y') {
        printf("yes\n");
        map_creator();
    }
    
    
    else if (answer == 'n'){
        printf("no\n");
        map();
    }
    
    
    else{
        printf("answer y or n?");
        map_editor();
    }
    
}











void map_creator(){
    printf("enter length of map\n");
    scanf("%d",&n);
    
    map_write();
    
}











void map_write(void){
    
    FILE *p;
    p=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/map_write.bin", "wb+");
    
    if (p==NULL) {
        printf("error");
    }
    
    fwrite(&n, sizeof(unsigned int), 1, p);
    
    unsigned char arr[n][n];
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("enter kind of (%d,%d):\n",i,j);
            scanf("%c",&arr[i][j]);
            getchar();
        }
    }
    
    fwrite(arr, sizeof(unsigned char), n*n , p);
    
//    fclose(p);
    
    map_read(p);
    
}

    

#endif /* map_h */


/*
 
 
 
 
 
 
 
 
     ___       ___
    /   \     /   \
   /     \___/     \___
   \     /   \     /   \
    \___/     \___/     \
    /   \     /   \     /
   /     \___/     \___/
   \     /   \     /   \
    \___/     \___/     \
    /   \     /   \     /
   /     \___/     \___/
   \     /   \     /   \
    \___/     \___/     \
    /   \     /   \     /
   /     \___/     \___/
   \     /   \     /   \
    \___/     \___/     \
        \     /   \     /
         \___/     \___/
 
 
 
 
 
 
 
        _____           _____
       /     \         /     \
      /       \       /       \
     /         \_____/         \_____
     \         /     \         /     \
      \       /       \       /       \
       \_____/         \_____/         \
       /     \         /     \         /
      /       \       /       \       /
     /         \_____/         \_____/
     \         /     \         /     \
      \       /       \       /       \
       \_____/         \_____/         \
       /     \         /     \         /
      /       \       /       \       /
     /         \_____/         \_____/
     \         /     \         /     \
      \       /       \       /       \
       \_____/         \_____/         \
       /     \         /     \         /
      /       \       /       \       /
     /         \_____/         \_____/
     \         /     \         /     \
      \       /       \       /       \
       \_____/         \_____/         \
             \         /     \         /
              \       /       \       /
               \_____/         \_____/

 
 
*/
