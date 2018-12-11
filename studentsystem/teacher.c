#include <stdio.h>
#include "stu_tea_adm_struct.h"
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include "teacher.h"
#include "display.h"
#include "get_cmd.h"
#include "tea_inf_func.h"
#include "tea_ach_func.h"
extern Teacher tea[50];
int stu_num = 0;               //当前学生数
int add_ach = 0;			   //一次导入的学生量

//修改教师密码模块
//*****************************************************************
void tea_cha_pass(int i){
	printf("请输入修改后的密码：");
	scanf("%s",tea[i].tea_pass_word);
	printf("修改成功\n");
	sleep(1);
}

//学生信息操作模块
//*****************************************************************
void inf_key(int i){
	while(1){
		tea_inf_func_display(i);
		switch(get_cmd('1','9')){							//输入1 ~ 9进行相应操作
			case '1':stu_num = add_stu(stu_num);
				break;
			case '2':delet_stu();
				break;
			case '3':mod_stu();
				break;
			case '4':res_stu_pass();
				break;
			case '5':unlock_stu_acc();
				break;
			case '6':sea_stu();
				break;
			case '7':dis_stu();
				break;
			case '8':dis_drop_stu();
				break;
			case '9':return;
		}
	}
}


//学生成绩操作模块
//*****************************************************************
void ach_key(int i){
	while(1){
		tea_ach_func_display(i);
		switch(get_cmd('1','5')){							//输入1 ~ 5进行相应操作
			case '1':add_stu_ach();
				break;
			case '2':mod_stu_ach();
				break;
			case '3':sea_ach();
				break;
			case '4':ach_sort();
				break;
			case '5':return;
		}
	}
}

//学生操作模块
//*****************************************************************
void teacher_func(int i){
	tea_display(i);	
	if(tea[i].is_first == 0){						//判断该账号是否为第一次登录
		printf("请更改登录密码:");
		scanf("%s",tea[i].tea_pass_word);			//是则输入修改后的密码
		printf("更改成功\n");
		tea[i].is_first = 1;
		sleep(1);
	}
	while(1){	
		tea_display(i);
		switch(get_cmd('1','4')){					//输入1 ~ 4进行相关操作
			case '1':inf_key(i);
				break;
			case '2':ach_key(i);
				break;
			case '3':tea_cha_pass(i);
				break;
			case '4':return;
		}
	}
}
