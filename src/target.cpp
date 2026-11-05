#include "target.h"

Target::Target(int id, double x, double y, double vx, double vy)
	: id_(id), x_(x), y_(y), vx_(vx), vy_(vy) {}

void Target::step(double dt) {
	x_ += vx_ * dt;
	y_ += vy_ * dt;
}

int Target::getId() const {
	return id_;
}

double Target::getX() const {
	return x_;
}

double Target::getY() const {
	return y_;
}

double Target::getVx() const {
	return vx_;
}

double Target::getVy() const {
	return vy_;
}
