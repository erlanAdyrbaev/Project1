#pragma once
#include "vector"
#include "box.h"
namespace labnull {
	class MaxWeightException :public std::exception {
	public:
		MaxWeightException(const char* msg) :exception(msg) {}
	};

	class Container {
	private:
		std::vector<Box> vectorBox;
		int length;
		int	width;
		int	height;
		double maxWeight;
	public:
		Container(int length, int width, int height, double maxWeight);
		int getLength() const;
		int getWidth() const;
		double getMaxWeight() const;
		int getHeight() const;



		void setLength(int length);
		void setWidth(int width);
		void setMaxWeight(double maxWeight);
		void setHeight(int height);


		int numOfBoxes();
		double sumWeight();
		int sumValue();
		const Box& getBoxI(int i)const;
		int pushBox(Box box);
		void removeI(const int i);
		Box& operator [](int i);

	};
	std::istream& operator >> (std::istream& in, Container& container);
	std::ostream& operator << (std::ostream& out, Container& container);
}
