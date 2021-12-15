//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
struct Info read_info(int object)
{
    StudentInfo studentInfo;
    TeacherInfo teacherInfo;
    AdminInfo adminInfo;
    char s[100];
    InputBox(s,100,"请输入用户ID\n姓名\n性别\n出生日期\n学院\n专业\n密码",
             "用户信息",NULL,0,180);
    switch(object) {
        case 1:
            sscanf(s,"%s%s%s%s%s%s%s",studentInfo.id,studentInfo.name,
                   studentInfo.gender,studentInfo.birth_date,
                   studentInfo.college_name,studentInfo.major_name,studentInfo.passwd
                   );
            return studentInfo;
        case 2:
            sscanf(s,"%s%s%s%s%s%s%s",teacherInfo.id,teacherInfo.name,
                   teacherInfo.gender,teacherInfo.birth_date,
                   teacherInfo.college_name,teacherInfo.major_name,teacherInfo.passwd
            );
            return teacherInfo;
        case 3:
            sscanf(s,"%s%s%s%s%s%s%s",adminInfo.id,adminInfo.name,
                   adminInfo.gender,adminInfo.birth_date,
                   adminInfo.college_name,adminInfo.major_name,adminInfo.passwd
            );
            return adminInfo;
    }
}

