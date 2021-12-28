//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
void output_one_item(List *p,int object)
{
    char str[150];
    HWND wnd = GetHWnd();
    if (p == NULL) {
        MessageBox(wnd, "No information available for this ID", "Enquiry failed", MB_OK);
        return;
    }
    switch (object) {
        case 1:
            _stprintf(str,TEXT("ID\t\t%s\n"
                                            "Name\t\t%s\n"
                                            "gender\t\t%s\n"
                                            "birth_date\t\t%s\n"
                                            "college\t\t%s\n"
                                            "major\t\t%s"),
                      p->data.id,p->data.name,p->data.gender,
                      p->data.birth_date,p->data.college_name,p->data.major_name);
            MessageBox(wnd, str, "Enquiry successful", MB_OK);
            break;
        case 2:
            _stprintf(str,TEXT("ID\t\t%s\n"
                               "Name\t\t%s\n"
                               "gender\t\t%s\n"
                               "birth_date\t\t%s\n"
                               "college\t\t%s\n"
                               "major\t\t%s"),
                      p->data.id,p->data.name,p->data.gender,
                      p->data.birth_date,p->data.college_name,p->data.major_name);
            MessageBox(wnd, str, "Enquiry successful", MB_OK);
            break;
        case 3:
            _stprintf(str,TEXT("ID\t\t%s\n"
                               "Name\t\t%s\n"
                               "gender\t\t%s\n"
                               "birth_date\t\t%s\n"
                               "college\t\t%s\n"
                               "major\t\t%s"),
                      p->data.id,p->data.name,p->data.gender,
                      p->data.birth_date,p->data.college_name,p->data.major_name);
            MessageBox(wnd, str, "Enquiry successful", MB_OK);
            break;
        case 4:
            _stprintf(str,TEXT("class_id\t\t%s\n"
                               "class_name\t%s\n"
                               "credit\t\t%d\n"
                               "credit_hours\t%d\n"
                               "teacher_id\t\t%s\n"
                               "teacher_name\t%s"),
                      p->cdata.class_id,p->cdata.class_name,p->cdata.credit,
                      p->cdata.credit_hours,p->cdata.teacher_id,p->cdata.teacher_name);
            MessageBox(wnd, str, "Enquiry successful", MB_OK);
            break;
        case 5:
            _stprintf(str,TEXT("class_id\t\t%s\n"
                               "class_name\t%s\n"
                               "teacher_id\t\t%s\n"
                               "teacher_name\t%s\n"
                               "student_id\t\t%s\n"
                               "student_name\t%s\n"
                               "grades\t\t%3.2f"),
                      p->gdata.class_id,p->gdata.class_name,p->gdata.teacher_id,
                      p->gdata.teacher_name,p->gdata.student_id,p->gdata.student_name,p->gdata.grades);
            MessageBox(wnd, str, "Enquiry successful", MB_OK);
            break;
    }
}
