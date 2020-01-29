//
//  cellSingle.h
//  lonleyCell
//
//  Created by mohammad mahdi on 1/26/20.
//  Copyright © 2020 mohammad mahdi. All rights reserved.
//

#ifndef cellSingle_h
#define cellSingle_h

struct cell {
    char name[256];
    int x;
    int y;
    int energy;
    int flag;
    int number;
    
};

struct cells {
    int length;
    struct cells_el *head;
};

struct cells_el {
    struct cell *cell;
    struct cells_el *next;
};



struct cells *cells_new(void) {
  struct cells *clls = malloc(sizeof(struct cells));
  clls->length = 0;
  clls->head = NULL;

  return clls;
}






void cells_push_back(struct cells *cells, struct cell *cell) {
  struct cells_el *el = malloc(sizeof(struct cells_el));
  el->next = NULL;
  el->cell = cell;

  cells->length++;

  if (cells->head == NULL) {
    cells->head = el;
  } else {
    struct cells_el *p = cells->head;

    while (p->next != NULL) {
      p = p->next;
    }

    p->next = el;
  }
}





void cells_remove(struct cells *cells, int index) {
  struct cells_el *el = cells->head;

  if (index == 0) {
    cells->head = el->next;
    free(el->cell);
    free(el);
  } else {
    int i = 0;
    while (el && i + 1 < index) {
      el = el->next;
      i++;
    }
    if (i + 1 == index) {
      struct cells_el *p = el->next->next;
      free(el->next->cell);
      free(el->next);
      el->next = p;
    }
  }
}





int cells_search_name(struct cells *cells, const char *name) {
  int index = -1;
  int i = 1;

  struct cells_el *p = cells->head;
  while (p) {
    if (strcmp(p->cell->name, name) == 0) {
      index = i;
      break;
    }
    i++;
    p = p->next;
  }

  return index;
}

#endif /* cellSingle_h */
