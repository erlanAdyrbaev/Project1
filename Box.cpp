#pragma once
#include "Box.h"
using namespace labnull;

	Box::Box(int length, int width, int height, double weight, int value) {
		this->width = width;
		this->weight = weight;
		this->length = length;
		this->height = height;
		this->value = value;
	}
	Box::Box() {
		width = 0;
		weight = 0;
		length = 0;
		height = 0;
		value = 0;
	}
	 int Box::getLength() const {
		return length;
	}
	 int Box::getWidth() const {
		return width;
	}
	 double Box::getWeight() const {
		return weight;
	}
	 int Box::getHeight() const {
		return height;
	}
	 double Box::getValue() const {
		return value;
	}


	void Box::setLength(int length)  {
		this->length = length;
	}
	void Box::setWidth(int width)  {
		this->width = width;
	}
	void Box::setWeight(double weight) {
		this->weight = weight;
	}
	void Box::setHeight(int height) {
		this->height = height;
	}
	void Box::setValue(int value) {
		this->value = value;
	}



int sumBox(Box box[], int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += box[i].getValue();
	}
	return res;
}
bool lenWidHeightStandart(Box box[], int n, int l, int w, int h) {
	int lenght = 0;
	int width = 0;
	int height = 0;
	for (int i = 0; i < n; i++) {
		lenght += box[i].getLength();
		width += box[i].getWidth();
		height += box[i].getHeight();
	}
	if (lenght > l || width > w || height < h) {
		return true;
	}
	else return false;
}
int maxWeight(Box box[], int n, int maxV) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		int V = box[i].getHeight() * box[i].getLength() * box[i].getWidth();
		if (box[i].getWeight() > result && V <= maxV) {
			result = V;
		}
	}
	return result;
}
bool operator == (const Box& box1, const Box& box2) {
	return box1.getHeight() == box2.getHeight() && box1.getLength() == box2.getLength() && box1.getValue() == box2.getValue() && box1.getWeight() == box2.getWeight() && box1.getWidth() == box1.getWidth();
}
std::istream& operator >> (std::istream& in, Box& box) {
	int length, width, height, value;
	double weight;
	in >> length >> width >> height >> value >> weight;
	box.setHeight(height);
	box.setLength(length);
	box.setValue(value);
	box.setWeight(weight);
	return in;
}
std::ostream& operator << (std::ostream& out,const Box& box) {
	out << "length: " << box.getLength() << " width: " << box.getWidth() << " height: " << box.getHeight() << " value: " << box.getValue() << " weight: " << box.getWeight();
	return out;
}
