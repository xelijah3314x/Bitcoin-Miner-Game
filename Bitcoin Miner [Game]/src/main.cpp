#include <iostream>
#include <thread>
#include <windows.h>
#include "..\include\main.hpp"

using namespace std;
using namespace game;

int main() {
    while (true) {
        Sleep(1000);

        input();
        update();
        draw();
    }

    return 0;
}