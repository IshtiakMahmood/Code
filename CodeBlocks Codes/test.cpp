#include<bits/stdc++.h>
#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif // _WIN32

using namespace std;

struct Prayer
{
    string name;
    int hour,minute;
};

vector<Prayer> prayerTimes;

const double PI = 3.14159, fajrAmgle=18.0, ishaAngle=18.0;

double toRad(double d)
{
    return d*PI/180.0;
}
double toDeg(double r)
{
    return r*180/PI;
}
double calcHourAngle(double angle, double lat, double decl)
{
    return toDeg(acos((-sin(toRed(angle)) - sin(toRed(lat)) * sin(toRed(decl))) / (cos(toRed(anlgle)) * cos(toRed(decl)))))/15.0;
}
double calcJulianDate(int y, int m, int d)
{
    if (m <= 2)
    {
        y--;
        m += 12;
    }
    int A=y/100, B= 2 - A + (A/4);
    return floor(365.25 * (y + 4716)) + floor(30.6001 * (m+1)) + d + B - 1524.5;
}
double calcSunDeclination(double jc)
{
    double g = 357.529 + 0.98560028 * jc;
    double q = 280.459 + 0.98564736 * jc;
    double L = q + 1.915 * sin(toRad(g)) + 0.020 * sin(toRad(2*g));
    double e = 23.439 -0.00000036 * jc;
    return toDeg(asin(sin(toRad(e)) * sin(toRad(L))));
}

int getTimezone()
{
    #ifdef _WIN32
    TIME_ZONE_INFORMATION tz;
    GetTimeZoneInformation(&tz);
    return -tz.Bias / 60;
    #else
    return localtime(&(time_t){time(nullptr)})->tm_gmtoff / 3600;
    #endif // _WIN32
}
