//
// Created by 14772 on 2021/11/22.
//
#include "Student_Performance_Management_System.h"
GradesInfo read_grades_info()
{
    GradesInfo gradesInfo;
    gradesInfo.grades=-1;
    char s[100];
    InputBox(s,100,"������γ�ID\n�γ���\n��ʦID\n��ʦ����\nѧ��ID\nѧ������\n�ɼ�",
             "�ɼ���Ϣ",NULL,0,180);
    sscanf(s,"%s%s%d%d%s%s%f",gradesInfo.class_id,gradesInfo.class_name,
           gradesInfo.teacher_id,gradesInfo.teacher_name,
           gradesInfo.student_id,gradesInfo.student_name,&gradesInfo.grades
    );
    return gradesInfo;
}
