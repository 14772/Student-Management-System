//
// Created by 14772 on 2021/11/21.
//

#ifndef STUDENT_PERFORMANCE_MANAGEMENT_SYSTEM_STUDENT_PERFORMANCE_MANAGEMENT_SYSTEM_H
#define STUDENT_PERFORMANCE_MANAGEMENT_SYSTEM_STUDENT_PERFORMANCE_MANAGEMENT_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>
#include <graphics.h>   // 引用图形库头文件(easyx)

#define STUDENT_FILE_NAME "./documents/studentinfo.txt"
#define TEACHER_FILE_NAME "./documents/teacherinfo.txt"
#define ADMIN_FILE_NAME "./documents/admininfo.txt"
#define CLASS_FILE_NAME "./documents/classinfo.txt"
#define GRADE_FILE_NAME "./documents/grades.txt"
#define MAX_ID_LEN 15
#define MAX_NAME_LEN 31
#define MAX_PWD_LEN 20
#define GENDER_LEN 8
#define DATE_LEN 11

typedef struct Info {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    char gender[GENDER_LEN];
    char birth_date[DATE_LEN];
    char college_name[MAX_NAME_LEN];
    char major_name[MAX_NAME_LEN];
    char passwd[MAX_PWD_LEN];
} StudentInfo,TeacherInfo,AdminInfo;
typedef struct {
    char class_id[MAX_ID_LEN];
    char class_name[MAX_NAME_LEN];
    int credit;
    int credit_hours;
    char teacher_id[MAX_ID_LEN];
    char teacher_name[MAX_NAME_LEN];
} ClassInfo;
typedef struct {
    char class_id[MAX_ID_LEN];
    char class_name[MAX_NAME_LEN];
    char teacher_id[MAX_ID_LEN];
    char teacher_name[MAX_NAME_LEN];
    char student_id[MAX_ID_LEN];
    char student_name[MAX_NAME_LEN];
    float grades;
} GradesInfo;
typedef struct List{
    struct Info data;
    ClassInfo cdata;
    GradesInfo gdata;
    struct List *next;
} ClassList,StudentList,TeacherList,AdminList,GradesList;

int judge_button(MOUSEMSG mousemsg,int menu);
void create_file();
bool input_login(List *pL);
struct Info read_info(int object);
ClassInfo read_class_info();
GradesInfo read_grades_info();
void init_list(StudentList **pL1,TeacherList **pL2,AdminList **pL3,ClassList **pL4,GradesList **pL5);
void destroy_list(StudentList **pL1,TeacherList **pL2,AdminList **pL3,ClassList **pL4,GradesList **pL5);
void destroy_list_and_file(StudentList **pL1,TeacherList **pL2,AdminList **pL3,ClassList **pL4,GradesList **pL5);
void save_to_file(StudentList *pL1,TeacherList *pL2,AdminList *pL3,ClassList *pL4,GradesList *pL5);
void output_all_items(GradesList *pL);
void output_one_item(List *pL,int object);
void insert_item(List *pL, struct Info item,ClassInfo citem,GradesInfo gitem,int object);
bool delete_item(List *pL, char *id,int object);
struct List *search_item(List *pL, char *id,int object);
bool change_item(List *pL, char *id, struct Info new_info,ClassInfo citem,GradesInfo gitem,int object);
void bubble_sort(GradesList *pL5);

#endif //STUDENT_PERFORMANCE_MANAGEMENT_SYSTEM_STUDENT_PERFORMANCE_MANAGEMENT_SYSTEM_H
