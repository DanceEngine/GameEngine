//
// Created by DanceEngine on 2024/12/14.
//

#ifndef GENERICPLATFORMTIME_H
#define GENERICPLATFORMTIME_H



class GenericPlatformTime {

public:
    static double SecondsPerCycle;
    static double SecondsPerCycle64;



    static double GetSecondsPerCycle() {
        return SecondsPerCycle;
    }
};



#endif //GENERICPLATFORMTIME_H
