#include <stdio.h>
#define cal_rozane 100

int main()
{
    int food_type,n,i,cal_daryaft=0,cal_masraf,tafavot_cal;
    /*get number of days we want to check*/
    scanf("%d",&n);
    /*calculate daily calorie limit*/
    cal_masraf=n*cal_rozane;
    /*get n numbers of food and add thier calories to the calories received*/
    for(i=0;i<n;i++)
    {
        scanf("%d",&food_type);
        switch(food_type)
        {
            case 1:
             cal_daryaft+=329;
            break;
            case 2:
             cal_daryaft+=127;
            break;
            case 3:
             cal_daryaft+=61;
            break;
            case 4:
             cal_daryaft+=83;
            break;
            case 5:
             cal_daryaft+=156;
            break;
            case 6:
             cal_daryaft+=296;
            break;
            case 7:
             cal_daryaft+=496;
            break;
            case 8:
             cal_daryaft+=73;
            break;
            case 9:
             cal_daryaft+=34;
            break;
            case 10:
             cal_daryaft+=16;
            break;
            default:
            cal_daryaft+=0;
            break;
        }
    }
    /*determine the meaning of net calories number and show result to user*/
    if (cal_daryaft>cal_masraf)
    {printf("chagh");}
    if (cal_daryaft<cal_masraf)
    {printf("laghar");}
    if(cal_daryaft==cal_masraf)
    {printf("bedoon taghir");}
    return 0;    
}