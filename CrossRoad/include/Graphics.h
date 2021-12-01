#pragma once 
#ifndef  _Graphics_h_
#define _Graphics_h_



#include <stdio.h>
#include <conio.h>
#include<ctime> 
#include "windows.h" 


#define KEY_NONE	-1
int whereX();
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);
//============= đặt màu cho chữ =========
void SetColor(WORD color);
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);

int inputKey();


#endif // ! _graphic_h_