//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
bool delete_item(List *L, char *id,int object)
{
    extern int gradecnt;
    List *p,*pre;
    p=L->next,pre=L;
    switch (object) {
        case 1:
        case 2:
        case 3:
            while ((p != NULL && (strcmp(p->data.id, id)))) {
                pre = p;
                p = p->next;
            }
            if (p == NULL)
                return false;
            pre->next = p->next;
            free(p);
            return true;
        case 4:
            while ((p != NULL && (strcmp(p->cdata.class_id, id)))) {
                pre = p;
                p = p->next;
            }
            if (p == NULL)
                return false;
            pre->next = p->next;
            free(p);
            return true;
        case 5:
            while ((p != NULL && (strcmp(p->gdata.student_id, id)))) {
                pre = p;
                p = p->next;
            }
            if (p == NULL)
                return false;
            pre->next = p->next;
            free(p);
            gradecnt--;
            return true;
    }
}
