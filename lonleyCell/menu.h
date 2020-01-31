//
//  menu.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/26/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdlib.h>
#include <time.h>
#include "cellSingle.h"
#include "file.h"

int num_player;
int turn;

struct cells *first_player[2];

void Load(void);
void Single(void/*struct map **/);
void Multi(void);
void Exit(void);
void menu_1(void);
void choose_1(void);
void choose_2(void);
void main_menu(struct cells_el *);
//struct cells * return_player(void);



void Move(struct cells_el *);
void Split(struct cells_el *);
void Boost(struct cells_el *);
void Save(void);
void Esc(void);
int check_move(struct cells_el * , int , int);


//struct cells *return_player(void){
//    return first_player;
//}



unsigned int n;
struct maps *game_map ;
int x;

//    enum

enum blocks { ENERGY = 1, MITOSIS, FORBIDDEN, NORMAL};


//    fynction

void map(void);
void map_read(FILE *p);
void map_write(void);
void map_editor(void);
void map_creator(void);
void show_map(void);
void initial_coordinate(struct cell */*,struct map **/);
struct maps_el * find_map(int x,int y);



void Load(void){
    printf("Load\n");
    
    FILE * status_map;
    status_map=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/status_map.txt","r+");

    if (status_map==NULL) {
        printf("error");
    }
    
    game_map = maps_new();
    
    long int hasan;
    int ali = 0;
    char mmd[256];
    char khar;
    int ff=0;
    int ss=0;
    fscanf(status_map, "number of player : %d\t\n",&num_player );
    printf("\n%d",num_player);
    fscanf(status_map, "turn : %d\n",&turn );
    printf("\n%d",turn);
    fscanf(status_map, "length of map : %d\n\n",&n);
    printf("\n%d",n);
    
    fgets(mmd, 100, status_map);
    printf("%s",mmd);
    hasan=ftell(status_map);
    printf("\nhasan%ld\n",hasan);
    
    
    for (int j=0; j<n*n; j++) {
        struct map *mmm= malloc(sizeof(struct map));
//        index
        fscanf(status_map, "%d",&ali);
        printf("%d\n",ali);
        fseek(status_map, 2, SEEK_CUR);
        
//        name
        fgets(mmd, 18, status_map);
        puts(mmd);
        strcpy(mmm->name, mmd);
        
//        flag
        
        fscanf(status_map, "%d",&ali);
        mmm->flag=ali;
        printf("%d\n",ali);
        fseek(status_map, 8, SEEK_CUR);
        
        
//        x,y
        fscanf(status_map, "%d",&ali);
        printf("%d\n",ali);
        mmm->x=ali;
        fseek(status_map, 1, SEEK_CUR);
        fscanf(status_map, "%d",&ali);
        printf("%d\n",ali);
        mmm->y=ali;
        fseek(status_map, 4, SEEK_CUR);
        
//        energy map
        
        fscanf(status_map, "%d",&ali);
        printf("%d\n",ali);
        mmm->energy_m=ali;
        fseek(status_map, 9, SEEK_CUR);
        
//        kind
        
        if (ali<10) {
            fseek(status_map, 2, SEEK_CUR);
        }else if (ali<100){
            fseek(status_map, 1, SEEK_CUR);
        }
        khar=fgetc(status_map);
        printf("%c\n",khar);
        mmm->kind=khar;
        fseek(status_map, 14, SEEK_CUR);
        
//        energy cell
        
        fscanf(status_map, "%d",&ali);
        printf("%d\n",ali);
        mmm->energy_c=ali;
        fseek(status_map, 1, SEEK_CUR);
        
        
        if (mmm->flag==1) {
            
            first_player[0] = cells_new();
            ff++;
                struct cell *cel= malloc(sizeof(struct cell));
                cel->number=ff;
                strcpy(cel->name,mmm->name);
                cel->flag=mmm->flag;
                cel->energy=mmm->energy_c;
                cel->x=mmm->x;
                cel->y=mmm->y;
                
                cells_push_back(first_player[0], cel);
            
            single_status(first_player[0]);
            
            
        }else if(mmm->flag==2){
            first_player[1] = cells_new();
            ss++;
                struct cell *cel= malloc(sizeof(struct cell));
                cel->number=ss;
                strcpy(cel->name,mmm->name);
                cel->flag=mmm->flag;
                cel->energy=mmm->energy_c;
                cel->x=mmm->x;
                cel->y=mmm->y;
                
                cells_push_back(first_player[1], cel);
            
            multi_status(first_player[1]);
        }
        
        
        
        
        maps_push_back(game_map, mmm);
    }
    
    map_status(game_map, num_player, turn, n);
    fclose(status_map);
    
    
    
    getchar();
    if (turn==0) {
        choose_1();
    }else if (turn==1){
        choose_2();
    }
    
}



void Single(/*struct map * block*/){
    
    num_player =1;
    printf("first person :\n");
    first_player[0] = cells_new();
    printf("enter number of your cell:\n");
    int number_cell;
    scanf("%d",&number_cell);
    getchar();
    for (int i=1; i<=number_cell; i++) {
        printf("what is name of your %dth cell?\n",i);
        struct cell *cel= malloc(sizeof(struct cell));
        cel->number=i;
        gets(cel->name);
        cel->flag=1;
        cel->energy=0;
        
        
        initial_coordinate(cel);
        
        cells_push_back(first_player[0], cel);
    }
    single_status(first_player[0]);
    
    
    
}
void Multi(void){
    
    printf("Multi\n");
    printf("1) 2th person\n");
    printf("2) pc\n");
    
    Single();
    num_player=2;
    printf("second player :\n");
    first_player[1] = cells_new();
    printf("enter number of your cell:\n");
    int number_cell;
    scanf("%d",&number_cell);
    getchar();
    for (int i=1; i<=number_cell; i++) {
        printf("what is name of your %dth cell?\n",i);
        struct cell *cel= malloc(sizeof(struct cell));
        cel->number=i;
        gets(cel->name);
        cel->flag=2;
        cel->energy=0;
        
        
        initial_coordinate(cel);
        
        cells_push_back(first_player[1], cel);
    }
    multi_status(first_player[1]);
    
}


//  menu 1

void menu_1 (){
    
    printf("\nmenu\n\n");
    printf("1) Load\n");
    printf("2) New single player game\n");
    printf("3) New Multiplayer game\n");
    printf("4) Exit\n");

    int choose;
    scanf("%d", &choose);
    getchar();

    switch (choose)
    {
        case 1 :
            Load();
            break;
        case 2 :
            map_editor();
            Single();
            break;
        case 3 :
            map_editor();
            Multi();
            break;
        case 4 :
            Exit();
            break;
        default :
            printf("please enter valid choice\n");
            menu_1();
            break;
    }

}


void choose_1(){
    
    show_map();
    printf("\n\nhey player number 1 is your turn\n");
    printf("choose a cell!!!\n");
    
    struct cells_el *p=first_player[0]->head;
    for (int i=1; i<=first_player[0]->length; i++) {
        printf("%d)\t",first_player[0]->head->cell->number);
        printf("%-7s\t",first_player[0]->head->cell->name);
        printf("(%d,%d)\t",first_player[0]->head->cell->x,first_player[0]->head->cell->y);
        printf("energy:%d\n",first_player[0]->head->cell->energy);
        first_player[0]->head=first_player[0]->head->next;
    }
    first_player[0]->head=p;
    
    char answer[100];
    gets(answer);
    
    struct cells_el *choosen_cell;
    
    
    int num=cells_search_name(first_player[0], answer);
//    printf("%d",num);
    
    choosen_cell=first_player[0]->head;
    for (int i=0; i<num; i++) {
        choosen_cell=first_player[0]->head;
        first_player[0]->head=first_player[0]->head->next;
    }
    
    first_player[0]->head=p;
    
//    printf("%d",choosen_cell->cell->x);
    if (num_player==2) {
        turn=1;
    }
    main_menu(choosen_cell);
    
//    first_player->head=p;
}


void choose_2(){
    
    show_map();
    
    printf("\n\nhey player number 2 is your turn\n");
    printf("choose a cell!!!\n");
    
    struct cells_el *p=first_player[1]->head;
    for (int i=1; i<=first_player[1]->length; i++) {
        printf("%d)\t",first_player[1]->head->cell->number);
        printf("%-7s\t",first_player[1]->head->cell->name);
        printf("(%d,%d)\t",first_player[1]->head->cell->x,first_player[1]->head->cell->y);
        printf("energy:%d\n",first_player[1]->head->cell->energy);
        first_player[1]->head=first_player[1]->head->next;
    }
    first_player[1]->head=p;
    
    char answer[100];
    gets(answer);
    
    struct cells_el *choosen_cell;
    
    
    int num=cells_search_name(first_player[1], answer);
//    printf("%d",num);
    
    choosen_cell=first_player[1]->head;
    for (int i=0; i<num; i++) {
        choosen_cell=first_player[1]->head;
        first_player[1]->head=first_player[1]->head->next;
    }
    
    first_player[1]->head=p;
    
//    printf("%d",choosen_cell->cell->x);
    turn=0;
    main_menu(choosen_cell);
//    choose_1();
    
//    first_player->head=p;
}

void main_menu(struct cells_el *choosen_cell){
    printf("\nmain menu:\n");
    printf("1) Move\n");
    printf("2) Split a cell\n");
    printf("3) Boost energy\n");
    printf("4) Save\n");
    printf("5) Exit\n");
    
    int answer;
    scanf("%d",&answer);
    getchar();
    
    switch (answer) {
        case 1:
            Move(choosen_cell);
            if (turn==0) {
                choose_1();
            }
            if (turn==1) {
                choose_2();
            }
            
            break;
        case 2:
            Split(choosen_cell);
            if (turn==0) {
                choose_1();
            }
            if (turn==1) {
                choose_2();
            }
            break;
        case 3:
            Boost(choosen_cell);
            if (turn==0) {
                choose_1();
            }
            if (turn==1) {
                choose_2();
            }
            break;
        case 4:
            Save();
            if (turn==0) {
                choose_1();
            }
            if (turn==1) {
                choose_2();
            }
            break;
        case 5:
            Exit();
            break;
        default:
            printf("write valid number!!!\n");
            main_menu(choosen_cell);
            break;
    }
}




void Move(struct cells_el *choosen_cell){
    printf("1) North\n");
    printf("2) South\n");
    printf("3) Northeast\n");
    printf("4) Northwest\n");
    printf("5) Southeast\n");
    printf("6) Southwest\n");
    
    int answer;
    scanf("%d",&answer);
    getchar();
    
    int tool=0;
    int arz=0;
    
    switch (answer) {
        case 1:
            tool=0;
            arz=1;
            printf("\n1(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            check_move(choosen_cell, tool, arz);
            printf("\n2(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            break;
        case 2:
            tool=0;
            arz=-1;
            printf("\n1(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            check_move(choosen_cell, tool, arz);
            printf("\n2(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            break;
        case 3:
            if (choosen_cell->cell->x % 2 == 0) {
                tool=1;
                arz=1;
            }else{
                tool=1;
                arz=0;
            }
            printf("\n1(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            check_move(choosen_cell, tool, arz);
            printf("\n2(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            break;
        case 4:
            if (choosen_cell->cell->x % 2 == 0) {
                tool=-1;
                arz=1;
            }else{
                tool=-1;
                arz=0;
            }
            printf("\n1(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            check_move(choosen_cell, tool, arz);
            printf("\n2(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            break;
        case 5:
            if (choosen_cell->cell->x % 2 == 0) {
                tool=1;
                arz=0;
            }else{
                tool=1;
                arz=-1;
            }
            printf("\n1(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            check_move(choosen_cell, tool, arz);
            printf("\n2(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            break;
        case 6:
            if (choosen_cell->cell->x % 2 == 0) {
                tool=-1;
                arz=0;
            }else{
                tool=-1;
                arz=-1;
            }
            printf("\n1(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            check_move(choosen_cell, tool, arz);
            printf("\n2(%d,%d)\n",choosen_cell->cell->x,choosen_cell->cell->y);
            break;
        default:
            printf("write valid turn!!!\n");
            Move(choosen_cell);
            break;
    }
}


int check_move (struct cells_el *choosen_cell , int tool , int arz){
    
    
    if (!(choosen_cell->cell->x+tool >=0 && choosen_cell->cell->y+arz >=0 && choosen_cell->cell->x+tool <n && choosen_cell->cell->y+arz <n)) {
        printf("cant move\n");
        printf("out of map\n");
        return 0;
    }
    
//    struct cells_el *p=first_player->head;
//    int aa,bb;
//    aa=choosen_cell->cell->x+tool;
//    bb=choosen_cell->cell->y+arz;
    
    
//    int f=((aa*n)+bb);
//    for (int i=0; i<f; i++) {
//        printf("next\n");
//        printf("%d\n",p->cell->x);
//        printf("%d\n",p->cell->y);
//        p=p->next;
//        printf("%d\n",p->cell->x);
//        printf("%d\n",p->cell->y);
//
//    }
    
    
    
    struct maps_el *curr =game_map->head;
    struct maps_el *qqq =game_map->head;
    
    for(int i=0 ; i<(choosen_cell->cell->x+tool)*n+(choosen_cell->cell->y+arz);i++)
        {
            game_map->head=game_map->head->next;
        }
    
    for(int i=0 ; i<(choosen_cell->cell->x)*n+(choosen_cell->cell->y);i++)
    {
        qqq=qqq->next;
    }
    
    printf("x,y map\n");
    printf("(%d,%d)\n",qqq->map->x,qqq->map->y );
    printf("x,y map\n");
    printf("(%d,%d)\n",game_map->head->map->x,game_map->head->map->y );
        
        if (game_map->head->map->flag==0 && game_map->head->map->kind != '3') {
            choosen_cell->cell->x+=tool;
            choosen_cell->cell->y+=arz;
            strcpy(game_map->head->map->name,choosen_cell->cell->name);
            strcpy(qqq->map->name,"-----");
            game_map->head->map->energy_c=qqq->map->energy_c;
            game_map->head->map->flag=qqq->map->flag;
            qqq->map->flag=0;
            qqq->map->energy_c=0;
            game_map->head=curr;
            
//            for(int i=0 ; i<(choosen_cell->cell->x)*n+(choosen_cell->cell->y);i++)
//            {
//                game_map->head=game_map->head->next;
//            }
//            game_map->head->map->flag=0;
//
//            game_map->head=curr;
            
            return 1;
        }
    game_map->head=curr;
    printf("cant move\n");
    return 0;
}


void Split(struct cells_el *choosen_cell){
    
    struct maps_el *curr =game_map->head;
    for(int i=0 ; i<(choosen_cell->cell->x)*n+(choosen_cell->cell->y);i++)
    {
        game_map->head=game_map->head->next;
    }
    
    
    if (game_map->head->map->energy_c >= 80 && game_map->head->map->kind == '2') {
        printf("x,y  choosen:(%d,%d)\n",choosen_cell->cell->x , choosen_cell->cell->y);
        Move(choosen_cell);
        printf("flag:%d\n",game_map->head->map->flag);
        if (game_map->head->map->flag==0) {
            printf("what is name of your new cell?\n");
                struct cell *cel= malloc(sizeof(struct cell));
                cel->number=(first_player[0]->length)+1;
                gets(cel->name);
                cel->flag=1;
                cel->energy=40;
                
            cel->x=game_map->head->map->x;
            cel->y=game_map->head->map->y;
            
            if (cel->flag==1) {
                cells_push_back(first_player[0], cel);
            }else if (cel->flag==1){
                cells_push_back(first_player[1], cel);
            }
                
            
//            single_status(first_player);
        }
    }else{
        printf("you cant split\n");
    }
    
     game_map->head=curr;
}

void Boost(struct cells_el *choosen_cell){
        
        struct maps_el *curr =game_map->head;
        for(int i=0 ; i<(choosen_cell->cell->x)*n+(choosen_cell->cell->y);i++)
        {
            game_map->head=game_map->head->next;
        }
    
    if (game_map->head->map->energy_m >= 15 && game_map->head->map->energy_c <= 85) {
        game_map->head->map->energy_c+=15;
        game_map->head->map->energy_m-=15;
        choosen_cell->cell->energy+=15;
        printf("boos1\n");
        
    /*}else if (game_map->head->map->energy_m >= 15 && game_map->head->map->energy_c >= 85){
        int tmp;
        tmp=100-game_map->head->map->energy_m;
        game_map->head->map->energy_c=100;
        game_map->head->map->energy_m-=tmp;
        choosen_cell->cell->energy=100;
        printf("boos2\n");*/
    }else if (game_map->head->map->energy_m <= 15 && game_map->head->map->energy_c <= 85){
        game_map->head->map->energy_c+=game_map->head->map->energy_m;
        game_map->head->map->energy_m=0;
        choosen_cell->cell->energy+=game_map->head->map->energy_m;
        printf("boos3\n");
    }else if(game_map->head->map->energy_m + game_map->head->map->energy_c >= 100){
        int tmp;
        tmp=100-game_map->head->map->energy_m - game_map->head->map->energy_c;
        game_map->head->map->energy_c=100;
        game_map->head->map->energy_m=tmp;
        choosen_cell->cell->energy=100;
        printf("boos4\n");
    }
        
    printf("boos boos\n");
        game_map->head=curr;
        
}

void Save(void){
    map_status(game_map,num_player,turn,n);
    single_status(first_player[0]);
    if (num_player==2) {
        multi_status(first_player[1]);
    }
    

    printf("your data saved\n");

}

void Exit(){
    Save();
    printf("bye bye \n");
    exit(0);
}




void map(){
    
    FILE *p;
    p=fopen("/Users/mohammadmahdi/Documents/CE/c/finalProject/lonleyCell/lonleyCell/map.bin", "rb");
//    p=fopen("/Users/mohammadmahdi/Documents/Telegram/Map7_Test.bin", "rb");
    
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
        
        game_map = maps_new();
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                printf("%c",arr[i][j]);
                struct map *mmm= malloc(sizeof(struct map));
                mmm->kind=arr[i][j];
                mmm->x=i;
                mmm->y=j;
                mmm->energy_c=0;
                mmm->flag=0;
                strcpy(mmm->name, "-----");
                
                if (mmm->kind == '1') {
                    mmm->energy_m=100;
                }else{
                    mmm->energy_m=0;
                }
                maps_push_back(game_map, mmm);
            }
        }
        
        printf("\n");
        
        map_status(game_map,num_player,turn,n);
        
        fclose(p);
    }









    
//    random


void initial_coordinate(struct cell *cel/*,struct map *block*/){

    struct maps_el *p =game_map->head;
    
    int tool,arz;
    
    tool=rand()%n;
    arz=rand()%n;
    
    for(int i=0 ; i<tool*n+arz;i++)
    {
//        printf("(%d,",game_map->head->map->x);
//        printf("%d)\n",game_map->head->map->y);
        game_map->head=game_map->head->next;
        
    }
    
    if (game_map->head->map->flag==0 && game_map->head->map->kind != '3') {
        cel->x=tool;
        cel->y=arz;
//        char str[256];
        game_map->head->map->flag=cel->flag;
        strcpy(game_map->head->map->name,cel->name);
        game_map->head=p;
        
    }else{
        game_map->head=p;
        initial_coordinate(cel);
    }
    
//    map_status(game_map);
    

}



//    map editor


void map_editor(){
    
    
    printf("do you want create a new map?\n");
    printf("y or n?\n");
    char answer='n';
//    scanf("%c",&answer);
    answer=getchar();
//    getc(answer);
    
    if (answer == 'y') {
        printf("yes\n");
        map_creator();
    }
    
    
    else if (answer == 'n'){
        printf("no\n");
        map();
    }
    
    
    else{
        printf("answer y or n?\n");
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
            printf("%c",arr[i][j]);
        }
    }
    
    fwrite(arr, sizeof(unsigned char), n*n , p);
    
//    fclose(p);
    
    map_read(p);
    
}


struct maps_el * find_map(int x,int y){
    
    struct maps_el *curr =game_map->head;
    
    for(int i=0 ; i<x*n+y;i++)
        {
            curr=curr->next;
        }
    return curr;
}





void show_map(){
    
    int x = 0,y = 0;
    if (n%2==0) {
        for (int i=0; i<n/2; i++) {
            printf("   _____        ");
        }
        printf("\n");
        for (int j=0; j<n; j++) {
            
            
            for (int i=0; i<n/2; i++) {
                x=2*i;
                y=n-j-1;
                printf("  /(%d,%d)\\       ",x,y);
            }
            if (j!=0) {
                printf("  /");
            }
            
            printf("\n");
            for (int i=0; i<n/2; i++) {
                printf(" /   %c   \\      ",find_map(x, y)->map->kind);
            }
            if (j!=0) {
                printf(" /");
            }
            printf("\n");
            for (int i=0; i<(n/2); i++) {
                printf("/    %d    \\_____",find_map(x, y)->map->flag);
            }
            if (j!=0) {
                printf("/");
            }
            printf("\n");
            for (int i=0; i<n/2; i++) {
                x=2*i+1;
                y=n-j-1;
                printf("\\         /(%d,%d)",x,y);
            }
            printf("\\");
            printf("\n");
            for (int i=0; i<n/2; i++) {
                printf(" \\       /   %c  ",find_map(x, y)->map->kind);
            }
            printf(" \\");
            printf("\n");
            for (int i=0; i<n/2; i++) {
                printf("  \\_____/    %d  ",find_map(x, y)->map->flag);
            }
            printf("  \\");
            printf("\n");
            
        }
        printf("   ");
        for (int i=0; i<n/2; i++) {
            printf("     \\         /");
        }
//        printf("\\");
        printf("\n");
        printf("   ");
        for (int i=0; i<n/2; i++) {
            printf("      \\       / ");
        }
//        printf(" \\");
        printf("\n");
        printf("   ");
        for (int i=0; i<n/2; i++) {
            printf("       \\_____/  ");
        }
        
        
    }else{
         for (int i=0; i<(n+1)/2; i++) {
                    printf("   _____        ");
                }
                printf("\n");
                for (int j=0; j<n; j++) {
                    
                    
                    for (int i=0; i<(n+1)/2; i++) {
                        x=2*i;
                        y=n-j-1;
                        printf("  /(%d,%d)\\       ",x,y);
                    }
//                    printf("  /");
                    printf("\n");
                    for (int i=0; i<(n+1)/2; i++) {
                        printf(" /   %c   \\      ",find_map(x, y)->map->kind);
                    }
                    printf("\n");
                    for (int i=0; i<(n+1)/2; i++) {
                        printf("/    %d    \\",find_map(x, y)->map->flag);
                        if (i<n/2) {
                            printf("_____");
                        }
                    }
                    printf("\n");
                    for (int i=0; i<(n+1)/2; i++) {
                        printf("\\         /");
                        if (i<n/2) {
                            x=2*i+1;
                            y=n-j-1;
                            printf("(%d,%d)",x,y);
                        }
                    }
                    printf("\n");
                    for (int i=0; i<(n+1)/2; i++) {
                        printf(" \\       /");
                        if (i<n/2) {
                            printf("   %c  ",find_map(x, y)->map->kind);
                        }
                    }
                    printf("\n");
                    for (int i=0; i<(n+1)/2; i++) {
                        printf("  \\_____/    %d  ",find_map(x, y)->map->flag);
                    }
                    printf("\n");
                    
                }
                printf("   ");
                for (int i=0; i<n/2; i++) {
                    printf("     \\         /");
                }
        //        printf("\\");
                printf("\n");
                printf("   ");
                for (int i=0; i<n/2; i++) {
                    printf("      \\       / ");
                }
        //        printf(" \\");
                printf("\n");
                printf("   ");
                for (int i=0; i<n/2; i++) {
                    printf("       \\_____/  ");
                }
    }
    
    
    printf("\n\n\n");
}


#endif /* menu_h */
