#ifndef TARGET_H
#define TARGET_H

class Target {
public:
	Target(int id, double x, double y, double vx, double vy);

	void step(double dt);

	int getId() const;
	double getX() const;
	double getY() const;
	double getVx() const;
	double getVy() const;

private:
	int id_;
	double x_;
	double y_;
	double vx_;
	double vy_;
};

#endif
