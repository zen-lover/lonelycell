//
//  map.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/25/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef map_h
#define map_h


//    read map


    void map(void){
        
        FILE *p;
        unsigned int n;
        
        p=fopen("/Users/mohammadmahdi/Documents/finalProject/lonleyCell/lonleyCell/map.bin", "rb");
        
        if (p==NULL) {
            printf("error");
        }
        
        fread(&n, sizeof(unsigned int), 1, p);
    //    printf("%d",n);
        
        unsigned char arr[n][n];
        
        fread(arr, sizeof(unsigned char), n*n , p);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                printf("%c",arr[i][j]);
            }
        }
        
        fclose(p);
    }


    
//    enum


    enum blocks { ENERGY = 1, MITOSIS, FORBIDDEN, NORMAL};




//    map editor


//    void map_editor(void){
//
//    }

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
