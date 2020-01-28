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

void single_status(struct cells * player){
    
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


void map_status(struct maps * game_map){
    
    FILE * status_map;
    status_map=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/status_map.txt","w+");

    if (status_map==NULL) {
        printf("error");
    }

    for (int i=1; i<=game_map->length; i++) {
        fprintf(status_map, "%d)  ",i);
        fprintf(status_map, "%s\t\t",game_map->head->map->name);
        fprintf(status_map, "(%d,%d)\t\t",game_map->head->map->x,game_map->head->map->y);
        fprintf(status_map, "energy of map:%-5d\t\t",game_map->head->map->energy_m);
        fprintf(status_map, "kind:%c\t\t",game_map->head->map->kind);
        fprintf(status_map, "energy of cell:%d\n",game_map->head->map->energy_c);
        
        game_map->head=game_map->head->next;
    }
    fclose(status_map);
}





#endif /* file_h */
