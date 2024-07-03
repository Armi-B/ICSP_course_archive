#include <stdio.h>
#define half 0.5
#define floor_height 2
#define hundred 100

int main()
{
    int room_sign,room_num,floor,area,num_jump=0;
    double f_jump_h,slop_jump_h,height;
    /*get inputs from user*/
    scanf("%d\n%lf",&room_sign,&f_jump_h);
    /*devide room number from room sign*/
    room_num = room_sign% hundred;
    /*calculate the appropriate area for placing trampoline*/
    if ((room_num>=1)&&(room_num<=4))
      {area=1;}
    else if((room_num>=5)&&(room_num<=8))
      {area=2;}
    else if((room_num>=9)&&(room_num<=12))
      {area=3;}
    else if((room_num>=13)&&(room_num<=16))
      {area=4;}
    else{}
    /*calculate room floor from room sign*/
    floor= room_sign/hundred;
    /*calculate the increments of the jump*/
    slop_jump_h =f_jump_h*half;
    /*calculate the required jump height*/
    height= (floor*floor_height)+1;
    /*calculate the number of jumps*/
    double i= f_jump_h;
    while((height-i>0.0000001))
    {
        i+=slop_jump_h;
        num_jump++;
    }
    /*show results to user*/
    printf("%d\n%d",area,num_jump);
    return 0;
}