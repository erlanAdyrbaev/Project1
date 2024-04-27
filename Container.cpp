#include "Container.h"
#pragma once
using namespace labnull;



	Container::Container(int length, int width, int height, double maxWeight) {
			this->length = length;
			this->width = width;
			this->height = height;
			this->maxWeight = maxWeight;
	}
	int Container::getLength() const {
		return length;
	}
	int Container::getWidth() const {
		return width;
	}
	double Container::getMaxWeight() const {
		return maxWeight;
	}
	int Container::getHeight() const {
		return height;
	}
	


	void Container::setLength(int length) {
		this->length = length;
	}
	void Container::setWidth(int width) {
		this->width = width;
	}
	void Container::setMaxWeight(double maxWeight) {
		this->maxWeight = maxWeight;
	}
	void Container::setHeight(int height) {
		this->height = height;
	}
	

	int Container::numOfBoxes() {
		return vectorBox.size();
	}
	double Container::sumWeight() {
		double sumWeight = 0;
		for (int i = 0; i < vectorBox.size(); i++) {
			sumWeight += vectorBox[i].getWeight();
		}
		return sumWeight;
	}
	int Container::sumValue() {
		int sumValue = 0;
		for (int i = 0; i < vectorBox.size(); i++) {
			sumValue += vectorBox[i].getValue();
		}
		return sumValue;
	}
		const Box& Container::getBoxI(int i) const {
			return vectorBox.at(i);
		}
		int Container::pushBox(Box box) {
			if (sumWeight() + box.getWeight() <= maxWeight) {
				vectorBox.push_back(box);
				return vectorBox.size();
			}
			throw MaxWeightException("The box exceeds the maximum weight");
		}
		void Container::removeI(const int i) {
			if (numOfBoxes() == 0) {
				throw std::exception("The container was empty, you can't delete any element here");
			}
			vectorBox.erase(vectorBox.begin() + i);
		}
std::istream& operator >> (std::istream& in, Container& container) {
	int length, width, height, n;
	double maxWeight;
	Box box;
	std::cout << "entry length/n";
	in >> length;
	std::cout << "entry width/n";
	in >> width;
	std::cout << "entry height/n";
	in >> height;
	std::cout << "entry maxWeight/n";
	in >> maxWeight;

	container.setHeight(height);
	container.setLength(length);
	container.setWidth(width);
	container.setMaxWeight(maxWeight);

	std::cout << "entry nums of boxes/n";
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		in >> box;
		container.pushBox(box);
	}
}
std::ostream& operator << (std::ostream& out, Container& container) {
	out << "length: " << container.getLength() << ", width: " << container.getWidth() << ", height: " << container.getHeight() << ", maxWeight: " << container.getMaxWeight() << std::endl;
	int n = container.numOfBoxes();
	out << "boxes in container:\n";
	for (int i = 0; i < n; i++) {
		out << "box[" << i << "]:\n" << container.getBoxI(i);
	}
}