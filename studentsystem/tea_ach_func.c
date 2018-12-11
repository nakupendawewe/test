#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include "tea_ach_func.h"
#include "teacher.h"
#include "stu_tea_adm_struct.h"
#include <string.h>
extern Student stu[500];
extern Teacher tea[50];
extern Administrator adm[10];
extern int  stu_num;//表示当前的学生数
extern int add_ach;//表示想添加的学生数
int stu_num_cur = 0;

//学生成绩录入模块
//*****************************************************
void add_stu_ach(){
	int have_stu = 0;
	int n = stu_num;
	int add_pat = 0;
	char want_add_ach_id[20];
	printf("请输入导入方式(1:单个输入，２:批量导入)：\n");     //选择录入方式，１为单个输入，２为多个导入
	while(1){
		scanf("%d",&add_pat);
		if(add_pat == 1 || add_pat == 2)
			break;
		printf("输入有误，请重新输入：");
	}
//*****************************************************
	if(add_pat == 1){
		printf("请输入想要录入成绩的学号：");
		scanf("%s",want_add_ach_id);		//输入想要录入成绩的学号
		for(int i = 0;i < n; i++){
			if((stu[i].is_study == 1 || stu[i].is_study == 2)&& strcmp(want_add_ach_id,stu[i].stu_id) == 0){	//判断该学号是否在读或离校
				if(stu[i].is_study == 1){
					if(stu[i].has_ach == 1){				//判断该在校生是否已有成绩
						printf("该学号已有成绩\n");
						break;
					}else{
						printf("请输入语文成绩：");
						scanf("%d",&stu[i].ach_chi);
						printf("请输入数学成绩：");
						scanf("%d",&stu[i].ach_mat);
						printf("请输入英语成绩：");
						scanf("%d",&stu[i].ach_eng);
						stu[i].ach_sco = stu[i].ach_chi + stu[i].ach_mat + stu[i].ach_eng;
						stu[i].ach_avg = stu[i].ach_sco / 3.0;
						printf("录入成绩成功\n");
						stu[i].has_ach = 1;
						break;
					}
				}else if(stu[i].is_study == 2){				//该学生为退学学生
					printf("该学生已退学");
				} 
			}else if(i == n - 1){
				printf("不存在该学号\n");
			}	
		}
	}
//批量导入成绩
//***************************************************
	else if(add_pat == 2){
		int flag = 0;
		int i = stu_num_cur;                   //ｉ为当前学生数
		char fname[20];
		printf("请输入想要导入的文件：\n");
		scanf("%s",fname);
		FILE *frp_ach = fopen(fname,"r");
		if(NULL == frp_ach)					  //判断该文件是否存在
		{
			perror("fopen");
			sleep(1);
			return;
		}
		while(i < add_ach + stu_num_cur ){							//根据add_ach导入成绩
		 	fscanf(frp_ach,"%d %d %d %d\n",&stu[i].ach_chi,&stu[i].ach_mat,&stu[i].ach_eng,&stu[i].has_ach);
			stu[i].ach_sco = stu[i].ach_chi + stu[i].ach_mat + stu[i].ach_eng;
			stu[i].ach_avg = stu[i].ach_sco / 3.0;
			i++;
		}
		fclose(frp_ach);
		flag = i - stu_num_cur;			//flag为导入成绩之前的学生人数与导入成绩之后的学生人数之差，即已有成绩的学生增长量
		stu_num_cur = i;
		printf("成功导入%d个学生信息\n",flag);
	}
	sleep(1);
}

//修改学生成绩模块
//***************************************************
void mod_stu_ach(){
	int sub_flag = 0;
	char want_mod_ach_id[20];
	int n = stu_num;
	printf("请输入想要修改成绩的学号");
	scanf("%s",want_mod_ach_id);		//输入想要修改的成绩学号
	for(int i = 0;i < n;i++){			
		if((stu[i].is_study == 1 || stu[i].is_study == 2) && stu[i].has_ach == 1 && strcmp(want_mod_ach_id,stu[i].stu_id) == 0){//判断该学号是否有成绩或者是否在读或者退学
			printf("请输入想修改的成绩(1.语文2.数学3.英语)：");
			while(1){												//输入想修改的成绩
				scanf("%d",&sub_flag);
				if(sub_flag == 1 || sub_flag == 2 || sub_flag == 3)
					break;
				printf("输入有误，请重新输入");
			}
			if(sub_flag == 1){
				printf("请输入修改后的语文成绩：");
				scanf("%d",&stu[i].ach_chi);
			}else if(sub_flag == 2){
				printf("请输入修改后的数学成绩：");
				scanf("%d",&stu[i].ach_mat);
			}else if(sub_flag == 3){
				printf("请输入修改后的英语成绩：");
				scanf("%d",&stu[i].ach_eng);	
			}
			printf("修改完成\n");
			stu[i].ach_sco = stu[i].ach_chi + stu[i].ach_mat + stu[i].ach_eng;       //修改后的总分修改
			stu[i].ach_avg = stu[i].ach_sco / 3.0;									 //修改后的平均分修改
			break;
		}else if(stu[i].is_study != 1 && stu[i].is_study != 2 && stu[i].has_ach == 0 && strcmp(want_mod_ach_id,stu[i].stu_id)){
			printf("该学生还没有录入成绩，无法修改");
		}
	}
	if(n == 0){
		printf("不存在该学号");
	}
	sleep(1);
}

//查找成绩模块
//***************************************************
void sea_ach(){
	int have_stu = 0;
	int n = stu_num;
	char want_sea_ach[20];
	printf("请输入学号或姓名查询成绩");
	scanf("%s",want_sea_ach);       //输入想查找的名字或者学号
	for(int i = 0;i < n;i++){
		if(strcmp(want_sea_ach,stu[i].stu_id) == 0 || strcmp(want_sea_ach,stu[i].name) == 0){	//判断是否存在该学号或者姓名
			printf("学号     姓名   语文   数学   英语   总分   平均分\n");
			printf("%-5s   %5s   %-2d     %-2d     %-2d     %-2d   %-2.2lf\n",stu[i].stu_id,stu[i].name,stu[i].ach_chi,stu[i].ach_mat,stu[i].ach_eng,stu[i].ach_sco,stu[i].ach_avg);
			have_stu = 1;
		}else if(i == n - 1 && have_stu == 0){
			printf("查无此人\n");
		}
	}
	if(n == 0){
		printf("查无此人\n");
	}
	printf("* * * * * 按1键返回 * * * * *\n");
	while(1){
		if(getch() == '1')
			break;
	}
}

//成绩排名模块
//***************************************************
void ach_sort(){
	int flag = 0;
	int n = stu_num;
	int ach_num[500] = {};
	int want_sort_sub = 0;
	printf("请输入要排序的科目（１.语文 ２.数学 3.英语 4.总分）：");
	scanf("%d",&want_sort_sub);						//输入想要的科目排名
	for(int i = 0;i < n;i++){
		stu[i].is_display = 0;
	}

//语文排序
//***************************************************
	if(want_sort_sub == 1){
		for(int i = 0;i < n; i++){					//把每个学生成绩拿出来放在一个数组中
			ach_num[i] = stu[i].ach_chi;	
		}
		for(int j = 0;j < n - 1;j++){				//用冒泡排序法，让数组内的成绩依次从大到小排列
			for(int i = 0;i < n - 1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i + 1] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){					//拿数组的每一位数来跟学生的成绩比较，该数所在的数组位置，即使学生的排名成绩－１；
			for(int j = 0;j < n;j++){
				if(stu[i].ach_chi == ach_num[j]){
					stu[i].chi_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   语文成绩   排名\n");
		for(int i = 0 ;i < n;i++){
			for(int j = 0; j < n;j++){
				if(ach_num[i] == stu[j].ach_chi && stu[j].is_display == 0 && stu[j].is_study == 1){			//依次从大到小按照降序打印出在读生的成绩
					printf("%-5s   %-5s    %-2d       %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_chi,stu[j].chi_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
		printf("排序成功！\n");

//数学排序
//***************************************************
	}else if(want_sort_sub == 2){
		for(int i = 0;i < n; i++){
			ach_num[i] = stu[i].ach_mat;
		}
		for(int j = 0;j < n -1;j++){
			for(int i = 0;i < n - 1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i + 1] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(stu[i].ach_mat == ach_num[j]){
					stu[i].mat_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   数学成绩   排名\n");
		for(int i = 0 ;i < n;i++){
			for(int j = 0; j < n;j++){
				if(ach_num[i] == stu[j].ach_mat && stu[j].is_display == 0 && stu[j].is_study == 1){
					printf("%-5s   %-5s    %-2d       %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_mat,stu[j].mat_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
	printf("排序成功！\n");

//英语排序
//***************************************************
	}else if(want_sort_sub == 3){
		for(int i = 0;i < n; i++){
			ach_num[i] = stu[i].ach_eng;
		}
		for(int j = 0;j < n - 1;j++){
			for(int i = 0;i < n - 1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i + 1] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(stu[i].ach_eng == ach_num[j]){
					stu[i].eng_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   英语成绩   排名\n");
		for(int i = 0 ;i < n;i++){
			for(int j = 0; j < n;j++){
				if(ach_num[i] == stu[j].ach_eng && stu[j].is_display == 0 && stu[j].is_study == 1){
					printf("%-5s   %-5s    %d       %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_eng,stu[j].eng_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
		printf("排序成功！\n");

//总分排序
//***************************************************
	}else if(want_sort_sub == 4){
		for(int i = 0;i < n; i++){
			ach_num[i] = stu[i].ach_sco;
		}
		for(int j = 0;j < n - 1;j++){
			for(int i = 0;i < n -1;i++){
				if(ach_num[i] < ach_num[i + 1]){
					flag = ach_num[i + 1];
					ach_num[i +1 ] = ach_num[i];
					ach_num[i] = flag;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(stu[i].ach_sco == ach_num[j]){
					stu[i].sco_rank = j + 1;
					break;
				}
			}
		}
		printf("学号     姓名   总成绩   平均分   排名\n");
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(ach_num[i] == stu[j].ach_sco &&stu[j].is_display == 0 && stu[j].is_study == 1){
					printf("%-5s   %-5s    %d    %-2.2lf      %-2d\n",stu[j].stu_id,stu[j].name,stu[j].ach_sco,stu[j].ach_avg,stu[j].sco_rank);
					stu[j].is_display = 1;
					break;
				}
			}
		}
		printf("排序成功!\n");
	}
	printf("* * * * * 输１键返回 * * * * *");
	while(1){
		if(getch() == '1')
			break;
	}
}
