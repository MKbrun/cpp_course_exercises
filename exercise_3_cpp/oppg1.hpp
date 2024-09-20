#pragma once // only include once

const double pi = 3.141592;

class Circle {
public:
  Circle(double radius_); // FIX
  int get_area() const;
  double get_circumference() const;

private: // FIX
  double radius;
}; // FIX

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {}

int Circle::get_area() const { // FIX
  return pi * radius * radius;
}

double Circle::get_circumference() const {  // FIX
  double circumference = 2.0 * pi * radius; // FIX
  return circumference;
}
