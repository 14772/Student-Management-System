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
    if ((fp1 = fopen(STUDENT_FILE_NAME, "r")) == NULL) //����ļ�������
    {
        if ((fp1 = fopen(STUDENT_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "�޷�����ѧ����Ϣ�ļ�", "����", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp2 = fopen(TEACHER_FILE_NAME, "r")) == NULL) //����ļ�������
    {
        if ((fp2 = fopen("TEACHER_FILE_NAME", "w")) == NULL)
        {
            MessageBox(wnd, "�޷�������ʦ��Ϣ�ļ�", "����", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp3 = fopen(ADMIN_FILE_NAME, "r")) == NULL) //����ļ�������
    {
        if ((fp3 = fopen(ADMIN_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "�޷���������Ա��Ϣ�ļ�", "����", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp4 = fopen(CLASS_FILE_NAME, "r")) == NULL) //����ļ�������
    {
        if ((fp4 = fopen(CLASS_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "�޷������γ���Ϣ�ļ�", "����", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
    if ((fp5 = fopen(GRADE_FILE_NAME, "r")) == NULL) //����ļ�������
    {
        if ((fp5 = fopen(GRADE_FILE_NAME, "w")) == NULL)
        {
            MessageBox(wnd, "�޷������ɼ���Ϣ�ļ�", "����", MB_OK | MB_ICONWARNING);
            exit(0);
        }
    }
}