#include <stdio.h>
#include <getch.h>
#include <unistd.h>
/*int main(){

	char *a = getpass("input a password:");
	printf("The password is:%s\r\n",a);
}*/
int main(){
	char id[20] = "stu01";
	char name[20] = "林德龙";
	int yuwen = 98;
	int shuxue = 89;
	int yingyu = 86;
	double zongfen = 89.93;
	printf("学号     姓名   语文   数学   英语   总分\n");
	printf("%-5s   %-5s   %-2d     %-2d     %-2d   %-2.2lf",id,name,yuwen,shuxue,yingyu,zongfen);
}
