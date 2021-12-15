//
// Created by 14772 on 2021/12/4.
//
#include "Student_Performance_Management_System.h"

extern int r[10][4];

int judge_button(MOUSEMSG m,int menu) {
    while (true) {
        m = GetMouseMsg();
        if (m.x >= r[0][0] && m.x <= r[0][1] && m.y >= r[0][2] && m.y <= r[0][3] && menu>=1) {
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 1;
            }
        }
        if (m.x >= r[1][0] && m.x <= r[1][1] && m.y >= r[1][2] && m.y <= r[1][3] && menu>=2){
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 2;
            }
        }
        if (m.x >= r[2][0] && m.x <= r[2][1] && m.y >= r[2][2] && m.y <= r[2][3] && menu>=3){
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 3;
            }
        }
        if (m.x >= r[3][0] && m.x <= r[3][1] && m.y >= r[3][2] && m.y <= r[3][3] && menu>=4){
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 4;
            }
        }
        if (m.x >= r[4][0] && m.x <= r[4][1] && m.y >= r[4][2] && m.y <= r[4][3] && menu>=5){
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 5;
            }
        }
        if (m.x >= r[5][0] && m.x <= r[5][1] && m.y >= r[5][2] && m.y <= r[5][3] && menu>=6)
        {
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 6;
            }
        }
        if (m.x >= r[6][0] && m.x <= r[6][1] && m.y >= r[6][2] && m.y <= r[6][3] && menu>=7)
        {
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 7;
            }
        }
        if (m.x >= r[7][0] && m.x <= r[7][1] && m.y >= r[7][2] && m.y <= r[7][3] && menu>=8)
        {
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 8;
            }
        }
        if (m.x >= r[8][0] && m.x <= r[8][1] && m.y >= r[8][2] && m.y <= r[8][3] && menu>=9)
        {
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 9;
            }
        }
        if (m.x >= r[9][0] && m.x <= r[9][1] && m.y >= r[9][2] && m.y <= r[9][3] && menu>=10)
        {
            if (m.uMsg == WM_LBUTTONDOWN) {
                return 10;
            }
        }
    }
}
