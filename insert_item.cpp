//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
void insert_item(List *L, struct Info item,ClassInfo citem,GradesInfo gitem,int object)
{
    List *pre,*p,*new_node;
    pre = L->next,pre = L;
    HWND wnd = GetHWnd();
    char str[30];
    switch (object) {
        case 1:
            new_node = (StudentList *) malloc(sizeof(StudentList ));
            new_node->data = item;
            while (p != NULL) {
                pre = p;
                p = p->next;
            }
            pre->next = new_node;
            new_node->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),item.id);
            MessageBox(wnd, str, "提示", MB_OK );
            return ;
        case 2:
            new_node = (TeacherList *) malloc(sizeof(TeacherList ));
            new_node->data = item;
            while (p != NULL) {
                pre = p;
                p = p->next;
            }
            pre->next = new_node;
            new_node->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),item.id);
            MessageBox(wnd, str, "提示", MB_OK );
            return ;
        case 3:
            new_node = (AdminList *) malloc(sizeof(AdminList ));
            new_node->data = item;
            while (p != NULL) {
                pre = p;
                p = p->next;
            }
            pre->next = new_node;
            new_node->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),item.id);
            MessageBox(wnd, str, "提示", MB_OK );
            return ;
        case 4:
            new_node = (ClassList *) malloc(sizeof(ClassList ));
            new_node->cdata=citem;
            while (p != NULL) {
                pre = p;
                p = p->next;
            }
            pre->next = new_node;
            new_node->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),citem.class_id);
            MessageBox(wnd, str, "提示", MB_OK );
            return;
        case 5:
            new_node = (GradesList *) malloc(sizeof(GradesList ));
            new_node->gdata=gitem;
            while (p != NULL) {
                pre = p;
                p = p->next;
            }
            pre->next = new_node;
            new_node->next = NULL;
            _stprintf(str,TEXT("添加%s-%s成功"),gitem.student_id,gitem.class_id);
            MessageBox(wnd, str, "提示", MB_OK );
            return;
    }
}
