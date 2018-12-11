#include <stdio.h>
#include <stdlib.h>
#include "stu_tea_adm_struct.h"
#include "inf_teacher.h"
int add_stu(int stu_num){
	int is_samename = 0;
	int a = stu_num;
	int add_pat = 0;
	printf("请输入导入方式(1:单个输入，２:批量导入)：");
	while(1){
		scanf("%d",&add_pat);
		if(add_pat == 1 || add_pat == 2){
			break;
		}else{
			printf("输入有误！亲输入１或２");
		}
	}
	if(add_pat == 1){
		if(!(a < 500)){
			printf("-----------学生已满----------\n");
			sleep(1);
			return a;
		}else{
			printf("请输入学号：");
			do{
				scanf("%s",stu[a].stu_id);
				for(int i = 0;i < a;i++){
					if((stu[i].is_study == 1 || stu[i].is_study == 2) && strcmp(stu[i].stu_id,stu[a].stu_id) == 0){	
						printf("学号以存在，请重新输入：\n");
						is_samename = 1;
						break;
					}else{
						is_samename = 0;	
					}
				}
			}while(is_samename);
			printf("请输入姓名：");
			scanf("%s",stu[a].name);
			printf("请输入性别：");
			scanf("%s",stu[a].sex);
			printf("请输入年龄:");
			scanf("%d",&stu[a].age);
			printf("录入成功\n");
			stu[a].is_study = 1;
			strcpy(stu[a].stu_pass_word,"88888888"); 
			sleep(1);
			return ++a;
		}
	}
	if(add_pat == 2){
	/*****************************************/
	/*****************************************/
	}
}
