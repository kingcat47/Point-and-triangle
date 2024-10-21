#include<stdio.h>
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

//삼각형조건확인하기(거리)
int last1(int a,int b,int c){
    //a<=b<=c 맞춰주기

    // 세 변 중 가장 큰 값 찾기
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    // 세 변 중 가장 작은 값 찾기
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    // 중간 값 찾기
    int mid = a + b + c - max - min;

    return (min+mid)>max ? 1 : 0;
}

//삼각형조건확인하기(기울기)
double last2(Point x, Point y){
    //나누는 값이 0이면 오류날수 있어서추가
    //무한대를 안배워서 모르겠는데 검색해보니 무한대로 표현한다길래 INFINITY넣음
    if(x.x == y.x){
        return INFINITY;
    }

    return (double)(x.y - y.y) / (x.x - y.x);
}


int main(){
    Point a,b,c;

    scanf("%d %d",&a.x ,&a.y);
    scanf("%d %d",&b.x ,&b.y);
    scanf("%d %d",&c.x ,&c.y);

    //거리
    int d1,d2,d3;
    d1 = d(a,b);
    d2 = d(a,c);
    d3 = d(c,b); 

    //기울기
    double m1,m2,m3;
    m1 = last2(a,b);
    m2 = last2(a,c);
    m3 = last2(c,b);

    int check1 = last1(d1,d2,d3); // 거리
    int check2; // 기울기

    if((m1 == m2) && (m2 == m3)){
        check2 = 0;
    }
    else{
        check2 = 1;
    }

    //check 2개가 모두 참이면 true 출력
    if ((check1 == 1) && (check2 == 1)  ) {
        printf("true");
    }
    //아니라면 false 출력
    else {
        printf("false");
    }

    return 0;
}
