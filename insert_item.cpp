//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
void insert_item(StudentList *L1,TeacherList *L2,AdminList *L3,ClassList *L4,GradesList *L5, struct Info item,ClassInfo citem,GradesInfo gitem,int object)
{
    StudentList *pre1,*p1,*new_node1;
    p1 = L1->next,pre1 = L1;
    TeacherList *pre2,*p2,*new_node2;
    p2 = L2->next,pre2 = L2;
    AdminList *pre3,*p3,*new_node3;
    p3 = L3->next,pre3 = L3;
    ClassList *pre4,*p4,*new_node4;
    p4 = L4->next,pre4 = L4;
    GradesList *pre5,*p5,*new_node5;
    p5 = L5->next,pre5 = L5;
    HWND wnd = GetHWnd();
    char str[30];
    switch (object) {
        case 1:
            new_node1 = (StudentList *) malloc(sizeof(StudentList ));
            new_node1->data = item;
            while (p1 != NULL) {
                pre1 = p1;
                p1 = p1->next;
            }
            pre1->next = new_node1;
            new_node1->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),item.id);
            MessageBox(wnd, str, "提示", MB_OK );
            return ;
        case 2:
            new_node2 = (TeacherList *) malloc(sizeof(TeacherList ));
            new_node2->data = item;
            while (p2 != NULL) {
                pre2 = p2;
                p2 = p2->next;
            }
            pre2->next = new_node2;
            new_node2->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),item.id);
            MessageBox(wnd, str, "提示", MB_OK );
            return ;
        case 3:
            new_node3 = (AdminList *) malloc(sizeof(AdminList ));
            new_node3->data = item;
            while (p3 != NULL) {
                pre3 = p3;
                p3 = p3->next;
            }
            pre3->next = new_node3;
            new_node3->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),item.id);
            MessageBox(wnd, str, "提示", MB_OK );
            return ;
        case 4:
            new_node4 = (ClassList *) malloc(sizeof(ClassList ));
            new_node4->cdata=citem;
            while (p4 != NULL) {
                pre4 = p4;
                p4 = p4->next;
            }
            pre4->next = new_node4;
            new_node4->next = NULL;
            _stprintf(str,TEXT("添加%s成功"),citem.class_id);
            MessageBox(wnd, str, "提示", MB_OK );
            return;
        case 5:
            new_node5 = (GradesList *) malloc(sizeof(GradesList ));
            new_node5->gdata=gitem;
            while (p5 != NULL) {
                pre5 = p5;
                p5 = p5->next;
            }
            pre5->next = new_node5;
            new_node5->next = NULL;
            _stprintf(str,TEXT("添加%s-%s成功"),gitem.student_id,gitem.class_id);
            MessageBox(wnd, str, "提示", MB_OK );
            return;
    }
}
