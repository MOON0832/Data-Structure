#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct { // ���� ����� ��,���� �� ��ü�� ������ �� �ִ� ����ü element�� �����Ѵ�. 
	int row; // ���� ����� ���� ��ġ
	int col; // ���� ����� ���� ��ġ
	int value; // ����� ��
}element;

typedef struct SparseMatrix{ // 0�� �ƴ� ���� ����, ��ü matrix�� ��� ���� ũ�Ⱚ�� ������ �� �ִ� SparseMatrix��� �̸��� ����ü�� �����Ѵ�.  
	element data[MAX_TERMS];
	int rows; // matrix�� �� ����
	int cols; //matrix�� �� ����
	int terms; // 0�� �ƴ� ���� ����
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a){ // matrix�� transpose �����ִ� �Լ� 
	SparseMatrix b; // Sparsematrix �� ���� b�� �����Ѵ�. b���� matrix a�� transpose�Ǿ ����ȴ�. 
	int bindex; // b�� data�� ���������� �����ϱ� ���� ���� index b�� �����Ѵ�. 
	int c;  //c�� i�� for���� ���� �����̴�. 
	int i; 
	b.rows = a.cols;  // a�� ���� ���� ũ�⸦ �ٲ㼭 b�� ���� �� ũ��� �������ش�. 
	b.cols = a.rows;
	b.terms = a.terms; // ���� ���� ������ �����Ƿ� a�� ���� ���� ���� ������ b�� �������ش�. 

	if(a.terms>0){ 
	bindex = 0;
	
	for (c = 0; c<a.cols;c++){
		for(i = 0; i<a.terms; i++){
			if(a.data[i].col ==c){
				b.data[bindex].row = a.data[i].col; // a�� ���� ���� ���� �ٲ㼭 b�� ���� ���� ������ �������ش�.(transpose���ش�.) 
				b.data[bindex].col = a.data[i].row;
				b.data[bindex].value = a.data[i].value;
				bindex++; //���������� �����ϱ� ���� ���� ������ �� bindex�� ���� �ϳ��� ������Ų��. 
			}
		}
	
	
	}
	
	
	}
	return b; //transpose�� matrix�� ��ȯ���ش�. 

}

void matrix_print(SparseMatrix a){ //matrix�� ����ϱ� ���� �Լ��̴�. 
	int k =0; //k�� matrix���� 0�� �ƴ� ���� ����ϱ� ���� data�� index�� �����ϱ� ���� �����̴�. 
	int i; //i,j�� for���� ������ ���� �����̴�. 
	int j;

	for(i=0;i<a.rows;i++){ 
		for(j=0;j<a.cols;j++){
			if(a.data[k].row == i && a.data[k].col ==j){ //0�� �ƴ� ���� ����Ѵ�. 
				printf("%d",a.data[k].value);
				k++; //0�� �ƴ� ���� ����� �ڿ��� data�� ���� index�� �Ѿ���ϹǷ�,k�� ���� ���������ش�. 
			}
			else{
			printf("0");} //data�� ������� �ʴ� ��� ���� ��쿡�� 0�̶�� �ǹ��̹Ƿ�, 0�� ������ش�. 
		}
	printf("\n");
	
	}

	


}

int main(void){
	SparseMatrix m = { //sparse matrix ������ m�� �����ϰ�, ���Ŀ� �°� ���� �������ش�. 
	
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7
	
	
	};
	SparseMatrix result; //�����(m�� transpose��) �� �����ϱ� ���� sparse matrix result�� �������ش�. 
	matrix_print(m);
	printf("\n");
	result = matrix_transpose2(m); //result���� m�� transpose�Ǿ� ����ȴ�. 
	matrix_print(result); // result matrix�� �ռ� ������ matrix_print�Լ��� �̿��Ͽ� ����Ʈ���ش�. 
	return 0;




}