//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"
bool change_item(List *L, char *id, struct Info new_info,ClassInfo citem,GradesInfo gitem,int object)
{
    List *p= search_item(L,id,object);
    switch(object)
    {
        case 1:
        case 2:
        case 3:
            if (p == NULL) {
                return false;
            }
            p->data = new_info;
            return true;
        case 4:
            if (p == NULL) {
                return false;
            }
            p->cdata = citem;
            return true;
        case 5:
            if (p == NULL) {
                return false;
            }
            p->gdata = gitem;
            return true;
    }
}
