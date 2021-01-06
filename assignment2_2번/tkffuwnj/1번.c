#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix{
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a){
	SparseMatrix b;
	int bindex;
	int c;
	int i;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if(a.terms>0){
	bindex = 0;
	
	for (c = 0; c<a.cols;c++){
		for(i = 0; i<a.terms; i++){
			if(a.data[i].col ==c){
				b.data[bindex].row = a.data[i].col;
				b.data[bindex].col = a.data[i].row;
				b.data[bindex].value = a.data[i].value;
				bindex++;
			}
		}
	
	
	}
	
	
	}
	return b;

}

void matrix_print(SparseMatrix a){
	int k =0;
	int i;
	int j;

	for(i=0;i<a.rows;i++){
		for(j=0;j<a.cols;j++){
			if(a.data[k].row == i && a.data[k].col ==j){
				printf("%d",a.data[k].value);
				k++;
			}
			else{
			printf("0");}
		}
	printf("\n");
	
	}

	


}

int main(void){
	SparseMatrix m = { 
	
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7
	
	
	};
	SparseMatrix result;
	matrix_print(m);
	printf("\n");
	result = matrix_transpose2(m);
	matrix_print(result);
	return 0;




}