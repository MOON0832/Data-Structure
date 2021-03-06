#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

double ***mem_alloc_3D_double(int width,int length,int height){ // 삼차원 배열(삼중포인터)을 동적할당해주는 함수 

	double ***data; // 메모리가 동적할당될 삼중 포인터 변수 data
	int i,j; //for문을 위한 변수 
	data = (double***)malloc(sizeof(double**)*height); //높이(세로)만큼 메모리 공간을 할당한다.
	for(i=0;i<height;i++){
		data[i] = (double**)malloc(sizeof(double*)*length); // 길이(가로)만큼 메모리 공간을 할당한다. 
		for(j=0;j<length;j++){
		data[i][j] = (double*)malloc(sizeof(double)*width); // 너비만큼 메모리 공간을 할당한다. 
		}
	
	}


return data; // 할당된 삼중포인터 data를 return한다. 


}

int memoryRelease(double*** data,int width,int length,int height){ // 동적할당된 메모리를 해제해주는 함수
int i,j; //for문을 위한 변수
printf("동적할당되었던 메모리가 해제됩니다.\n");
for(i=0;i<height;i++){  // 이중 for문을 돌려서 이차원 배열을 해제해준다. 

	for(j=0;j<length;j++){ 
		
		free(data[i][j]);
	
	}

}

for(i=0;i<width;i++){ //삼차원 배열을 모두 해제해준다. 
free(data[i]);
}
free(data);
return 0;


}


void addition_3D(double*** a, double*** b){ // 2개의 삼차원 배열 덧셈을 해주는 함수
	double data; //a,b배열의 값을 더해서 저장할 변수 
	int i,j,k; //for loop를 돌리는데 필요한 정수변수 
	for(i=0;i<3;i++){ //삼중 for문을 돌려서 삼차원 배열에 저장된 값에 하나씩 접근한다. 
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
			data = a[i][j][k]+b[i][j][k];//두 개의 삼차원 배열의 각각의 원소에 접근하여 그 값을 더하여 data변수에 저장한다. 
			printf("%.2f\t",data); // data에 저장된 값(두 삼차원 배열의 원소의 합)을 print한다. 

			}
			printf("\n");
		}
		printf("\n");
	}



}




int main(){
	int i,j,k,cnt; // i,j,k는 for loop를 돌릴때 필요한 변수, cnt는 삼차원 배열에 임의의 값을 넣어주기 위해 필요한 변수이다. 
	double ***data = mem_alloc_3D_double(3,3,3); // data라는 이름의 3*3*3크기의 삼차원 배열을 mem_alloc_3D_double함수를 이용해 할당해준다.
	double ***data1=mem_alloc_3D_double(3,3,3); //data1이라는 이름의 3*3*3크기의 삼차원 배열을 mem_alloc_3D_double함수를 이용해 할당해준다.
	cnt =1; // 삼차원 배열에 임의의 수를 대입해주기 위해 cnt를 1로 설정해준다. 
	printf("data\n");
	for(i=0;i<3;i++){  // 삼중 for문을 돌면서 삼차원 배열 data에 임의의 수(1씩 증가하는 수)를 대입해준다. 
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				data[i][j][k] = cnt;
				printf("%.2f\t",data[i][j][k]);
				cnt++;
							
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("\n");

	printf("data1\n");
	for(i=0;i<3;i++){ // 삼중 for문을 돌면서 삼차원 배열 data1에 임의의 수(1씩 증가하는 수)를 대입해준다. 
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				data1[i][j][k] = cnt;
				printf("%.2f\t",data1[i][j][k]);
				cnt++;
							
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("\n");

	printf("addition\n");
	addition_3D(data,data1);  //addition_3D함수를 이용하여, data와 data1에 있는 원소들끼리 더해주고, 그 값을 print해준다. 
	memoryRelease(data,3,3,3); // 동적할당 되었던 배열을 해제해준다. 
	memoryRelease(data1,3,3,3);	
	
	

}