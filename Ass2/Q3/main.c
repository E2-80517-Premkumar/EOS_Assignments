//3. Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). 
//Compile the program using "gcc" and execute it. No fork(), exec() expected
//here.

#include"fun.h"

int main(void)
{
    float r1,r2,r3;
    r1=area_circle();
    r2=area_rect();
    r3=area_square();

    printf("area circle = %f\narea rect = %f\narea square = %f\n",r1,r2,r3);

    return 0;

}