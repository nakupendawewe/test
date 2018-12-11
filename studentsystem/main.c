#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stu_tea_adm_struct.h"
#include "student.h"
#include "teacher.h"
#include "adm.h"
#include "super_adm.h"
#include "get_cmd.h"
#include "display.h"
#include "password.h"

Student stu[500];
Teacher tea[50];
Administrator adm[10];


void main()
{
	while(1){
		menu_display();
		switch(get_cmd('1','5'))
		{
			case '1':stu_username_and_password();break;
			case '2':tea_username_and_password();break;
			case '3':adm_username_and_password();break;
			case '4':super_password();break;
			case '5':puts("退出成功!");return;
		}
	}
}
