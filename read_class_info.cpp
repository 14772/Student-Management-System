//
// Created by 14772 on 2021/11/22.
//
#include "Student_Performance_Management_System.h"
ClassInfo read_class_info()
{
    ClassInfo classInfo;
    char s[100];
    InputBox(s,100,"请输入课程ID\n课程名\n学分数\n学时数\n教师ID\n教师姓名",
             "课程信息",NULL,0,180);
    sscanf(s,"%s%s%d%d%s%s%s",classInfo.class_id,classInfo.class_name,
           &classInfo.credit,&classInfo.credit_hours,
           classInfo.teacher_id,classInfo.teacher_name
    );
    return classInfo;
}
