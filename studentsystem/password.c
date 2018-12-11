#include "password.h"
#include "stu_tea_adm_struct.h"
#include "student.h"
#include "teacher.h"
#include "adm.h"
#include "super_adm.h"
#include "get_cmd.h"
#include "display.h"

extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];

//教师登录
void tea_username_and_password(void)
{
	char id[20];
	int tea_cur = 0;
	char str[10];
	int n = 3;
	puts("请输入工号:");
	{
		int flag = 1;
		while(flag){
			scanf("%s",id);
			for(int i = 0;i < 50;i++ ){
				//输入的id存在且该id在职
				if(0 == strcmp(tea[i].tea_id,id) && tea[i].is_work == 1){
					//若被锁定则显示
					if(tea[i].is_lock == 1){
						printf("该工号被锁定！请向上一级（管理员）申诉\n");
						sleep(1);
						return;
					//否则，退出循环，记录是第a个人
					}else{
						flag = 0;
						tea_cur = i; 
						break;
					}
				//输入id存在但离职或不存在，显示不存在
				}else if((0 == strcmp(tea[i].tea_id,id) && tea[i].is_work == 2) || (i == 49)){
					printf("该工号不存在\n");
					sleep(1);
					return;
				}
			}
		}
	}
	puts("请输入密码：");
	do{
		n--;
		scanf("%s",str);
		//输入的密码与该账号密码不相同，则进入
		if(0 != strcmp(tea[tea_cur].tea_pass_word,str)){
		//n记录剩余次数
			if(n > 0){
				printf("密码错误，请重新输入（还有%d次）\n",n);	
			}else{
				printf("工号被锁定！请向上一级（管理员）申诉\n");
				tea[tea_cur].is_lock=1;
				sleep(1);
				return;
			}
		}
		//如果相同则进入教师模块
		else{
			//传参内容：第a个教师
			teacher_func(tea_cur);
			n = 0;
		}
	}while(n);
}
//学生登录
void stu_username_and_password(void)
{
	char id[20];
	int stu_cur = 0;
	char str[10];
	int n = 3;
	puts("请输入学号:");
	int flag = 1;
	while(flag){
		scanf("%s",id);
		for(int i = 0;i < 500;i++ ){
			if(0 == strcmp(stu[i].stu_id,id) && stu[i].is_study ==1){
				if(stu[i].is_lock == 1){
					printf("该学号被锁定！请向上一级（教师）申诉\n");
					sleep(1);
					return;
				}else{
					flag = 0;
					stu_cur = i; 
					break;
				}
			}
			else if((0 == strcmp(stu[i].stu_id,id) && stu[i].is_study ==2) ||(i == 499)){
				printf("该学号不存在\n");
				sleep(1);
				return;
			}
		}
	}	
	puts("请输入密码：");
	do{
		n--;
		scanf("%s",str);
		if(0 != strcmp(stu[stu_cur].stu_pass_word,str)){
			if(n > 0){
				printf("密码错误，请重新输入（还有%d次）\n",n);	
			}else{
				printf("学号被锁定！请向上一级（教师）申诉\n");
				stu[stu_cur].is_lock=1;
				sleep(1);
				return;
			}
		}
		else{
			student_use(stu_cur);
			n = 0;
		}
	}while(n);
}
//管理员登录
void adm_username_and_password(void)
{
	char id[20];
	char id_flag[20];
	int adm_cur = 0;
	char str[10];
	int n = 3;
	puts("请输入管理号ID:");
	int flag = 1;
	while(flag){
		scanf("%s",id);
		for(int i = 0;i < 10;i++ ){
			if(0 == strcmp(id,adm[i].adm_id) && adm[i].is_alive == 1){
				if(adm[i].is_lock == 1){
					printf("该管理员ＩＤ被锁定！请向上一级（超级管理员）申诉\n");
					sleep(1);
					return;
				}else{
					flag = 0;
					adm_cur = i; 
					break;
				}
			}else if((0 == strcmp(id,adm[i].adm_id) && adm[i].is_alive) || (i == 9)){
				printf("该管理员不存在\n");
				sleep(1);
				return;
			}
		}
	}
	puts("请输入密码：");
	do{
		n--;
		scanf("%s",str);
		if(0 != strcmp(adm[adm_cur].adm_pass_word,str)){
			if(n > 0){
				printf("密码错误，请重新输入（还有%d次）\n",n);	
			}else{
				printf("管理员ＩＤ被锁定！请向上一级（超级管理员）申诉\n");
				adm[adm_cur].is_lock=1;
				sleep(1);
				return;
			}
		}
		else{
			nor_adm(adm_cur);
			n = 0;
		}
	}while(n);
}
//超级管理员登录
void super_password(void)
{
	char str[20]="888888";
	char *super_pass;
	puts("请输入密码：");
	while(1)
	{	
		//getpass不显示输入内容
		super_pass = getpass("");
		if(0 == strcmp(super_pass,str))
		{
			//若相同进入超级管理员模块，否则继续输入
			super_adm();
			break;
		}
	}
}

