//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"

void create_file()
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    FILE *fp5;
    HWND wnd = GetHWnd();
    if ((fp1 = fopen(STUDENT_FILE_NAME, "r")) == NULL) //如果文件不存在
    {
        if ((fp1 = fopen(STUDENT_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "无法建立学生信息文件", "警告", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp2 = fopen(TEACHER_FILE_NAME, "r")) == NULL) //如果文件不存在
    {
        if ((fp2 = fopen("TEACHER_FILE_NAME", "w")) == NULL)
        {
            MessageBox(wnd, "无法建立教师信息文件", "警告", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp3 = fopen(ADMIN_FILE_NAME, "r")) == NULL) //如果文件不存在
    {
        if ((fp3 = fopen(ADMIN_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "无法建立管理员信息文件", "警告", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp4 = fopen(CLASS_FILE_NAME, "r")) == NULL) //如果文件不存在
    {
        if ((fp4 = fopen(CLASS_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "无法建立课程信息文件", "警告", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp5 = fopen(GRADE_FILE_NAME, "r")) == NULL) //如果文件不存在
    {
        if ((fp5 = fopen(GRADE_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "无法建立成绩信息文件", "警告", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
}