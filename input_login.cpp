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
            MessageBox(wnd, "用户ID错误", "警告", MB_OK | MB_ICONWARNING);
            return false;
        }
        InputBox(s,30,"请输入用户密码");
        strcpy(tmp_passwd,s);
        do {
            if (!strcmp(tmp_passwd, p->data.passwd)) {
                MessageBox(wnd, "登录成功", "提示", MB_OK );
                return true;
            } else {
                InputBox(s,30,"密码错误！请再次输入密码");
                strcpy(tmp_passwd,s);
                wp_cnt++;//防止暴力破解密码
            }
        } while (wp_cnt < 3);
        return false;
    }
}
