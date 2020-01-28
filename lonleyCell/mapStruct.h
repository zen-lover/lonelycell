//
//  mapStruct.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/28/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef mapStruct_h
#define mapStruct_h

struct map {
    char name[256];
    int x;
    int y;
    int energy;
    int kind;
    
};

struct maps {
    int length;
    struct cells_el *head;
};

struct maps_el {
    struct cell *cell;
    struct cells_el *next;
};



struct maps *maps_new(void) {
  struct maps *clls = malloc(sizeof(struct maps));
  clls->length = 0;
  clls->head = NULL;

  return clls;
}

void maps_push_back(struct maps *maps, struct map *map) {
  struct maps_el *el = malloc(sizeof(struct maps_el));
  el->next = NULL;
  el->cell = cell;

  maps->length++;

  if (maps->head == NULL) {
    maps->head = el;
  } else {
    struct maps_el *p = maps->head;

    while (p->next != NULL) {
      p = p->next;
    }

    p->next = el;
  }
}



#endif /* mapStruct_h */
