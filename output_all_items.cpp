//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
void output_all_items(GradesList *L) {
    extern int gradecnt;
    GradesList *p = L->next;
    char str[150];
    char rank[20];
    HWND wnd = GetHWnd();
    for (int i=1 ; p != NULL ; i++ ) {
        _stprintf(str,TEXT("class_id\t\t%s\n"
                           "class_name\t%s\n"
                           "teacher_id\t\t%s\n"
                           "teacher_name\t%s\n"
                           "student_id\t\t%s\n"
                           "student_name\t%s\n"
                           "grades\t\t%3.2f"),
                  p->gdata.class_id,p->gdata.class_name,p->gdata.teacher_id,
                  p->gdata.teacher_name,p->gdata.student_id,p->gdata.student_name,p->gdata.grades);
        _stprintf(rank,TEXT("%d/%d\n"),i,gradecnt);
        MessageBox(wnd, str, rank, MB_OK);
        p=p->next;
    }
}