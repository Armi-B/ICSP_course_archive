#include <stdio.h>

int main()
{
    int a,b,c,marz_chap,marz_rast;
    double step,i,meghdar_moadele,x1=0,x2=0,x3=0;
    scanf("%d\n%d\n%d\n%lf",&a,&b,&c,&step);
    /*bar asas bozorgtarin zarib moadele baze pasokh ra taeen mikonim*/
    if (a>=b&&a>=c)
    {
        marz_chap=a*a*(-1);
        marz_rast=a*a;
    }
    if(c>=a&&c>=b)
    {
        marz_chap=c*c*(-1);
        marz_rast=c*c;
    }
    if (b>=c&&b>=a)
    {
        marz_chap=b*b*(-1);
        marz_rast=b*b;
    }
    /*ba tavajoh be sorat soal pasokh ha dar baze iee bain mar_chap va marz_rast hastand*/
    i=marz_chap;
    /*baray gerftan pasokh behtar khatahay kochektar az 1 behtarand*/
    if (step>=1)
    {
      step=0.000001;
    }
    
    while(i<marz_rast)
    /*az marz_chap shoro mikonim va ba khatay taeen shode adadi ra ke dar moadele emthan mikonim afzayesh midahim*/
    {
      i+=step;
      meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
      /*az khat 32 ta 96 barname faghat baray halat khas va kam ehtmal deghat barname ra afzayesh midahad*/
          if (meghdar_moadele==0)
          /*agar meghdar_moadele barabar 0 shavad i rishe moadele ast*/
          {
               x1=i;
               i+=step;
               if(meghdar_moadele<0)
               /*x1 rishe mozaf moadele bode pas tanha yek rishe digar baghist*/
                  {while(i<marz_rast){
                    i+=step;
                    meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                    if(meghdar_moadele>0)
                       {i-=step;
                       x2=i;
                       break;}
                    if(meghdar_moadele==0)
                       {x2=i;
                       break;}
                   }}

                if(meghdar_moadele>0)
                /*x1 ya rishe adi ast ya rishe ba 3 bar tekrar*/
                   {while (i<marz_rast){  
                     i+=step;
                     meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                     if((meghdar_moadele<0))
                     /*x1 va x2 rishe mozaf nistand va x3 vojod darad*/
                     {
                       while(i<marz_rast)
                       {
                         i+=step;
                         meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                         if((meghdar_moadele>0))
                         {
                           i-=step;
                           x3=i;
                           i+=step;
                           break;
                         }
                       }
                     }
                     if(meghdar_moadele==0)
                     { x2=i;
                       i+=step;
                       meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                       if(meghdar_moadele<0)
                       /*x1 va x2 rishe mozaf nistand va x3 vojod darad*/
                         {
                           while(i<marz_rast)
                           {i+=step;
                            meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                            if(meghdar_moadele>0)
                            {
                             i-=step;
                             x3=i;
                             i+=step;
                             break;
                            }
                           }
                          }
                        if(meghdar_moadele>0)
                         /*x1 rishe adi va x2 rishe mozaaf bode pas x3 mojod nist*/
                         {break;}}
                          }}
            break;
          }
          
          
          if((meghdar_moadele>0))
          /*ba tavajoh be form moadele pish az avalin rishe meghdar moadele manfi ast va tanha bad az avalin rishe mitavanad mosbat shavad*/
          {
            i-=step;
            x1=i;
            i+=step;
            while (i<marz_rast)
            {  
               i+=step;
               meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
               if((meghdar_moadele<0))
               /*x1 va x2 rishe mojod va darje aval moadele hastand pas x3 niz vojod darad*/
               {
                 i-=step;
                 x2=i;
                 i+=step;
                 while(i<marz_rast)
                 {
                  i+=step;
                  meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                  if((meghdar_moadele>0))
                  {
                   i-=step;
                    x3=i;
                    i+=step;
                    break;
                  }
                 }
                 break;
                }
              if(meghdar_moadele==0)
                     { x2=i;
                       i+=step;
                       meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                       if(meghdar_moadele<0)
                       /*x1 va x2 rishe mozaf nistand va x3 vojod darad*/
                         {
                           while(i<marz_rast)
                           {i+=step;
                            meghdar_moadele=(double) ((i*i*i)+a*(i*i)+b*(i)+c);
                            if(meghdar_moadele>0)
                            {
                             i-=step;
                             x3=i;
                             i+=step;
                             break;
                            }
                           }
                          }
                        if(meghdar_moadele>0)
                         /*x1 rishe adi va x2 rishe mozaaf bode pas x3 mojod nist*/
                         {break;}}
            }
            break;
          }
    }
    /*agar har yek az rishe ha hanoz 0 motlagh bashad yani meghdari baray an vojod nadashte*/
    if(x2==0&&x3==0)
    {printf("%lf\nbedoon rishe\nbedoon rishe",x1);}
    if(x2!=0&&x3!=0)
    {printf("%lf\n%lf\n%lf",x1,x2,x3);}
    if(x3==0&&x2!=0)
    {printf("%lf\n%lf\nbedoon rishe",x1,x2);}
return 0;
}