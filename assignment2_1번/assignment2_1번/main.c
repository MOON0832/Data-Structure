#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct { // 값이 저장된 행,열과 값 자체를 저장할 수 있는 구조체 element를 선언한다. 
	int row; // 값이 저장된 열의 위치
	int col; // 값이 저장된 행의 위치
	int value; // 저장된 값
}element;

typedef struct SparseMatrix{ // 0이 아닌 값의 개수, 전체 matrix의 행과 열의 크기값를 저장할 수 있는 SparseMatrix라는 이름의 구조체를 선언한다.  
	element data[MAX_TERMS];
	int rows; // matrix의 열 개수
	int cols; //matrix의 행 개수
	int terms; // 0이 아닌 값의 개수
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a){ // matrix를 transpose 시켜주는 함수 
	SparseMatrix b; // Sparsematrix 형 변수 b를 선언한다. b에는 matrix a가 transpose되어서 저장된다. 
	int bindex; // b의 data에 순차적으로 접근하기 위한 변수 index b를 선언한다. 
	int c;  //c와 i는 for문을 위한 변수이다. 
	int i; 
	b.rows = a.cols;  // a의 열과 행의 크기를 바꿔서 b의 열과 행 크기로 설정해준다. 
	b.cols = a.rows;
	b.terms = a.terms; // 값을 가진 개수는 같으므로 a의 값을 가진 항의 개수를 b에 대입해준다. 

	if(a.terms>0){ 
	bindex = 0;
	
	for (c = 0; c<a.cols;c++){
		for(i = 0; i<a.terms; i++){
			if(a.data[i].col ==c){
				b.data[bindex].row = a.data[i].col; // a의 열과 행의 값을 바꿔서 b의 열과 행의 값으로 설정해준다.(transpose해준다.) 
				b.data[bindex].col = a.data[i].row;
				b.data[bindex].value = a.data[i].value;
				bindex++; //순차적으로 접근하기 위해 값을 저장한 뒤 bindex의 값을 하나씩 증가시킨다. 
			}
		}
	
	
	}
	
	
	}
	return b; //transpose된 matrix를 반환해준다. 

}

void matrix_print(SparseMatrix a){ //matrix를 출력하기 위한 함수이다. 
	int k =0; //k는 matrix에서 0이 아닌 값을 출력하기 위한 data의 index에 접근하기 위한 변수이다. 
	int i; //i,j는 for문을 돌리기 위한 변수이다. 
	int j;

	for(i=0;i<a.rows;i++){ 
		for(j=0;j<a.cols;j++){
			if(a.data[k].row == i && a.data[k].col ==j){ //0이 아닌 값을 출력한다. 
				printf("%d",a.data[k].value);
				k++; //0이 아닌 값을 출력한 뒤에는 data의 다음 index로 넘어가야하므로,k의 값을 증가시켜준다. 
			}
			else{
			printf("0");} //data에 저장되지 않는 행과 열일 경우에는 0이라는 의미이므로, 0을 출력해준다. 
		}
	printf("\n");
	
	}

	


}

int main(void){
	SparseMatrix m = { //sparse matrix 형식의 m을 선언하고, 형식에 맞게 값을 저장해준다. 
	
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7
	
	
	};
	SparseMatrix result; //결과값(m이 transpose됨) 을 저장하기 위한 sparse matrix result를 선언해준다. 
	matrix_print(m);
	printf("\n");
	result = matrix_transpose2(m); //result에는 m이 transpose되어 저장된다. 
	matrix_print(result); // result matrix를 앞서 선언한 matrix_print함수를 이용하여 프린트해준다. 
	return 0;




}