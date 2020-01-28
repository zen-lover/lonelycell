//
//  menu.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/26/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef menu_h
#define menu_h

int x=9;


void Load(void){
    printf("Load\n");
}
void Single(void){
    printf("Single\n");
    printf("enter number of your cell:\n");
    int number_cell;
    scanf("%d",&number_cell);
    for (int i=1; i<=number_cell; i++) {
        printf("what is name of your %dth cell?\n",i);
        char mamad[100];
        gets(mamad);
        
    }
}
void Multi(void){
    printf("Multi\n");
    printf("1) 2th person\n");
    printf("2) pc\n");
    int multiPlayer;
    scanf("%d",&multiPlayer);
    printf("enter number of your cell:\n");
}
void Exit(void){
    printf("Exit\n");
}

//  menu 1

void menu_1 (void){
    
    printf("1) Load\n");
    printf("2) New single player game\n");
    printf("3) New Multiplayer game\n");
    printf("4) Exit\n");

    int choose;
    scanf("%d", &choose);

    switch (choose)
    {
        case 1 :
            Load();
            break;
        case 2 :
            Single();
            break;
        case 3 :
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






#endif /* menu_h */
