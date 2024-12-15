//
// Created by DanceEngine on 2024/12/14.
//

#ifndef GENERICPLATFORMMISC_H
#define GENERICPLATFORMMISC_H



class GenericPlatformMisc {
public:
    static void SetEnvironmentVar(const char* name,const char* value);

    static const char* GetEnvironmentVar(const char* name);
};



#endif //GENERICPLATFORMMISC_H
