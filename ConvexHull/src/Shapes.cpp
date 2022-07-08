#include "Shapes.h"
#include <iostream>
#include <utility>
#include <typeinfo>
#include <cmath>
#include <vector>

Circle::Circle(int center_x, int center_y, int radius) : center_x{center_x}, center_y{center_y}, radius{radius}{};

void Circle::print(){
    std::cout<< "C " << "(" << center_x << ", " << center_y << ", " << radius << ")" <<std::endl;
}

std::vector<std::pair<double, double>> Circle::intersect(Shape* s){
		std::vector<std::pair<double, double>> result;

		if(typeid(*s).name() == typeid(Circle).name()){
			Circle* c = dynamic_cast<Circle*>(s);
			int r1 = getRadius(); int r2 = c->getRadius(); 
			int x1 = getCenterX(); int y1 = getCenterY(); 
			int x2 = c->getCenterX(); int y2 = c->getCenterY(); 

			double d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
			double a = (r1*r1 - r2*r2 + d*d) /(2*d);

			if(d > (r1 + r2) || d < abs(r1 - r2) || (d == 0.0 && r1 == r2)){
				// std::cout<<"No intersection!"<<std::endl;
				return result;
			}

			double h = sqrt(r1*r1 - a*a);
			double px= x1 + a*(x2-x1)/d;
			double py= y1 + a*(y2-y1)/d;

			double x3= px + h*(y2-y1)/d; 
			double y3= py - h*(x2-x1)/d;

			double x4= px - h*(y2-y1)/d; 
			double y4= py + h*(x2-x1)/d;

			if(x3 == x4 && y3 == y4){
				// std::cout<<x3<< " " <<y3<<std::endl;
				result.push_back(std::make_pair(x3, y3));
				return result;
			}
			result.push_back(std::make_pair(x3, y3));
			result.push_back(std::make_pair(x4, y4));
			// std::cout<<x4<< " " <<y4<<std::endl;

		}

		else if(typeid(*s).name() == typeid(LineSegment).name()){
			LineSegment* l = dynamic_cast<LineSegment*>(s);
			int r = getRadius(); int cx = getCenterX(); int cy = getCenterY(); 
			int x1 = l->getStartX(); int x2 = l->getEndX(); 
			int y1 = l->getStartY(); int y2 = l->getEndY();

			double t;
			int dx = x2 - x1;
			int dy = y2 - y1;
			int a = dx*dx + dy*dy; 
			int b = 2 * (dx*(x1 - cx) + dy*(y1 - cy));
			int c = (x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy) - r*r;

			double disc = b*b - 4*a*c;
			if(disc == 0.0){
				t = (-b + sqrt(disc)) / (a * 2.0);
				if(t >= 0.0 && t<= 1.0){
					result.push_back(std::make_pair(x1 + t*dx,y1 + t*dy));
					// std::cout<<x1 + t*dx<<" "<<y1 + t*dy<<std::endl;
				}
			}
			else if(disc > 0.0){
				t = (-b + sqrt(disc)) / (a * 2.0);
				if(t >= 0 && t <= 1){
					result.push_back(std::make_pair(x1 + t*dx,y1 + t*dy));
				}
				
				t = (-b - sqrt(disc)) / (a * 2.0);
				if(t >= 0 && t <= 1){
					// std::cout<<"circleline "<<x1 + t*dx<<" "<<y1 + t*dy<<std::endl;
					result.push_back(std::make_pair(x1 + t*dx,y1 + t*dy));
				}
			}
	}
	return result;
}

//getters
int Circle::getRadius(){
	return radius;
}

int Circle::getCenterX(){
	return center_x;
}

int Circle::getCenterY(){
	return center_y;
}

//setters
void Circle::setRadius(int radius){
    this -> radius = radius;
}

void Circle::setCenterX(int center_x){
	this -> center_x = center_x;
}

void Circle::setCenterY(int center_y){
	this -> center_y = center_y;
}

/* -------------------------------------------------------- */

LineSegment::LineSegment(int start_x, int start_y, int end_x, int end_y) : 
                            start_x{start_x}, start_y{start_y}, end_x{end_x}, end_y{end_y}{};

void LineSegment::print(){
    std::cout<< "L " <<  "(" << start_x<< ", " << start_y <<  ", " << end_x << ", " << end_y << ")" <<std::endl;
}


std::vector<std::pair<double, double>> LineSegment::intersect(Shape* sh){
		std::vector<std::pair<double, double>> result;
		if(typeid(*sh).name() == typeid(Circle).name()){
			return sh->intersect(this);
		}
		else if(typeid(*sh).name() == typeid(LineSegment).name()){
			LineSegment* l = dynamic_cast<LineSegment*>(sh);
			int p1_x = getStartX(), p1_y = getStartY(), p2_x = getEndX(), p2_y = getEndY();
			int p3_x = l->getStartX(), p3_y = l->getStartY(), p4_x = l->getEndX(), p4_y = l->getEndY();

			double s1_x, s1_y, s2_x, s2_y;
			s1_x = p2_x - p1_x;     
			s1_y = p2_y - p1_y;

			s2_x = p4_x - p3_x;
			s2_y = p4_y - p3_y;

			double s = (-s1_y * (p1_x - p3_x) + s1_x * (p1_y - p3_y)) / (-s2_x * s1_y + s1_x * s2_y);
			double t = ( s2_x * (p1_y - p3_y) - s2_y * (p1_x - p3_x)) / (-s2_x * s1_y + s1_x * s2_y);


			if (s >= 0 && s <= 1 && t >= 0 && t <= 1){
					double res_x = p1_x + (t * s1_x);
					double res_y = p1_y + (t * s1_y);
					// std::cout<<"line/line: "<<res_x<< " "<<res_y<<std::endl;
					result.push_back(std::make_pair(res_x,res_y));
			}
		}

			return result;
}
//getters

int LineSegment::getStartX(){
	return start_x;
}

int LineSegment::getStartY(){
	return start_y;
}

int LineSegment::getEndX(){
	return end_x;
}

int LineSegment::getEndY(){
	return end_y;
}

//setters
void LineSegment::setStartX(int start_x){
	this -> start_x = start_x;
}

void LineSegment::setStartY(int start_y){
	this -> start_y = start_y;
}

void LineSegment::setEndX(int end_x){
	this -> end_x = end_x;
}

void LineSegment::setEndY(int end_y){
	this -> end_y = end_y;
}