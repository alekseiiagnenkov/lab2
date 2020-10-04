//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include "string"

namespace Prog2 {

    int dialog(const char* [], int);

    int getNaturalInt(int* a);

    class Point {
    public:
        double x, y;

        friend std::ostream& operator<<(std::ostream& out, Point& point);

        Point(double, double);
    };

    std::ostream& operator<<(std::ostream& out, Point& point);

    class Astroid {
        double r;

        friend std::ostream& operator<<(std::ostream& out, Point& point);

    public:
        explicit Astroid(double); // ��� ���������� ����������� ���������� ������� ����� "= value"
        explicit Astroid();

        double getR() const;

        void setR(double r);

        double getLength() const;

        double getLength(double) const;

        double getX(double) const;

        double getY(double) const;

        double getRadCur(double) const;

        double getY(double*) const;

        double getArea() const;

        Point getXY(double) const;

    };

    void checkZero_r(Astroid&);

    void check_t(double);

    void errmsg(double&);

    void errmsg(double*);

    int dialog_input(Astroid&);

    int dialog_getCurveLength(Astroid&);

    int dialog_getCurveLength_t(Astroid&);

    int dialog_getXY(Astroid&);

    int dialog_getY(Astroid&);

    int dialog_getArea(Astroid&);

    int dialog_getRadCur(Astroid&);
}