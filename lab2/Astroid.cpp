#define _CRT_SECURE_NO_WARNINGS
#include "Astroid.h"
#include <iostream>
#include <cmath>

namespace Prog2 {

    Point::Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    Astroid::Astroid() {
        this->r = 1;
    }

    Astroid::Astroid(double r) {
        if (r < 0)
            throw std::invalid_argument("Invalid radius");
        this->r = r;
    }

    double Astroid::getR() const {
        return r;
    }

    void Astroid::setR(double const r) {
        if (r == 0) {
            throw std::invalid_argument("Invalid radius");
        }
        this->r = r;
    }

    double Astroid::getX(double T) const {
        return 4 * r * pow(cos(T), 3);
    }

    double Astroid::getY(double T) const {
        return 4 * r * pow(sin(T), 3);
    }

    double Astroid::getY(double* x) const {
        return pow((pow(4 * r, 0.66) - pow((*x), 0.66)), 1.5);
    }

    double Astroid::getLength() const {
        return 4 * r * 6;
    }

    double Astroid::getRadCur(double T) const {
        return (3.0 / 2) * 4 * r * sin(2 * T);
    }

    double Astroid::getLength(double T) const {
        return 1.5 * 4 * r * pow(sin(T), 2);
    }

    double Astroid::getArea() const {
        return 0.375 * 3.14 * pow(4 * r, 2);
    }

    Point Astroid::getXY(double T) const {
        return { getX(T), getY(T) };
    }

    int dialog(const char* msgs[], int N) {
        std::string errmsg;
        int rc;
        do {
            std::cout << errmsg;
            errmsg = "You are wrong. Repeat, please\n";
            for (int j = 0; j < N; ++j)
                puts(msgs[j]);
            std::cout << "Make your choice:";

            if (getNaturalInt(&rc) == 0) { rc = 0; }
        } while (rc < 0 || rc >= N);
        return rc;
    }

    int getNaturalInt(int* a) {
        int n;
        do {
            n = scanf("%d", a);
            if (n < 0)
                return 0;
            if (n == 0 || *a < 0) {
                printf("%s\n", "Error! Please, repeat your input: ");
                scanf("%*[^\n]");
            }
        } while (n == 0 || *a < 0);
        return 1;
    }

    int getDouble(double* a) {
        int n;
        do {
            n = scanf("%lf", a);
            if (n < 0)
                return 0;
            if (n == 0 || *a < 0) {
                printf("%s\n", "Error! Please, repeat your input: ");
                scanf("%*[^\n]");
            }
        } while (n == 0 || *a < 0);
        return 1;
    }

    int dialog_input(Astroid& A) {
        double r;
        std::cout << "Input \"r\" parameter for deltoid:";
        getDouble(&r);
        A.setR(r);

        return 1;
    }

    int dialog_getCurveLength(Astroid& A) {
        try {
            checkZero_r(A);
            std::cout << "Curve length is:" << A.getLength() << std::endl << std::endl;
            return 1;
        }
        catch (double r) {
            errmsg(r);
            std::cerr << "Radius of inner circle equals: " << r << std::endl << std::endl;
            return 1;
        }
    }

    int dialog_getCurveLength_t(Astroid& A) {
        try {
            checkZero_r(A);
            std::cout << "Input \"t\" parameter for deltoid:";
            double t;
            getDouble(&t);
            check_t(t);
            std::cout << "Curve length is: " << A.getLength(t) << std::endl << std::endl;

            return 1;
        }
        catch (double t) {
            errmsg(&t);
            return 1;
        }
    }

    int dialog_getXY(Astroid& A) {
        try {
            checkZero_r(A);
            std::cout << "Input \"t\" parameter for deltoid:";
            double t;
            getDouble(&t);
            check_t(t);
            Point point = A.getXY(t);
            std::cout << point << std::endl << std::endl;
            return 1;
        }
        catch (double t) {
            errmsg(&t);
            return 1;
        }
    }

    int dialog_getY(Astroid& A) {
        try {
            checkZero_r(A);
            std::cout << "\nInput \"X\" parameter for deltoid:\n";
            double x;
            getDouble(&x);
            std::cout << A.getY(&x) << std::endl << std::endl;
            return 1;
        }
        catch (double r) {
            errmsg(r);
            return 1;
        }
    }

    int dialog_getArea(Astroid& A) {
        try {
            checkZero_r(A);
            std::cout << "Area is:" << A.getArea() << std::endl << std::endl;
            return 1;
        }
        catch (double r) {
            errmsg(r);
            std::cerr << "Radius of inner circle equals: " << r << std::endl << std::endl;
            return 1;
        }
    }

    int dialog_getRadCur(Astroid& A) {
        try {
            checkZero_r(A);
            std::cout << "Input \"t\" parameter for deltoid:";
            double t;
            getDouble(&t);
            check_t(t);
            std::cout << "Radius of curvature is: " << A.getRadCur(t) << std::endl << std::endl;
            return 1;
        }
        catch (double t) {
            errmsg(&t);
            return 1;
        }
    }

    std::ostream& operator<<(std::ostream& out, Point& point) {
        out << "Point(" << point.x << ";" << point.y << ")\n\n";
        return out;
    }

    void checkZero_r(Astroid& A) {
        if (A.getR() == 0) {
            throw A.getR();
        }
    }

    void check_t(double t) {
        if (t < 0 || t > 1.57) {
            throw std::invalid_argument("Invalid \"t\"");
        }
    }

    void errmsg(double& r) {
        std::cerr << "Radius of inner circle equals: " << r << "\n";
    }

    void errmsg(double* t) {
        std::cerr << "Radius of inner circle equals: " << *t << "\n";
    }
}