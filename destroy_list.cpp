//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"

void destroy(struct List *p,struct List *pre)
{
    while (p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

void destroy_list(StudentList **L1,TeacherList **L2,AdminList **L3,ClassList **L4,GradesList **L5) {
    if (L1 == NULL || *L1 == NULL)
        return;
    if (L2 == NULL || *L2 == NULL)
        return;
    if (L3 == NULL || *L3 == NULL)
        return;
    if (L4 == NULL || *L4 == NULL)
        return;
    if (L5 == NULL || *L5 == NULL)
        return;
    StudentList *pre1 = *L1, *p1 = (*L1)->next;
    TeacherList *pre2 = *L2, *p2 = (*L2)->next;
    AdminList *pre3 = *L3, *p3 = (*L3)->next;
    ClassList *pre4 = *L4, *p4 = (*L4)->next;
    GradesList *pre5 = *L5, *p5 = (*L5)->next;
    destroy(p1, pre1);
    *L1 = NULL;
    destroy(p2, pre2);
    *L2 = NULL;
    destroy(p3, pre3);
    *L3 = NULL;
    destroy(p4, pre4);
    *L4 = NULL;
    destroy(p5, pre5);
    *L5 = NULL;
}
