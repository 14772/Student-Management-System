//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
struct List *search_item(List *p, char *id,int object) {
    switch (object) {
        case 1:
        case 2:
        case 3:
            while ((p != NULL && (strcmp(p->data.id, id)))) {
                p = p->next;
            }
            if (p == NULL)
                return NULL;
            break;
        case 4:
            while ((p != NULL && (strcmp(p->cdata.class_id, id)))) {
                p = p->next;
            }
            if (p == NULL)
                return NULL;
            break;
        case 5:
            while ((p != NULL && (strcmp(p->gdata.student_id, id)))) {
                p = p->next;
            }
            if (p == NULL)
                return NULL;
            break;
    }
    return p;
}