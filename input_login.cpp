//
// Created by 14772 on 2021/11/21.
//
#include "Student_Performance_Management_System.h"

bool input_login(List *p) {
    {
        char tmp_passwd[MAX_PWD_LEN];
        char s[30];
        int wp_cnt = 0;
        HWND wnd = GetHWnd();
        if (p == nullptr) {
            MessageBox(wnd, "�û�ID����", "����", MB_OK | MB_ICONWARNING);
            return false;
        }
        InputBox(s,30,"�������û�����");
        strcpy(tmp_passwd,s);
        do {
            if (!strcmp(tmp_passwd, p->data.passwd)) {
                MessageBox(wnd, "��¼�ɹ�", "��ʾ", MB_OK );
                return true;
            } else {
                InputBox(s,30,"����������ٴ���������");
                strcpy(tmp_passwd,s);
                wp_cnt++;//��ֹ�����ƽ�����
            }
        } while (wp_cnt < 3);
        return false;
    }
}
