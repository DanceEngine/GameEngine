//
// Created by DanceEngine on 2024/12/10.
//

#ifndef APP_H
#define APP_H


class App {
public:
    static float GetDeltaTime();
    static void SetDeltaTime(double time);

    static void SetCurrentTime(double time);
    static double CurrentTime();

private:
    static double m_currentTime;
    static double m_DeltaTime;
};


#endif //APP_H
