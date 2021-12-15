//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
void save_to_file(StudentList *L1,TeacherList *L2,AdminList *L3,ClassList *L4,GradesList *L5) {
    if (L1 == NULL)
        return;
    if (L2 == NULL)
        return;
    if (L3 == NULL)
        return;
    if (L4 == NULL)
        return;
    if (L5 == NULL)
        return;
    StudentList *p1 = L1->next;
    TeacherList *p2 = L2->next;
    AdminList *p3 = L3->next;
    ClassList *p4 = L4->next;
    GradesList *p5 = L5->next;
    FILE *fp;
    HWND wnd = GetHWnd();
    if ((fp = fopen(STUDENT_FILE_NAME, "w")) == NULL) {
        MessageBox(wnd, "无法保存学生信息文件", "警告", MB_OK | MB_ICONWARNING);
    }
    while (p1 != NULL) {
        fprintf(fp, "%s\t", p1->data.id);
        fprintf(fp, "%s\t", p1->data.name);
        fprintf(fp, "%s\t", p1->data.gender);
        fprintf(fp, "%s\t", p1->data.birth_date);
        fprintf(fp, "%s\t", p1->data.college_name);
        fprintf(fp, "%s\t", p1->data.major_name);
        fprintf(fp, "%s\n", p1->data.passwd);
        p1 = p1->next;
    }
    fclose(fp);
    if ((fp = fopen(TEACHER_FILE_NAME, "w")) == NULL) {
        MessageBox(wnd, "无法保存教师信息文件", "警告", MB_OK | MB_ICONWARNING);
    }
    while (p2 != NULL) {
        fprintf(fp, "%s\t", p2->data.id);
        fprintf(fp, "%s\t", p2->data.name);
        fprintf(fp, "%s\t", p2->data.gender);
        fprintf(fp, "%s\t", p2->data.birth_date);
        fprintf(fp, "%s\t", p2->data.college_name);
        fprintf(fp, "%s\t", p2->data.major_name);
        fprintf(fp, "%s\n", p2->data.passwd);
        p2 = p2->next;
    }
    fclose(fp);
    if ((fp = fopen(ADMIN_FILE_NAME, "w")) == NULL) {
        MessageBox(wnd, "无法保存管理员信息文件", "警告", MB_OK | MB_ICONWARNING);
    }
    while (p3 != NULL) {
        fprintf(fp, "%s\t", p3->data.id);
        fprintf(fp, "%s\t", p3->data.name);
        fprintf(fp, "%s\t", p3->data.gender);
        fprintf(fp, "%s\t", p3->data.birth_date);
        fprintf(fp, "%s\t", p3->data.college_name);
        fprintf(fp, "%s\t", p3->data.major_name);
        fprintf(fp, "%s\n", p3->data.passwd);
        p3 = p3->next;
    }
    fclose(fp);
    if ((fp = fopen(CLASS_FILE_NAME, "w")) == NULL) {
        MessageBox(wnd, "无法保存课程信息文件", "警告", MB_OK | MB_ICONWARNING);
    }
    while (p4 != NULL) {
        fprintf(fp, "%s\t", p4->cdata.class_id);
        fprintf(fp, "%s\t", p4->cdata.class_name);
        fprintf(fp, "%d\t", p4->cdata.credit);
        fprintf(fp, "%d\t", p4->cdata.credit_hours);
        fprintf(fp, "%s\t", p4->cdata.teacher_id);
        fprintf(fp, "%s\n", p4->cdata.teacher_name);
        p4 = p4->next;
    }
    fclose(fp);
    if ((fp = fopen(GRADE_FILE_NAME, "w")) == NULL) {
        MessageBox(wnd, "无法保存成绩信息文件", "警告", MB_OK | MB_ICONWARNING);
    }
    while (p5 != NULL) {
        fprintf(fp, "%s\t", p5->gdata.class_id);
        fprintf(fp, "%s\t", p5->gdata.class_name);
        fprintf(fp, "%s\t", p5->gdata.teacher_id);
        fprintf(fp, "%s\t", p5->gdata.teacher_name);
        fprintf(fp, "%s\t", p5->gdata.student_id);
        fprintf(fp, "%s\t", p5->gdata.student_name);
        fprintf(fp, "%3.2f\n", p5->gdata.grades);
        p5 = p5->next;
    }
    fclose(fp);
}
