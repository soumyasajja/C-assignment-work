#include <iostream>
using namespace std;
class Time{
               int hours,min,sec;
 public:        Time()
                  {
                     hours=0;
                     min=0;
                     sec=0;
                    }
         Time(int h,int m,int s)
                  {
                     hours=h;
                     min=m;
                     sec=s;
                   }
        void display()
         {
                cout<<"the current time is"<<hours<<':'<<min<<':'<<sec;
           }
         void add_time(time &t1,time &t2)
          {
                hours=t1.hours+t2.hours;
                min=t1.min+t2.min;
                sec=t1.sec+t2.sec;
            if(sec>60)
             {
                 sec=sec-60;
                 min=min+1;
              }
             if(min>60)
             {
                 hours=hours+1;
                 min=min-60;
              }
             if(hours>23)
             {
               hours=0;
              }
         }
};
int main()
{
     Time t1(10,20,30),t2(11,22,33),t3;
     t1.display();
     t2.display();
     t3.add_time(t1,t2);
     t3.display();
}
