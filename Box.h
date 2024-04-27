#pragma once
#include <iostream>
namespace labnull {
    class Box
    {
    private:
        int length;
        int width;
        int height;
        double weight;
        int value;

    public:
        Box();
        Box(int l, int width, int h, double weight, int v);

        int getLength() const;
        int getWidth() const;
        int getHeight() const;
        double getWeight() const;
        double getValue() const;

        void setLength(int length);
        void setWidth(int width);
        void setHeight(int height);
        void setWeight(double weight);
        void setValue(int value);
    };
    int sumBox(Box box[], int n);
    bool lenWidHeightStandart(Box box[], int n, int l, int w, int h);
    int maxWeight(Box box[], int n, int maxV);
    bool operator == (const Box& box1, const Box& box2);
    std::istream& operator >> (std::istream& in, Box& box);
    std::ostream& operator << (std::ostream& out, const Box& box);
}