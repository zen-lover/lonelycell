//
//  file.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/28/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef file_h
#define file_h

//#include "map.h"
//#include "menu.h"
//#include "mainmenu.h"
#include "mapStruct.h"

void single_status(struct cells * );
void multi_status(struct cells * );
void map_status(struct maps * ,int,int);

void single_status(struct cells * player){
    
    FILE * status_player;
    status_player=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/status_single.txt","w+");

    if (status_player==NULL) {
        printf("error");
    }
    struct cells_el *p=player->head;
    for (int i=1; i<=player->length; i++) {
        fprintf(status_player, "%d)\t",player->head->cell->number);
        fprintf(status_player, "%s\t",player->head->cell->name);
        fprintf(status_player, "(%d,%d)\t",player->head->cell->x,player->head->cell->y);
        fprintf(status_player, "energy:%d\n",player->head->cell->energy);
        player->head=player->head->next;
    }
    player->head=p;
    fclose(status_player);
}

void multi_status(struct cells * player){
    
    FILE * status_player;
    status_player=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/status_multi.txt","w+");

    if (status_player==NULL) {
        printf("error");
    }
    struct cells_el *p=player->head;
    for (int i=1; i<=player->length; i++) {
        fprintf(status_player, "%d)\t",player->head->cell->number);
        fprintf(status_player, "%s\t",player->head->cell->name);
        fprintf(status_player, "(%d,%d)\t",player->head->cell->x,player->head->cell->y);
        fprintf(status_player, "energy:%d\n",player->head->cell->energy);
        player->head=player->head->next;
    }
    player->head=p;
    fclose(status_player);
}

void map_status(struct maps * game_map,int num_player,int turn){
    
    FILE * status_map;
    status_map=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/status_map.txt","w+");

    if (status_map==NULL) {
        printf("error");
    }

    fprintf(status_map, "number of player : %d\n",num_player);
    fprintf(status_map, "turn : %d\n",turn);
    
    
    fprintf(status_map, "\nindex\t");
    fprintf(status_map, "name:\t\t");
    fprintf(status_map, "flag:\t");
    fprintf(status_map, "coordinate:\t");
    fprintf(status_map, "energy of map:\t  ");
    fprintf(status_map, "kind:\t   ");
    fprintf(status_map, "energy of cell:\n\n");
//    ftell(status_map);
    
    struct maps_el *p=game_map->head;
    for (int i=1; i<=game_map->length; i++) {
        fprintf(status_map, "%d)\t",i);
        fprintf(status_map, "%-18s",game_map->head->map->name);
        fprintf(status_map, "%-8d",game_map->head->map->flag);
        fprintf(status_map, "(%d,%d)\t\t\t",game_map->head->map->x,game_map->head->map->y);
        fprintf(status_map, "%-12d",game_map->head->map->energy_m);
        fprintf(status_map, "%-15c",game_map->head->map->kind);
        fprintf(status_map, "%d\n",game_map->head->map->energy_c);
        
        game_map->head=game_map->head->next;
    }
    game_map->head=p;
    fclose(status_map);
}





#endif /* file_h */
