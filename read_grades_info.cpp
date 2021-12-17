//
// Created by 14772 on 2021/11/22.
//
#include "Student_Performance_Management_System.h"
GradesInfo read_grades_info()
{
    GradesInfo gradesInfo;
    gradesInfo.grades=-1;
    char s[100];
    InputBox(s,100,"请输入课程ID\n课程名\n教师ID\n教师姓名\n学生ID\n学生姓名\n成绩",
             "成绩信息",NULL,0,180);
    sscanf(s,"%s%s%d%d%s%s%f",gradesInfo.class_id,gradesInfo.class_name,
           gradesInfo.teacher_id,gradesInfo.teacher_name,
           gradesInfo.student_id,gradesInfo.student_name,&gradesInfo.grades
    );
    return gradesInfo;
}
