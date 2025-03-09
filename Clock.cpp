/*
Author: Saeed Soukiah
Date: December 12, 2024
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
class Clock {
private:
    int hours;
    int minutes;
    int seconds;
public:
    Clock(int hours = 0, int minutes = 0, int seconds = 0) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    void displayclock() {
        while (true) {
            system("cls");
            if (seconds > 59) {
                minutes++;
                seconds = 0;
            }
            if (minutes > 59) {
                hours++;
                minutes = 0;
            }
            if (hours > 23)
            {
                hours = 0;
            }
            cout << hours << ":" << minutes << ":" << seconds;
            seconds++;
            Sleep(1000);
            // Check for user input to change the time without blocking 
            if (_kbhit()) {
                // _kbhit() checks if a key has been pressed 
                char ch = _getch(); // _getch() reads the key press without waiting for Enter 
                if (ch == '\r') { // '\r' is the Enter key 
                    int newHours, newMinutes, newSeconds;
                    system("Color 9A");
                    cout << "\nEnter new hours, minutes, seconds: \n";
                    cin >> newHours >> newMinutes >> newSeconds;
                    system("Color 94");
                    setTime(newHours, newMinutes, newSeconds);
                }
                if (ch == 'r') { //  letter r to reset clock 
                    this->hours = 0;
                    this->seconds = 0;
                    this->minutes = 0;
                    system("Color 94");
                    cout << "\nclock reset successful\n";
                    Sleep(1000);
                    system("Color 90");
                }
                if (ch == 'e') { //  letter e to terminate program 
                    break;
                }
            }
        }
    }
    void setTime(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
};
int main()
{
    cout << "Font: Consolas, Size: 24\n";
    system("Color 90");
    int x = 0; int y = 0; int z = 0;
    cout << "enter hours minutes seconds:\nPress enter to change clock:\npress 'r' letter to reset clock:\n'e' letter to exit: \n";
    cin >> x >> y >> z;
    Clock c(x, y, z);
    c.displayclock();
}
