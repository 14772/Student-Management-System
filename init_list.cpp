//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"

void init_list(StudentList **L1,TeacherList **L2,AdminList **L3,ClassList **L4,GradesList **L5) {
    extern int gradecnt;
    int exec_cnt=0;
    FILE *fp;
    *L1 = (StudentList *) malloc(sizeof(StudentList));
    StudentList *new_node1, *p1 = *L1;
    StudentInfo studentInfo;
    HWND wnd = GetHWnd();
    if ((fp = fopen(STUDENT_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(STUDENT_FILE_NAME, "w")) == NULL) {
            MessageBox(wnd, "读取学生信息文件失败", "警告", MB_OK | MB_ICONWARNING);
            return;
        }
    } else
        while (!feof(fp)) {
            new_node1 = (StudentList *) malloc(sizeof(StudentList));
            fscanf(fp, "%s\t", studentInfo.id);
            fscanf(fp, "%s\t", studentInfo.name);
            fscanf(fp, "%s\t", studentInfo.gender);
            fscanf(fp, "%s\t", studentInfo.birth_date);
            fscanf(fp, "%s\t", studentInfo.college_name);
            fscanf(fp, "%s\t", studentInfo.major_name);
            fscanf(fp, "%s\n", studentInfo.passwd);
            new_node1->data = studentInfo;
            p1->next = new_node1;
            p1 = p1->next;
        }
        p1->next=NULL;
    fclose(fp);
    *L2 = (TeacherList *) malloc(sizeof(TeacherList));
    TeacherList *new_node2, *p2 = *L2;
    TeacherInfo teacherInfo;
    if ((fp = fopen(TEACHER_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(TEACHER_FILE_NAME, "w")) == NULL) {
            MessageBox(wnd, "读取教师信息文件失败", "警告", MB_OK | MB_ICONWARNING);
            return;
        }
    } else
        while (!feof(fp)) {
            new_node2 = (TeacherList *) malloc(sizeof(TeacherList));
            fscanf(fp, "%s\t", teacherInfo.id);
            fscanf(fp, "%s\t", teacherInfo.name);
            fscanf(fp, "%s\t", teacherInfo.gender);
            fscanf(fp, "%s\t", teacherInfo.birth_date);
            fscanf(fp, "%s\t", teacherInfo.college_name);
            fscanf(fp, "%s\n", teacherInfo.major_name);
            fscanf(fp, "%s\n", teacherInfo.passwd);
            new_node2->data = teacherInfo;
            p2->next = new_node2;
            p2 = p2->next;
        }
        p2->next=NULL;
    fclose(fp);
    *L3 = (AdminList *) malloc(sizeof(AdminList));
    AdminList *new_node3, *p3 = *L3;
    AdminInfo adminInfo;
    if ((fp = fopen(ADMIN_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(ADMIN_FILE_NAME, "w")) == NULL) {
            MessageBox(wnd, "读取管理员信息文件失败", "警告", MB_OK | MB_ICONWARNING);
            return;
        }
    } else
        while (!feof(fp)) {
            new_node3 = (TeacherList *) malloc(sizeof(TeacherList));
            if(exec_cnt!=0)
            {
                fscanf(fp, "%s\t", adminInfo.id);
                fscanf(fp, "%s\t", adminInfo.name);
                fscanf(fp, "%s\t", adminInfo.gender);
                fscanf(fp, "%s\t", adminInfo.birth_date);
                fscanf(fp, "%s\t", adminInfo.college_name);
                fscanf(fp, "%s\n", adminInfo.major_name);
                fscanf(fp, "%s\n", adminInfo.passwd);
            }
            else//初始化admin账户
            {
                strcpy(adminInfo.id,"admin");
                strcpy(adminInfo.name,"none");
                strcpy(adminInfo.gender,"none");
                strcpy(adminInfo.birth_date,"none");
                strcpy(adminInfo.college_name,"none");
                strcpy(adminInfo.major_name,"none");
                strcpy(adminInfo.passwd,"123456");
            }
            if(!strcmp(adminInfo.id,"admin")&&exec_cnt!=0)
                continue;//避免读取到初始化的的admin账户
            new_node3->data = adminInfo;
            p3->next = new_node3;
            p3 = p3->next;
            exec_cnt++;
        }
        p3->next=NULL;
    fclose(fp);
    *L4 = (ClassList *) malloc(sizeof(ClassList));
    ClassList *new_node4, *p4 = *L4;
    ClassInfo classInfo;
    if ((fp = fopen(CLASS_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(CLASS_FILE_NAME, "w")) == NULL) {
            MessageBox(wnd, "读取课程信息文件失败", "警告", MB_OK | MB_ICONWARNING);
            return;
        }
    } else
        while (!feof(fp)) {
            new_node4 = (ClassList *) malloc(sizeof(ClassList));
            fscanf(fp, "%s\t", classInfo.class_id);
            fscanf(fp, "%s\t", classInfo.class_name);
            fscanf(fp, "%d\t", &classInfo.credit);
            fscanf(fp, "%d\t", &classInfo.credit_hours);
            fscanf(fp, "%s\t", classInfo.teacher_id);
            fscanf(fp, "%s\n", classInfo.teacher_name);
            new_node4->cdata = classInfo;
            p4->next = new_node4;
            p4 = p4->next;
        }
    p4->next=NULL;
    fclose(fp);
    *L5 = (GradesList *) malloc(sizeof(GradesList));
    GradesList *new_node5, *p5 = *L5;
    GradesInfo gradesinfo;
    if ((fp = fopen(GRADE_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(GRADE_FILE_NAME, "w")) == NULL) {
            MessageBox(wnd, "读取成绩信息文件失败", "警告", MB_OK | MB_ICONWARNING);
            return;
        }
    } else
        while (!feof(fp)) {
            new_node5 = (GradesList *) malloc(sizeof(GradesList));
            fscanf(fp, "%s\t", gradesinfo.class_id);
            fscanf(fp, "%s\t", gradesinfo.class_name);
            fscanf(fp, "%s\t", gradesinfo.teacher_id);
            fscanf(fp, "%s\t", gradesinfo.teacher_name);
            fscanf(fp, "%s\t", gradesinfo.student_id);
            fscanf(fp, "%s\n", gradesinfo.student_name);
            fscanf(fp, "%f\n", &gradesinfo.grades);
            new_node5->gdata = gradesinfo;
            p5->next = new_node5;
            p5 = p5->next;
            gradecnt++;
        }
    p5->next=NULL;
    fclose(fp);
}
