# 1971043 정문정

#1번 readme

purpose of this code: sparse형식의 matrix를 transpose시켜서, dense 형식의 matrix를 프린트하기 위한 코드이다. (transpose되기 전의 matrix도 dense형식으로 print해준다.)

사용된 구조체:
element: 값이 저장된 행,열과 값 자체를 저장할 수 있는 구조체
SparseMatrix: 0이 아닌 값의 개수, 전체 matrix의 행과 열의 크기값를 저장할 수 있는 구조체

사용된 함수:
SparseMatrix matrix_transpose2(SparseMatrix a) // matrix를 transpose 시켜주는 함수
parameter: SparseMatrix a (transpose시키고자 하는 matrix를 parameter 값으로 받아온다.)
변수 : int bindex; // b의 data에 순차적으로 접근하기 위한 변수 index b를 선언한다. 
         int c,i;  //c와 i는 for문을 위한 변수이다. 
return값: transpose된 matrix(b)

void matrix_print(SparseMatrix a) //matrix를 출력하기 위한 함수
parameter: SparseMatrix a (print하고자 하는 matrix를 parameter 값으로 받아온다.)
변수: int k =0; //k는 matrix에서 0이 아닌 값을 출력하기 위한 data의 index에 접근하기 위한 변수이다. 
        int i,j; //i,j는 for문을 돌리기 위한 변수이다. 
return값 : x( void형 함수)



#2번 readme

purpose of this code: 삼차원 배열을 동적할당해주고, 두개의 삼차원 배열을 더해 그 값을 출력한뒤, 할당되었던 삼차원 배열을 다시 해제해준다. 

사용된 함수:
double ***mem_alloc_3D_double(int width,int length,int height) // 삼차원 배열(삼중포인터)을 동적할당해주는 함수 
parameters: 할당할 삼차원 배열의 넓이, 높이, 너비를 각각 int형으로 받아온다. 
변수: double ***data; // 메모리가 동적할당될 삼중 포인터 변수 data
        int i,j; //for문을 위한 변수 
return값: 할당된 삼중포인터 data를 return한다.

int memoryRelease(double*** data,int width,int length,int height) // 동적할당된 메모리를 해제해주는 함수
parameters: 해제할 삼차원 배열의 넓이, 높이, 너비를 각각 int형으로 받아온다. 
변수: int i,j; //for문을 위한 변수

void addition_3D(double*** a, double*** b) // 2개의 삼차원 배열 덧셈을 해주는 함수
parameter: 덧셈을 할 두개의 삼중 포인터를 받아온다. 
변수: double data; //a,b배열의 값을 더해서 저장할 변수 
        int i,j,k; //for loop를 돌리는데 필요한 정수변수 





       	
