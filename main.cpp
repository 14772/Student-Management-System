//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"

int stat=0;//0:未登录.1:学生登录.2:教师登录.3:管理员登录.
int object;//1:学生.2:教师.3:管理员.4:课程.5:成绩.
int gradecnt;//成绩记录条数
int r[10][4]={{240,300,40,60},{240,300,100,120},
              {240,300,160,180},{240,300,220,240},
              {240,300,280,300},{240,300,340,360},
              {240,300,400,420},{240,300,460,480},
              {240,300,520,540},{240,300,580,600}};
//十个按钮的坐标

int main() {
    initgraph(800, 640,0); //定义画布大小也就是黑框大小
    create_file();
    StudentList *studentList, *L1;
    TeacherList *teacherList, *L2;
    AdminList *adminList, *L3;
    ClassList *classList, *L4;
    GradesList *gradesList, *L5;
    init_list(&studentList, &teacherList, &adminList, &classList, &gradesList);
    L1 = studentList;
    L2 = teacherList;
    L3 = adminList;
    L4 = classList;
    L5 = gradesList;
    struct Info item;
    ClassInfo citem;
    GradesInfo gitem;
    char tmp_id[MAX_ID_LEN];
    char s[30];//输入字符串变量
    int choice ,ch;
    MOUSEMSG m;//定义鼠标变量 m
    HWND wnd = GetHWnd();//用于messagebox
    while (true) {
        while (true) {
            studentList = L1;//使头指针重定向到头结点，以免search函数改变链表头结点
            teacherList = L2;
            adminList = L3;
            classList = L4;
            gradesList = L5;
            cleardevice();
            loadimage(nullptr, _T("./img/a.jpg"));
            setbkmode(TRANSPARENT);// 去掉文字背景
            settextcolor(RED);//设置文字颜色
            settextstyle(15, 0, "隶书");//设置文字大小 格式
            outtextxy(250, 42, "登录");
            outtextxy(250, 102, "注册");
            outtextxy(250, 162, "个人信息维护");
            outtextxy(250, 222, "个人成绩查询");
            outtextxy(250, 282, "成绩信息管理");
            outtextxy(250, 342, "课程信息管理");
            outtextxy(250, 402, "格式化");
            outtextxy(250, 462, "存盘退出系统");
            outtextxy(250, 522, "帮助");
            outtextxy(250, 582, "直接退出系统");
            if ((choice = judge_button(m, 10)))
                break;
        }
        cleardevice();
        loadimage(nullptr, _T("./img/b.jpg"));
        switch (choice) {
            case 1://登录
                outtextxy(250, 42, "学生登录");
                outtextxy(250, 102, "教师登录");
                outtextxy(250, 162, "管理员登录");
                outtextxy(250, 222, "返回上一级菜单");
                choice = judge_button(m, 4);
                if (choice != 4) {
                    InputBox(s, 30, "请输入用户ID");
                    strcpy(tmp_id, s);
                }
                switch (choice) {
                    case 1:
                        studentList = search_item(studentList, tmp_id, 1);
                        if (input_login(studentList))
                            stat = 1;
                        break;
                    case 2:
                        teacherList = search_item(teacherList, tmp_id, 2);
                        if (input_login(teacherList))
                            stat = 2;
                        break;
                    case 3:
                        adminList = search_item( adminList,tmp_id, 3);
                        if (input_login(adminList))
                            stat = 3;
                        break;
                    default:
                        break;
                }
                break;
            case 2://注册
                outtextxy(250, 42, "学生注册");
                outtextxy(250, 102, "教师注册");
                outtextxy(250, 162, "管理员注册");
                outtextxy(250, 222, "返回上一级菜单");
                choice = judge_button(m, 4);
                switch (choice) {
                    case 1:
                        item = read_info(1);
                        if (!strcmp(item.passwd,"default"))  {
                            MessageBox(wnd, "请输入完整的7条信息", "提示", MB_OK);
                            break;
                        }
                        if (search_item(studentList, item.id,1) == NULL) {
                            insert_item(studentList, teacherList, adminList, classList, gradesList, item,citem, gitem, 1);
                        } else
                            MessageBox(wnd, "此ID已存在，请换一个ID", "警告", MB_OK | MB_ICONWARNING);
                        break;
                    case 2:
                        if (stat < 2) {
                            MessageBox(wnd, "请以教师或管理员身份进行此操作！", "警告", MB_OK | MB_ICONWARNING);
                            break;
                        }
                        item = read_info(2);
                        if (!strcmp(item.passwd,"default"))  {
                            MessageBox(wnd, "请输入完整的7条信息", "提示", MB_OK);
                            break;
                        }
                        if (search_item(teacherList, item.id,2) == NULL) {
                            insert_item(studentList, teacherList, adminList, classList, gradesList, item,citem, gitem, 2);
                        } else
                            MessageBox(wnd, "此ID已存在，请换一个ID", "警告", MB_OK | MB_ICONWARNING);
                        break;
                    case 3:
                        if (stat != 3) {
                            MessageBox(wnd, "请以管理员身份进行此操作！", "警告", MB_OK | MB_ICONWARNING);
                            break;
                        }
                        item = read_info(3);
                        if (!strcmp(item.passwd,"default"))  {
                            MessageBox(wnd, "请输入完整的7条信息", "提示", MB_OK);
                            break;
                        }
                        if (search_item(adminList,item.id,3) == NULL) {
                            insert_item(studentList, teacherList, adminList, classList, gradesList, item,citem, gitem, 3);
                        } else
                            MessageBox(wnd, "此ID已存在，请换一个ID", "警告", MB_OK | MB_ICONWARNING);
                        break;
                    default:
                        break;
                }
                break;
            case 3://个人信息维护
                if (stat != 3) {
                    MessageBox(wnd, "请登录管理员账号再进行此操作！", "警告", MB_OK | MB_ICONWARNING);
                    break;
                }
                outtextxy(250, 42, "查询个人信息");
                outtextxy(250, 102, "修改个人信息");
                outtextxy(250, 162, "删除个人信息");
                outtextxy(250, 222, "返回上一级菜单");
                choice = judge_button(m, 4);
                switch (choice) {
                    case 1:
                        cleardevice();
                        loadimage(nullptr, _T("./img/c.jpg"));
                        outtextxy(250, 42, "查询学生信息");
                        outtextxy(250, 102, "查询教师信息");
                        outtextxy(250, 162, "查询管理员信息");
                        outtextxy(250, 222, "返回");
                        choice = judge_button(m, 4);
                        if (choice != 4) {
                            InputBox(s, 30, "请输入要查询的个人信息所属ID");
                            strcpy(tmp_id, s);
                        }
                        switch (choice) {
                            case 1:
                                studentList = search_item(studentList, tmp_id, 1);
                                output_one_item(studentList,1);
                                break;
                            case 2:
                                teacherList = search_item(teacherList, tmp_id, 2);
                                output_one_item(teacherList,2);
                                break;
                            case 3:
                                adminList = search_item(adminList, tmp_id, 3);
                                output_one_item(adminList,3);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        cleardevice();
                        loadimage(nullptr, _T("./img/c.jpg"));
                        outtextxy(250, 42, "修改学生信息");
                        outtextxy(250, 102, "修改教师信息");
                        outtextxy(250, 162, "修改管理员信息");
                        outtextxy(250, 222, "返回");
                        choice = judge_button(m, 4);
                        if (choice != 4) {
                            InputBox(s, 30, "请输入要修改的个人信息所属ID");
                            strcpy(tmp_id, s);
                        }
                        switch (choice) {
                            case 1:
                                item = read_info(1);
                                if(change_item(studentList,tmp_id, item, citem, gitem, 1))
                                    MessageBox(wnd, "修改成功", "提示", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "修改失败", "提示", MB_OK | MB_ICONWARNING);
                                break;
                            case 2:
                                item = read_info(2);
                                if(change_item(teacherList,tmp_id, item, citem, gitem, 2))
                                    MessageBox(wnd, "修改成功", "提示", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "修改失败", "提示", MB_OK | MB_ICONWARNING);
                                break;
                            case 3:
                                item = read_info(3);
                                if(change_item(adminList,tmp_id, item, citem, gitem, 3))
                                    MessageBox(wnd, "修改成功", "提示", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "修改失败", "提示", MB_OK | MB_ICONWARNING);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 3:
                        cleardevice();
                        loadimage(nullptr, _T("./img/c.jpg"));
                        outtextxy(250, 42, "删除学生信息");
                        outtextxy(250, 102, "删除教师信息");
                        outtextxy(250, 162, "删除管理员信息");
                        outtextxy(250, 222, "返回");
                        choice = judge_button(m, 4);
                        if (choice != 4) {
                            ch = MessageBox(wnd, "此操作为删除账户信息！是否继续操作？", "警告", MB_YESNO | MB_ICONQUESTION);
                            if (ch == IDNO)//点击了NO
                                break;
                            InputBox(s, 30, "请输入要删除的个人信息所属ID");
                            strcpy(tmp_id, s);
                        }
                        switch (choice) {
                            case 1:
                                if(delete_item(studentList,tmp_id, 1))
                                    MessageBox(wnd, "删除成功", "提示", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "删除失败", "提示", MB_OK | MB_ICONWARNING);
                                break;
                            case 2:
                                if(delete_item(teacherList,tmp_id, 2))
                                    MessageBox(wnd, "删除成功", "提示", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "删除失败", "提示", MB_OK | MB_ICONWARNING);
                                break;
                            case 3:
                                if(delete_item(adminList,tmp_id, 3))
                                    MessageBox(wnd, "删除成功", "提示", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "删除失败", "提示", MB_OK | MB_ICONWARNING);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 4://个人成绩查询
                if(stat == 0) {
                    MessageBox(wnd, "请登录任意账号再进行此操作", "警告", MB_OK | MB_ICONWARNING);
                    break;
                }
                InputBox(s, 30, "输入要查询成绩的所属学生ID");
                if(*s==0) {
                    MessageBox(wnd, "请输入ID", "警告", MB_OK | MB_ICONWARNING);
                    break;
                }
                strcpy(tmp_id, s);
                gradesList = search_item(gradesList, tmp_id,5);
                if(gradesList==NULL) {
                    MessageBox(wnd, "查无此ID", "警告", MB_OK | MB_ICONWARNING);
                    break;
                }
                output_one_item(gradesList, 5);
                break;
            case 5://成绩信息管理
                if (stat != 2) {
                    MessageBox(wnd, "请登录教师账号再进行此操作", "警告", MB_OK | MB_ICONWARNING);
                    break;
                }
                outtextxy(250, 42, "插入成绩信息");
                outtextxy(250, 102, "删除成绩信息");
                outtextxy(250, 162, "修改成绩信息");
                outtextxy(250, 222, "成绩排序");
                outtextxy(250, 282, "显示所有成绩");
                outtextxy(250, 342, "返回");
                choice = judge_button(m, 6);
                switch (choice) {
                    case 1 :
                        gitem = read_grades_info();
                        if (gitem.grades==-1)  {
                            MessageBox(wnd, "请输入完整的7条信息", "提示", MB_OK);
                            break;
                        }
                        insert_item(studentList, teacherList, adminList, classList, gradesList, item, citem,gitem, 5);//尾插法
                        break;
                    case 2 :
                        InputBox(s, 30, "输入要删除记录的ID");
                        strcpy(tmp_id, s);
                        if(delete_item(gradesList, tmp_id, 5))
                            MessageBox(wnd, "删除成功", "提示", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "删除失败", "提示", MB_OK | MB_ICONWARNING);
                        break;
                    case 3 :
                        gitem = read_grades_info();
                        if (gitem.grades==-1)  {
                            MessageBox(wnd, "请输入完整的7条信息", "提示", MB_OK);
                            break;
                        }
                        InputBox(s, 30, "输入要修改记录的ID");
                        strcpy(tmp_id, s);
                        if(change_item(gradesList, tmp_id,item, citem, gitem, 5))
                            MessageBox(wnd, "修改成功", "提示", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "修改失败", "提示", MB_OK | MB_ICONWARNING);
                        break;
                    case 4:
                        bubble_sort(gradesList);
                        MessageBox(wnd, "排序完成", "提示", MB_OK );
                        break;
                    case 5:
                        output_all_items(gradesList);
                        break;
                    default:
                        break;
                }
                break;
            case 6://课程信息管理
                if (stat != 2) {
                    MessageBox(wnd, "请登录教师账号再进行此操作", "警告", MB_OK | MB_ICONWARNING);
                    break;
                }
                outtextxy(250, 42, "插入课程信息");
                outtextxy(250, 102, "删除课程信息");
                outtextxy(250, 162, "修改课程信息");
                outtextxy(250, 222, "查询课程信息");
                outtextxy(250, 282, "返回");
                choice = judge_button(m, 5);
                switch (choice) {
                    case 1 :
                        citem = read_class_info();
                        if (!strcmp(citem.teacher_name,"default"))  {
                            MessageBox(wnd, "请输入完整的6条信息", "提示", MB_OK);
                            break;
                        }
                        insert_item( studentList, teacherList, adminList, classList, gradesList,item, citem,gitem, 4);//尾插法
                        break;
                    case 2 :
                        InputBox(s, 30, "输入要删除记录的ID");
                        strcpy(tmp_id, s);
                        if(delete_item(classList,tmp_id, 4))
                            MessageBox(wnd, "删除成功", "提示", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "删除失败", "提示", MB_OK | MB_ICONWARNING);
                        break;
                    case 3 :
                        citem = read_class_info();
                        if (!strcmp(citem.teacher_name,"default"))  {
                            MessageBox(wnd, "请输入完整的6条信息", "提示", MB_OK);
                            break;
                        }
                        InputBox(s, 30, "输入要修改记录的ID");
                        strcpy(tmp_id, s);
                        if(change_item(classList, tmp_id,item, citem, gitem, 4))
                            MessageBox(wnd, "修改成功", "提示", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "修改失败", "提示", MB_OK | MB_ICONWARNING);
                        break;
                    case 4:
                        InputBox(s, 30, "输入要查询的课程所属ID");
                        strcpy(tmp_id, s);
                        classList = search_item(classList,tmp_id, 4);
                        output_one_item(classList, 4);
                        break;
                    default:
                        break;
                }
                break;
            case 7://格式化
                if(stat!=3) {
                    MessageBox(wnd, "请以管理员身份执行此操作", "警告", MB_OK);
                    break;
                }
                ch = MessageBox(wnd, "此操作为格式化！是否继续操作？", "警告", MB_YESNO | MB_ICONQUESTION);
                if (ch == IDNO)//点击了NO
                    break;
                destroy_list_and_file(&studentList, &teacherList, &adminList, &classList, &gradesList);
                return 0;
            case 8:
                save_to_file(studentList, teacherList, adminList, classList, gradesList);
                MessageBox(wnd, "您已经退出学生成绩管理系统", "提示", MB_OK | MB_ICONWARNING);
                closegraph();            // 关闭绘图窗口
                return 0;
            case 9://帮助
                MessageBox(wnd, "管理员有初始账户 admin:123456\n请管理员用此账户登录后及时修改密码\n"
                                "请勿删除documents文件夹，否则程序无法进行", "提示", MB_OK | MB_ICONWARNING);
                break;
            default://退出
                destroy_list(&studentList, &teacherList, &adminList, &classList, &gradesList);
                MessageBox(wnd, "您已经退出学生成绩管理系统", "提示", MB_OK | MB_ICONWARNING);
                closegraph();            // 关闭绘图窗口
                return 0;
        }
    }
}