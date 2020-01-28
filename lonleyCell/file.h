//
//  file.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/28/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef file_h
#define file_h

#include "map.h"

void mamad(struct cells * player){
    
    FILE * status_player;
    status_player=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/status.txt","w+");

    if (status_player==NULL) {
        printf("error");
    }

    for (int i=1; i<=player->length; i++) {
        fprintf(status_player, "%d)\t",player->head->cell->number);
        fprintf(status_player, "%s\t",player->head->cell->name);
        fprintf(status_player, "(%d,%d)\t",player->head->cell->x,player->head->cell->y);
        fprintf(status_player, "energy:%d\n",player->head->cell->energy);
        player->head=player->head->next;
    }
    fclose(status_player);
}





#endif /* file_h */
