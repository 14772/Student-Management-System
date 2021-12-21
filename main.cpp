//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"

int stat=0;//0:δ��¼.1:ѧ����¼.2:��ʦ��¼.3:����Ա��¼.
int object;//1:ѧ��.2:��ʦ.3:����Ա.4:�γ�.5:�ɼ�.
int gradecnt;//�ɼ���¼����
int r[10][4]={{240,300,40,60},{240,300,100,120},
              {240,300,160,180},{240,300,220,240},
              {240,300,280,300},{240,300,340,360},
              {240,300,400,420},{240,300,460,480},
              {240,300,520,540},{240,300,580,600}};
//ʮ����ť������

int main() {
    initgraph(800, 640,0); //���廭����СҲ���Ǻڿ��С
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
    char s[30];//�����ַ�������
    int choice ,ch;
    MOUSEMSG m;//���������� m
    HWND wnd = GetHWnd();//����messagebox
    while (true) {
        while (true) {
            studentList = L1;//ʹͷָ���ض���ͷ��㣬����search�����ı�����ͷ���
            teacherList = L2;
            adminList = L3;
            classList = L4;
            gradesList = L5;
            cleardevice();
            loadimage(nullptr, _T("./img/a.jpg"));
            setbkmode(TRANSPARENT);// ȥ�����ֱ���
            settextcolor(RED);//����������ɫ
            settextstyle(15, 0, "����");//�������ִ�С ��ʽ
            outtextxy(250, 42, "��¼");
            outtextxy(250, 102, "ע��");
            outtextxy(250, 162, "������Ϣά��");
            outtextxy(250, 222, "���˳ɼ���ѯ");
            outtextxy(250, 282, "�ɼ���Ϣ����");
            outtextxy(250, 342, "�γ���Ϣ����");
            outtextxy(250, 402, "��ʽ��");
            outtextxy(250, 462, "�����˳�ϵͳ");
            outtextxy(250, 522, "����");
            outtextxy(250, 582, "ֱ���˳�ϵͳ");
            if ((choice = judge_button(m, 10)))
                break;
        }
        cleardevice();
        loadimage(nullptr, _T("./img/b.jpg"));
        switch (choice) {
            case 1://��¼
                outtextxy(250, 42, "ѧ����¼");
                outtextxy(250, 102, "��ʦ��¼");
                outtextxy(250, 162, "����Ա��¼");
                outtextxy(250, 222, "������һ���˵�");
                choice = judge_button(m, 4);
                if (choice != 4) {
                    InputBox(s, 30, "�������û�ID");
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
            case 2://ע��
                outtextxy(250, 42, "ѧ��ע��");
                outtextxy(250, 102, "��ʦע��");
                outtextxy(250, 162, "����Աע��");
                outtextxy(250, 222, "������һ���˵�");
                choice = judge_button(m, 4);
                switch (choice) {
                    case 1:
                        item = read_info(1);
                        if (!strcmp(item.passwd,"default"))  {
                            MessageBox(wnd, "������������7����Ϣ", "��ʾ", MB_OK);
                            break;
                        }
                        if (search_item(studentList, item.id,1) == NULL) {
                            insert_item(studentList, teacherList, adminList, classList, gradesList, item,citem, gitem, 1);
                        } else
                            MessageBox(wnd, "��ID�Ѵ��ڣ��뻻һ��ID", "����", MB_OK | MB_ICONWARNING);
                        break;
                    case 2:
                        if (stat < 2) {
                            MessageBox(wnd, "���Խ�ʦ�����Ա��ݽ��д˲�����", "����", MB_OK | MB_ICONWARNING);
                            break;
                        }
                        item = read_info(2);
                        if (!strcmp(item.passwd,"default"))  {
                            MessageBox(wnd, "������������7����Ϣ", "��ʾ", MB_OK);
                            break;
                        }
                        if (search_item(teacherList, item.id,2) == NULL) {
                            insert_item(studentList, teacherList, adminList, classList, gradesList, item,citem, gitem, 2);
                        } else
                            MessageBox(wnd, "��ID�Ѵ��ڣ��뻻һ��ID", "����", MB_OK | MB_ICONWARNING);
                        break;
                    case 3:
                        if (stat != 3) {
                            MessageBox(wnd, "���Թ���Ա��ݽ��д˲�����", "����", MB_OK | MB_ICONWARNING);
                            break;
                        }
                        item = read_info(3);
                        if (!strcmp(item.passwd,"default"))  {
                            MessageBox(wnd, "������������7����Ϣ", "��ʾ", MB_OK);
                            break;
                        }
                        if (search_item(adminList,item.id,3) == NULL) {
                            insert_item(studentList, teacherList, adminList, classList, gradesList, item,citem, gitem, 3);
                        } else
                            MessageBox(wnd, "��ID�Ѵ��ڣ��뻻һ��ID", "����", MB_OK | MB_ICONWARNING);
                        break;
                    default:
                        break;
                }
                break;
            case 3://������Ϣά��
                if (stat != 3) {
                    MessageBox(wnd, "���¼����Ա�˺��ٽ��д˲�����", "����", MB_OK | MB_ICONWARNING);
                    break;
                }
                outtextxy(250, 42, "��ѯ������Ϣ");
                outtextxy(250, 102, "�޸ĸ�����Ϣ");
                outtextxy(250, 162, "ɾ��������Ϣ");
                outtextxy(250, 222, "������һ���˵�");
                choice = judge_button(m, 4);
                switch (choice) {
                    case 1:
                        cleardevice();
                        loadimage(nullptr, _T("./img/c.jpg"));
                        outtextxy(250, 42, "��ѯѧ����Ϣ");
                        outtextxy(250, 102, "��ѯ��ʦ��Ϣ");
                        outtextxy(250, 162, "��ѯ����Ա��Ϣ");
                        outtextxy(250, 222, "����");
                        choice = judge_button(m, 4);
                        if (choice != 4) {
                            InputBox(s, 30, "������Ҫ��ѯ�ĸ�����Ϣ����ID");
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
                        outtextxy(250, 42, "�޸�ѧ����Ϣ");
                        outtextxy(250, 102, "�޸Ľ�ʦ��Ϣ");
                        outtextxy(250, 162, "�޸Ĺ���Ա��Ϣ");
                        outtextxy(250, 222, "����");
                        choice = judge_button(m, 4);
                        if (choice != 4) {
                            InputBox(s, 30, "������Ҫ�޸ĵĸ�����Ϣ����ID");
                            strcpy(tmp_id, s);
                        }
                        switch (choice) {
                            case 1:
                                item = read_info(1);
                                if(change_item(studentList,tmp_id, item, citem, gitem, 1))
                                    MessageBox(wnd, "�޸ĳɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "�޸�ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                                break;
                            case 2:
                                item = read_info(2);
                                if(change_item(teacherList,tmp_id, item, citem, gitem, 2))
                                    MessageBox(wnd, "�޸ĳɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "�޸�ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                                break;
                            case 3:
                                item = read_info(3);
                                if(change_item(adminList,tmp_id, item, citem, gitem, 3))
                                    MessageBox(wnd, "�޸ĳɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "�޸�ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 3:
                        cleardevice();
                        loadimage(nullptr, _T("./img/c.jpg"));
                        outtextxy(250, 42, "ɾ��ѧ����Ϣ");
                        outtextxy(250, 102, "ɾ����ʦ��Ϣ");
                        outtextxy(250, 162, "ɾ������Ա��Ϣ");
                        outtextxy(250, 222, "����");
                        choice = judge_button(m, 4);
                        if (choice != 4) {
                            ch = MessageBox(wnd, "�˲���Ϊɾ���˻���Ϣ���Ƿ����������", "����", MB_YESNO | MB_ICONQUESTION);
                            if (ch == IDNO)//�����NO
                                break;
                            InputBox(s, 30, "������Ҫɾ���ĸ�����Ϣ����ID");
                            strcpy(tmp_id, s);
                        }
                        switch (choice) {
                            case 1:
                                if(delete_item(studentList,tmp_id, 1))
                                    MessageBox(wnd, "ɾ���ɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "ɾ��ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                                break;
                            case 2:
                                if(delete_item(teacherList,tmp_id, 2))
                                    MessageBox(wnd, "ɾ���ɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "ɾ��ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                                break;
                            case 3:
                                if(delete_item(adminList,tmp_id, 3))
                                    MessageBox(wnd, "ɾ���ɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                                else
                                    MessageBox(wnd, "ɾ��ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 4://���˳ɼ���ѯ
                if(stat == 0) {
                    MessageBox(wnd, "���¼�����˺��ٽ��д˲���", "����", MB_OK | MB_ICONWARNING);
                    break;
                }
                InputBox(s, 30, "����Ҫ��ѯ�ɼ�������ѧ��ID");
                if(*s==0) {
                    MessageBox(wnd, "������ID", "����", MB_OK | MB_ICONWARNING);
                    break;
                }
                strcpy(tmp_id, s);
                gradesList = search_item(gradesList, tmp_id,5);
                if(gradesList==NULL) {
                    MessageBox(wnd, "���޴�ID", "����", MB_OK | MB_ICONWARNING);
                    break;
                }
                output_one_item(gradesList, 5);
                break;
            case 5://�ɼ���Ϣ����
                if (stat != 2) {
                    MessageBox(wnd, "���¼��ʦ�˺��ٽ��д˲���", "����", MB_OK | MB_ICONWARNING);
                    break;
                }
                outtextxy(250, 42, "����ɼ���Ϣ");
                outtextxy(250, 102, "ɾ���ɼ���Ϣ");
                outtextxy(250, 162, "�޸ĳɼ���Ϣ");
                outtextxy(250, 222, "�ɼ�����");
                outtextxy(250, 282, "��ʾ���гɼ�");
                outtextxy(250, 342, "����");
                choice = judge_button(m, 6);
                switch (choice) {
                    case 1 :
                        gitem = read_grades_info();
                        if (gitem.grades==-1)  {
                            MessageBox(wnd, "������������7����Ϣ", "��ʾ", MB_OK);
                            break;
                        }
                        insert_item(studentList, teacherList, adminList, classList, gradesList, item, citem,gitem, 5);//β�巨
                        break;
                    case 2 :
                        InputBox(s, 30, "����Ҫɾ����¼��ID");
                        strcpy(tmp_id, s);
                        if(delete_item(gradesList, tmp_id, 5))
                            MessageBox(wnd, "ɾ���ɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "ɾ��ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                        break;
                    case 3 :
                        gitem = read_grades_info();
                        if (gitem.grades==-1)  {
                            MessageBox(wnd, "������������7����Ϣ", "��ʾ", MB_OK);
                            break;
                        }
                        InputBox(s, 30, "����Ҫ�޸ļ�¼��ID");
                        strcpy(tmp_id, s);
                        if(change_item(gradesList, tmp_id,item, citem, gitem, 5))
                            MessageBox(wnd, "�޸ĳɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "�޸�ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                        break;
                    case 4:
                        bubble_sort(gradesList);
                        MessageBox(wnd, "�������", "��ʾ", MB_OK );
                        break;
                    case 5:
                        output_all_items(gradesList);
                        break;
                    default:
                        break;
                }
                break;
            case 6://�γ���Ϣ����
                if (stat != 2) {
                    MessageBox(wnd, "���¼��ʦ�˺��ٽ��д˲���", "����", MB_OK | MB_ICONWARNING);
                    break;
                }
                outtextxy(250, 42, "����γ���Ϣ");
                outtextxy(250, 102, "ɾ���γ���Ϣ");
                outtextxy(250, 162, "�޸Ŀγ���Ϣ");
                outtextxy(250, 222, "��ѯ�γ���Ϣ");
                outtextxy(250, 282, "����");
                choice = judge_button(m, 5);
                switch (choice) {
                    case 1 :
                        citem = read_class_info();
                        if (!strcmp(citem.teacher_name,"default"))  {
                            MessageBox(wnd, "������������6����Ϣ", "��ʾ", MB_OK);
                            break;
                        }
                        insert_item( studentList, teacherList, adminList, classList, gradesList,item, citem,gitem, 4);//β�巨
                        break;
                    case 2 :
                        InputBox(s, 30, "����Ҫɾ����¼��ID");
                        strcpy(tmp_id, s);
                        if(delete_item(classList,tmp_id, 4))
                            MessageBox(wnd, "ɾ���ɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "ɾ��ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                        break;
                    case 3 :
                        citem = read_class_info();
                        if (!strcmp(citem.teacher_name,"default"))  {
                            MessageBox(wnd, "������������6����Ϣ", "��ʾ", MB_OK);
                            break;
                        }
                        InputBox(s, 30, "����Ҫ�޸ļ�¼��ID");
                        strcpy(tmp_id, s);
                        if(change_item(classList, tmp_id,item, citem, gitem, 4))
                            MessageBox(wnd, "�޸ĳɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
                        else
                            MessageBox(wnd, "�޸�ʧ��", "��ʾ", MB_OK | MB_ICONWARNING);
                        break;
                    case 4:
                        InputBox(s, 30, "����Ҫ��ѯ�Ŀγ�����ID");
                        strcpy(tmp_id, s);
                        classList = search_item(classList,tmp_id, 4);
                        output_one_item(classList, 4);
                        break;
                    default:
                        break;
                }
                break;
            case 7://��ʽ��
                if(stat!=3) {
                    MessageBox(wnd, "���Թ���Ա���ִ�д˲���", "����", MB_OK);
                    break;
                }
                ch = MessageBox(wnd, "�˲���Ϊ��ʽ�����Ƿ����������", "����", MB_YESNO | MB_ICONQUESTION);
                if (ch == IDNO)//�����NO
                    break;
                destroy_list_and_file(&studentList, &teacherList, &adminList, &classList, &gradesList);
                return 0;
            case 8:
                save_to_file(studentList, teacherList, adminList, classList, gradesList);
                MessageBox(wnd, "���Ѿ��˳�ѧ���ɼ�����ϵͳ", "��ʾ", MB_OK | MB_ICONWARNING);
                closegraph();            // �رջ�ͼ����
                return 0;
            case 9://����
                MessageBox(wnd, "����Ա�г�ʼ�˻� admin:123456\n�����Ա�ô��˻���¼��ʱ�޸�����\n"
                                "����ɾ��documents�ļ��У���������޷�����", "��ʾ", MB_OK | MB_ICONWARNING);
                break;
            default://�˳�
                destroy_list(&studentList, &teacherList, &adminList, &classList, &gradesList);
                MessageBox(wnd, "���Ѿ��˳�ѧ���ɼ�����ϵͳ", "��ʾ", MB_OK | MB_ICONWARNING);
                closegraph();            // �رջ�ͼ����
                return 0;
        }
    }
}