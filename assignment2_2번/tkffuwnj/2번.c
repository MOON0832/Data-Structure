#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

double ***mem_alloc_3D_double(int width,int length,int height){ // ������ �迭(����������)�� �����Ҵ����ִ� �Լ� 

	double ***data; // �޸𸮰� �����Ҵ�� ���� ������ ���� data
	int i,j; //for���� ���� ���� 
	data = (double***)malloc(sizeof(double**)*height); //����(����)��ŭ �޸� ������ �Ҵ��Ѵ�.
	for(i=0;i<height;i++){
		data[i] = (double**)malloc(sizeof(double*)*length); // ����(����)��ŭ �޸� ������ �Ҵ��Ѵ�. 
		for(j=0;j<length;j++){
		data[i][j] = (double*)malloc(sizeof(double)*width); // �ʺ�ŭ �޸� ������ �Ҵ��Ѵ�. 
		}
	
	}


return data; // �Ҵ�� ���������� data�� return�Ѵ�. 


}

int memoryRelease(double*** data,int width,int length,int height){ // �����Ҵ�� �޸𸮸� �������ִ� �Լ�
int i,j; //for���� ���� ����
printf("�����Ҵ�Ǿ��� �޸𸮰� �����˴ϴ�.\n");
for(i=0;i<height;i++){  // ���� for���� ������ ������ �迭�� �������ش�. 

	for(j=0;j<length;j++){ 
		
		free(data[i][j]);
	
	}

}

for(i=0;i<width;i++){ //������ �迭�� ��� �������ش�. 
free(data[i]);
}
free(data);
return 0;


}


void addition_3D(double*** a, double*** b){ // 2���� ������ �迭 ������ ���ִ� �Լ�
	double data; //a,b�迭�� ���� ���ؼ� ������ ���� 
	int i,j,k; //for loop�� �����µ� �ʿ��� �������� 
	for(i=0;i<3;i++){ //���� for���� ������ ������ �迭�� ����� ���� �ϳ��� �����Ѵ�. 
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
			data = a[i][j][k]+b[i][j][k];//�� ���� ������ �迭�� ������ ���ҿ� �����Ͽ� �� ���� ���Ͽ� data������ �����Ѵ�. 
			printf("%.2f\t",data); // data�� ����� ��(�� ������ �迭�� ������ ��)�� print�Ѵ�. 

			}
			printf("\n");
		}
		printf("\n");
	}



}




int main(){
	int i,j,k,cnt; // i,j,k�� for loop�� ������ �ʿ��� ����, cnt�� ������ �迭�� ������ ���� �־��ֱ� ���� �ʿ��� �����̴�. 
	double ***data = mem_alloc_3D_double(3,3,3); // data��� �̸��� 3*3*3ũ���� ������ �迭�� mem_alloc_3D_double�Լ��� �̿��� �Ҵ����ش�.
	double ***data1=mem_alloc_3D_double(3,3,3); //data1�̶�� �̸��� 3*3*3ũ���� ������ �迭�� mem_alloc_3D_double�Լ��� �̿��� �Ҵ����ش�.
	cnt =1; // ������ �迭�� ������ ���� �������ֱ� ���� cnt�� 1�� �������ش�. 
	printf("data\n");
	for(i=0;i<3;i++){  // ���� for���� ���鼭 ������ �迭 data�� ������ ��(1�� �����ϴ� ��)�� �������ش�. 
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
	for(i=0;i<3;i++){ // ���� for���� ���鼭 ������ �迭 data1�� ������ ��(1�� �����ϴ� ��)�� �������ش�. 
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
	addition_3D(data,data1);  //addition_3D�Լ��� �̿��Ͽ�, data�� data1�� �ִ� ���ҵ鳢�� �����ְ�, �� ���� print���ش�. 
	memoryRelease(data,3,3,3); // �����Ҵ� �Ǿ��� �迭�� �������ش�. 
	memoryRelease(data1,3,3,3);	
	
	

}