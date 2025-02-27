#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class Time  
{
    private:
        unsigned int hour;
        unsigned int minute;
        unsigned int second;
    
    public:
        
        // CONSTRUCTOR DEFS BEGIN:
        Time(int constructHour, int constructMinute, int constructSecond)
        {
            hour = constructHour % 24;
            minute = constructMinute % 60;
            second = constructSecond % 60;
        }

        Time(int constructDuration)
        {
            constructDuration = constructDuration % 86400;
            hour =   (int)(constructDuration / 3600.0) % 24;
            constructDuration = constructDuration % 3600;
            minute = (int)(constructDuration / 60.0) % 60;
            constructDuration = constructDuration % 60;
            second = constructDuration;
        }
        // END CONSTRUCTOR DEFS.

        // SETTER BEGINS:
        int setHour(unsigned int hourMutator) {
            hour = hourMutator % 24;
            return 0;
        }

        int setMinute(unsigned int minuteMutator) {
            minute = minuteMutator % 60;
            return 0;
        }

        int setSecond(unsigned int secondMutator) {
            second = secondMutator % 60;
            return 0;
        }
        // SETTER ENDS.

        // GETTER BEGINS:
        unsigned int getHour() {
            return hour;
        }

        unsigned int getMinute() {
            return minute;
        }

        unsigned int getSecond() {
            return second;
        }
        // GETTER ENDS.

        // OTHER CLASS METHOD DEFS BEGINS:
        int getDuration() {
            return (hour * 3600) + (minute * 60) + (second);
        }

        Time add(Time other) {
            // solid gold                               // integral part                                          // overflow part                 
            Time* addedTime = new Time( ((this->getHour()   + other.getHour())   + ((this->getMinute() + other.getMinute()) / 60)) % 24, 
                                      ((this->getMinute() + other.getMinute()) + ((this->getSecond() + other.getSecond()) / 60)) % 60, // ts hideous bro
                                      (this->getSecond()  + other.getSecond()) % 60);
            return *addedTime;
        }

        int subtract(Time other) {
            if(this->getDuration() >= other.getDuration())
                return this->getDuration() - other.getDuration();
            else
                return 86400 + (this->getDuration() - other.getDuration());
            // return abs(this->getDuration() - other.getDuration());
        }

        int equals(Time other) {
            if(this->getDuration() == other.getDuration())
                return 1;
            else
                return 0;
        }

        std::string toString() {
            char cStringBuffer[32];
            sprintf(cStringBuffer, "%02u:%02u:%02u", hour, minute, second);
            std::string convertedBuffer = cStringBuffer;
            return cStringBuffer;
        }

        // OTHER ENDS.
};


int main() 
{
    Time t1(86400);
    Time t2(24, 0, 0);
    Time t3(1, 1, 1);
    Time t4(0, 30, 30);
    Time t5(0,30,30);

    std::cout << t1.getHour() << "," << t1.getMinute() << "," << t1.getSecond() << std::endl;

    std::cout << t1.equals(t1) << " " <<  t1.equals(t2) << " " 
              << t1.getDuration() << " " << t1.add(t1).toString() << std::endl;

    std::cout << t4.add(t5).toString();
}