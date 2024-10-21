#include<stdio.h>

//제곱근과 거듭제곱을 쉽게할수있도록 
//해주는 함수가 있는 파일이다
//당연히 사용가능한걸로 알고 사용하겠음
#include<math.h> 


//포인터객체
typedef struct{
    int x;
    int y;
}Point;


//거리구하기
int d(Point x, Point y){
    return sqrt(pow(x.x - y.x,2) + pow(x.y - y.y,2));
    //sqrt는 제곱근을 구하는함수 
    //pow는 n제곱 구하는 함수 
}

//삼각형조건확인하기
const char* last(int a,int b,int c){
    return (a+b)>c ? "true" : "false";
}

int main(){
    Point a,b,c;

    scanf("%d %d",&a.x ,&a.y);
    scanf("%d %d",&b.x ,&b.y);
    scanf("%d %d",&c.x ,&c.y);

    int d1,d2,d3;
    d1 = d(a,b);
    d2 = d(a,c);
    d3 = d(c,b); 

    printf("%s",last(d1,d2,d3));

    return 0;
}