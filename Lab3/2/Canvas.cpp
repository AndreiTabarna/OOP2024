#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char*[height];
    for (int i = 0; i < height; ++i) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    // Draw circle centered at (x, y) with radius 'ray' using midpoint circle algorithm
    int cx = ray;
    int cy = 0;
    int radiusError = 1 - cx;

    while (cx >= cy) {
        SetPoint(cx + x, cy + y, ch);
        SetPoint(cy + x, cx + y, ch);
        SetPoint(-cx + x, cy + y, ch);
        SetPoint(-cy + x, cx + y, ch);
        SetPoint(-cx + x, -cy + y, ch);
        SetPoint(-cy + x, -cx + y, ch);
        SetPoint(cx + x, -cy + y, ch);
        SetPoint(cy + x, -cx + y, ch);

        cy++;
        if (radiusError < 0)
            radiusError += 2 * cy + 1;
        else {
            cx--;
            radiusError += 2 * (cy - cx + 1);
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    // Fill circle centered at (x, y) with radius 'ray' using midpoint circle algorithm
    int cx = ray;
    int cy = 0;
    int radiusError = 1 - cx;

    while (cx >= cy) {
        DrawLine(cx + x, cy + y, -cx + x, cy + y, ch);
        DrawLine(cy + x, cx + y, -cy + x, cx + y, ch);
        DrawLine(-cx + x, -cy + y, cx + x, -cy + y, ch);
        DrawLine(-cy + x, -cx + y, cy + x, -cx + y, ch);

        cy++;
        if (radiusError < 0)
            radiusError += 2 * cy + 1;
        else {
            cx--;
            radiusError += 2 * (cy - cx + 1);
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    // Draw rectangle from (left, top) to (right, bottom)
    DrawLine(left, top, right, top, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
    DrawLine(left, bottom, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    // Fill rectangle from (left, top) to (right, bottom)
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    // Bresenham's line algorithm
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        SetPoint(x1, y1, ch);
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    SetPoint(x2, y2, ch);
}

void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = ' ';
        }
    }
}

