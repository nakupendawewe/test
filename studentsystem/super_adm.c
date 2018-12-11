#include <stdio.h>
#include <string.h>
#include <getch.h>
#include <stdlib.h>
#include"adm.h" 
#include"super_adm.h"
#include "stu_tea_adm_struct.h"
#include<time.h>
#include "display.h"
#include "get_cmd.h"
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];
extern int stu_num;

int super_count=0;
char a[10];
//**********************************
//查找管理员id是否存在
int find_adm_id(char* str)
{
	for(int i=0;i<10;i++)
	{
		if(0==strcmp(str,adm[i].adm_id)&&a[i])
		{
			return i;
		}	
	}
	return -1;
}
//*********************************
//添加管理员
int add_adm(void)
{
	int y=0;
	if(super_count>=10) 
	{
		printf("管理员个数已满，无法添加\n");
		return 0;
	}
	printf("请输入导入方式，１为单导，２为多导");
	
	while(1)
	{
		scanf("%d",&y);
		if(y == 1 || y == 2)
			break;
		printf("输入有误，请重新输入");
	}
	if(y==1)
	{
		for(int i=2;i<10;i++)
		{
			if(0==a[i])
			{
				printf("请输入管理员账号:");
				scanf("%s",adm[i].adm_id);
					if(-1!=find_adm_id(adm[i].adm_id))
					{
						puts("账号重复，输入失败！");
						return 0;
					}
				strcpy(adm[i].adm_pass_word,"88888888");
				puts("管理员添加成功");
				adm[i].is_alive=1;
				a[i]=1;
				super_count++;
				return 0;
			}
		}
	}
	//文件导入模块
	else if(2==y)
	{
		int add = 10 - super_count;
		int i = super_count;
		char fname[20];
		printf("请输入你想导入的文件：\n");
		scanf("%s",fname);
		FILE *frp = fopen(fname,"r");
		if(NULL==frp)
		{
			perror("fopen");
			sleep(1);
			return -1;
		}
		while(i < add )
		{
			fscanf(frp,"%s %d\n",adm[i].adm_id,&adm[i].is_alive);
			strcpy(adm[i].adm_pass_word,"88888888");
			a[i]=1;
			i++;
		}
		fclose(frp);
		puts("导入成功！");
		sleep(1);
		return i;
	}
}
//********************************
//删除管理员
void del_adm(void)
{
	puts("请输入管理员帐号：");
	char key[20];
	gets(key);
	int i=find_adm_id(key);
	if(-1!=i)
	{
		adm[i].is_alive=0;
		puts("删除成功!");
		a[i]=0;
		super_count--;
		return;
	}
	else puts("账号不存在");
}
//*******************************
//重置管理员密码
void res_adm_pass(void)
{
	puts("请输入管理员帐号：");
	char key[20];
	gets(key);
	int i=find_adm_id(key);
	if(-1!=i)
	{
		strcpy(adm[i].adm_pass_word,"88888888");
		puts("重置密码成功");
		adm[i].is_first=0;
		puts("按任意键返回！");
		getch();
	}
	else
	{
		puts("账号不存在，重置失败!");
		puts("按任意键返回！");
		getch();
	}
}
//****************************
//解锁锁定的管理员帐号
void unlock_adm_acc(void)
{
	puts("请输入管理员帐号：");
	char key[20];
	gets(key);
	int i=find_adm_id(key);
	if(-1!=i)
	{
		adm[i].is_lock=0;
		puts("解锁成功！");
		puts("按任意键返回！");
		getch();
	}
	else
	{
		puts("账号不存在，解锁失败！");
		puts("按任意键返回！");
		getch();
	}
}
//**************************
//显示所有管理员
void dis_all_adm(void)
{
	puts("管理员ｉｄ");
	for(int i=0;i<10;i++)
	{
		if(1==adm[i].is_alive)
		{
			printf("　　%s\n",adm[i].adm_id);
		}
	}
	puts("按任意键返回！");		
	getch();
}
//*********************************
void super_adm(void)
{
	while(1)
	{
	    sup_adm_display();
	    //选择功能模块
		switch(get_cmd('1','6'))
		{
			case '1':add_adm();sleep(1);break;
			case '2':del_adm();sleep(1);break;
			case '3':res_adm_pass();break;
			case '4':unlock_adm_acc();break;
			case '5':dis_all_adm();break;
			case '6':return;break;
		}
	}
}
