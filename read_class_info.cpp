//
// Created by 14772 on 2021/11/22.
//
#include "Student_Performance_Management_System.h"
ClassInfo read_class_info()
{
    ClassInfo classInfo;
    char s[100];
    InputBox(s,100,"������γ�ID\n�γ���\nѧ����\nѧʱ��\n��ʦID\n��ʦ����",
             "�γ���Ϣ",NULL,0,180);
    sscanf(s,"%s%s%d%d%s%s%s",classInfo.class_id,classInfo.class_name,
           &classInfo.credit,&classInfo.credit_hours,
           classInfo.teacher_id,classInfo.teacher_name
    );
    return classInfo;
}
