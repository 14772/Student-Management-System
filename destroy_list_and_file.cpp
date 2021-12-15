//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"

void destroy_list_and_file(StudentList **L1,TeacherList **L2,AdminList **L3,ClassList **L4,GradesList **L5)
{
    destroy_list(L1,L2,L3,L4,L5);
    remove(STUDENT_FILE_NAME);
    remove(TEACHER_FILE_NAME);
    remove(ADMIN_FILE_NAME);
    remove(CLASS_FILE_NAME);
    remove(GRADE_FILE_NAME);
}
