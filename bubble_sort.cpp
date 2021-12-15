//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
void bubble_sort(GradesList *L)
{
    extern int gradecnt;
    int i,j,n=gradecnt;
    GradesList *p=L->next;
    GradesInfo tmp;
    HWND wnd = GetHWnd();
    if (L == NULL || L->next == NULL)
    {
        MessageBox(wnd, "当前没有信息记录", "警告", MB_OK | MB_ICONWARNING);
        return;
    }
    for (i = 0; i < n - 1; i++) {
        p = L->next;
        for (j = 0; j < n - 1 - i; j++) {
            if (p->gdata.grades < p->next->gdata.grades) {
                tmp = p->gdata;
                p->gdata = p->next->gdata;
                p->next->gdata = tmp;
            }
            p = p->next;
        }
    }
}
