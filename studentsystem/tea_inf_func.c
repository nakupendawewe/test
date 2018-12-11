#include <stdio.h>
#include "stu_tea_adm_struct.h"
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include "teacher.h"
#include "display.h"
#include "tea_ach_func.h"
#include "tea_inf_func.h"
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];
//当前学生数
extern int stu_num;
//一次导入的学生量              
extern int add_ach;			   
//信息管理
//添加学生模块
int add_stu(int stu_num){
	int is_samename = 0;
	int a = stu_num;
	int add_pat = 0;
	printf("请输入导入方式(1:单个输入，２:批量导入)：\n");
	//判断导入方式，１为单个添加，２为多个导入
	while(1){										
		scanf("%d",&add_pat);
		if(add_pat == 1 || add_pat == 2){
			break;
		}else{
			printf("输入有误，请输入1或者2");
		}
	}
	//单个添加
	//***************************************************
	if(add_pat == 1){
		if(!(a < 500)){
			printf("-----------学生已满----------\n");
			sleep(1);
			return a;
		}else{
			printf("请输入学号：");
			do{
				//输入学号
				scanf("%s",stu[a].stu_id);       
				for(int i = 0;i < a;i++){
					//判断是否重名或退学         
					if((stu[i].is_study == 1 || stu[i].is_study == 2) && strcmp(stu[i].stu_id,stu[a].stu_id) == 0){    	
						if(stu[i].is_study == 1){		
							printf("学号以存在，请重新输入：\n");
						}else if(stu[i].is_study == 2){
							printf("该学生虽以退学，但学号依然存在，请输入新的学号：\n");
						}
						is_samename = 1;
						break;
					}else{
						is_samename = 0;	
					}
				}
			//没有重名或者退学，则跳出
			}while(is_samename); 			
			printf("请输入姓名：");
			scanf("%s",stu[a].name);
			printf("请输入性别(1：男，２：女)：");
			scanf("%d",&stu[a].sex);
			printf("请输入年龄:");
			scanf("%d",&stu[a].age);
			printf("录入成功\n");
			stu[a].is_study = 1;
			strcpy(stu[a].stu_pass_word,"88888888"); 
			sleep(1);
			//返回当前存在的学生数
			return ++a;							 
		}
	}
	//多个导入
	//***************************************************************
	else if(add_pat == 2){
		int count = 500 - stu_num;
		int i = stu_num;
		char fname[20];
		int n = 0;
		int want_add_num = 0;
		printf("请输入想要导入的文件：\n");
		//输入想要导入的文件名
		scanf("%s",fname);						   
		printf("请输入想导入的人数:\n");
		//输入想要导入的人数
		scanf("%d",&want_add_num);                 
		FILE *frp = fopen(fname,"r");
		if(NULL == frp)
		{
			perror("fopen");
			sleep(1);
			return 0;
		}
		//从第i个学生开始导入，到想要添加的人数位置
		while(i < want_add_num + stu_num ){			
			fscanf(frp,"%s %s %d %d %d\n",stu[i].stu_id,stu[i].name,&stu[i].sex,&stu[i].age,&stu[i].is_study);
			strcpy(stu[i].stu_pass_word,"88888888");
			i++;
			if(feof(frp)){
				break;
			}
		}
		fclose(frp);
		printf("成功导入%d个学生信息\n",i - stu_num);
		add_ach = i - stu_num;		
		sleep(1);
		//返回目前的学生数
		return i;                           
	}
}


//删除学生模块
//*****************************************************************
void delet_stu(){
	int n = stu_num;
	char want_delet_id[20];
	printf("请输入要删除的学生的学号：");
	scanf("%s",want_delet_id);
	//输入想要删除的学号                         
	for(int i = 0;i < n;i++){  
		//查找是否存在该学号                   
		if(strcmp(stu[i].stu_id,want_delet_id) == 0){  
			//判断是否在读
			if(stu[i].is_study == 1){    
				//在读，则把标志位置为２              
				stu[i].is_study = 2;                   
				printf("删除成功\n");
			}else{
				printf("该学号已经是退学的的学生了\n");
			}
			sleep(1);
			//修改完毕后返回调用处
			return;									   
		}
	}
	printf("不存在该学号\n");
	sleep(1);
}

//学生信息修改模块
//**************************************************************************
void mod_stu(){
	int flag = 0;
	int is_sameid = 0;
	int n = stu_num;
	char want_mod_stu_id[20];
	printf("请输入要修改信息的学生学号：");
	//输入想要修改的学号
	scanf("%s",want_mod_stu_id);                   
	for(int i = 0;i < n;i++){
		//查找是否存在该学号
		if(strcmp(want_mod_stu_id,stu[i].stu_id) == 0){ 
			flag = i;
			printf("请输入更改后的学号：");
			//判断是否有重名
			do{										   
				scanf("%s",stu[i].stu_id);
				for(int a = 0;a < n;a++){
					if((stu[a].is_study == 1 || stu[a].is_study == 2) && strcmp(stu[a].stu_id,stu[i].stu_id) == 0 && flag != a ){	
						printf("学号以存在，请重新输入：\n");
						is_sameid = 1;
						break;
					}else{
						is_sameid = 0;	
					}
				}
			//没有重名则跳出循环
			}while(is_sameid);							
			printf("请输入更改后的姓名：");
			scanf("%s",stu[flag].name);
			printf("请输入更改后的性别（１：男，２：女）：");
			scanf("%d",&stu[flag].sex);
			printf("请输入更改后的年龄：");
			scanf("%d",&stu[flag].age);
			printf("更改信息成功\n");
			break;
		}else if(i == n - 1){
		printf("不存在该学号\n");
		}
	}
	sleep(1);
}

//重置学生登录密码模块i
//*******************************************************************
void res_stu_pass(){
	int n = stu_num;
	char want_res_stu_id[20];
	printf("请输入要重置密码的学号：");
	//输入想要重置密码的学号
	scanf("%s",want_res_stu_id);			
	for(int i = 0;i < n;i++){
		//判断是否存在该学号
		if(strcmp(want_res_stu_id,stu[i].stu_id) == 0){	
			//存在则把密码改为默认密码	
			strcpy(stu[i].stu_pass_word,"88888888"); 
			//把是否第一次登录标志位置为０		
			stu[i].is_first = 0;							
			printf("重置密码成功\n");
			sleep(1);
			return ;
		}				
	}
	printf("不存在该学号\n");
	sleep(1);
}

//解锁学生账户模块
//*****************************************************************
void unlock_stu_acc(){
	int n = stu_num;
	char want_unlock_stu_id[20];
	printf("请输入想要解锁的学号：");
	//输入想要解锁的账户
	scanf("%s",want_unlock_stu_id);		
	for(int i = 0;i < n;i++){
		//判断是否存在该学号
		if(strcmp(want_unlock_stu_id,stu[i].stu_id) == 0){		
			stu[i].is_lock = 0;					
			printf("解锁成功\n");
			sleep(1);
			//解锁成功返回调用处
			return;										  
		}
	}
	printf("不存在该学号\n");
	sleep(1);
}


//查找学生信息模块
//*****************************************************************
void sea_stu(){
	int is_one = 0;
	int n = stu_num;
	char want_know_stu[20];
	printf("请输入姓名：");
	//输入姓名
	scanf("%s",want_know_stu);							
	system("clear");
	for(int i = 0;i < n;i++){
		//判断是否存在该姓名
		if(strcmp(want_know_stu,stu[i].name) == 0){		
			printf("学号    姓名    性别    年龄    状态\n");
			printf("%-5s   %-5s    %-2s    %-3d    %-2s\n",stu[i].stu_id,stu[i].name,stu[i].sex == 1 ? "男":"女",stu[i].age,stu[i].is_study == 1 ? "在读":"退学");
			is_one = 1;
		}else if((i == n - 1) && is_one == 0){
			printf("不存在该学生\n");
		}
	}
	if(n == 0){
		printf("不存在该学生\n");
	}
	printf("* * * * * 按1键返回 * * * * *\n");
	while(1){
		if(getch() == '1')
			break;
	}
}


//显示在读学生信息
//*****************************************************************
void dis_stu(){
	system("clear");
	int n = stu_num; 
	printf("学号      姓名    性别    年龄\n");
	for(int i = 0;i < n;i++){
		//判断是否在读
		if(stu[i].is_study == 1){							
			printf("%-5s    %-5s    %-5s    %-5d\n",stu[i].stu_id,stu[i].name,stu[i].sex == 1 ? "男":"女",stu[i].age);
		}											
	}
	printf("* * * * * 按任意键返回 * * * * *");
	getch();
}


//显示退学学生信息
//*****************************************************************
void dis_drop_stu(){
	system("clear");
	int n = stu_num; 
	printf("学号      姓名    性别    年龄\n");
	for(int i = 0;i < n;i++){
		//判断是否离校
		if(stu[i].is_study == 2){									
			printf("%-5s    %-5s    %-5s    %-5d\n",stu[i].stu_id,stu[i].name,stu[i].sex == 1 ? "男":"女",stu[i].age);
		}
	}
	printf("* * * * * 按任意键返回 * * * * *");
	getch();
}
