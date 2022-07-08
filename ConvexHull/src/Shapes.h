#pragma once
#include "Shapes.h"
#include <vector>


class Shape {
    public:
        virtual void print() = 0;
        virtual std::vector<std::pair<double, double>> intersect(Shape* s) = 0;
};

class Circle : public Shape{
    int radius;
    int center_x;
    int center_y;

    public:
        Circle(int radius, int center_x, int center_y);
        void print();
        std::vector<std::pair<double, double>> intersect(Shape* s);

        int getRadius();
        int getCenterX();
        int getCenterY();

        void setRadius(int r);
        void setCenterX(int r);
        void setCenterY(int r);

};


class LineSegment : public Shape{
    int start_x;
    int end_x;
    int start_y;
    int end_y;

    public:
        LineSegment(int start_x, int end_x, int start_y, int end_y);
        void print();
        std::vector<std::pair<double, double>> intersect(Shape* s);

        int getStartX();
        int getStartY();
        int getEndX();
        int getEndY();
        

        void setStartX(int start_x);
        void setStartY(int start_y);
        void setEndX(int end_x);
        void setEndY(int end_y);

};