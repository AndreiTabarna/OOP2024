#include "Canvas.h"

int main() {
    Canvas canvas(20, 20);
    canvas.DrawCircle(10, 10, 5, '*');
    canvas.FillCircle(10, 10, 5, '#');
    //canvas.DrawRect(5, 5, 15, 10, '-');
    //canvas.FillRect(1, 1, 18, 18, '+');
    //canvas.DrawLine(0, 0, 19, 19, '|');
    canvas.Print();
    canvas.Clear();
    return 0;
}

