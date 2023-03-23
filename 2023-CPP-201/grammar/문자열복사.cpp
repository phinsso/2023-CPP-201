#include<stdio.h>
#include<string.h>

int main(void) {

	char str[30] = { 0 }; //문자는 29개 들어감 (null값 1개)
	char str2[30] = "c_insert";

	strcpy(str, str2); //str에다가 str2에 있는 문자열을 복사하여 넣겠다는 뜻

	printf("%s \n",str);
	printf("%s \n", str2);

	return 0;
}