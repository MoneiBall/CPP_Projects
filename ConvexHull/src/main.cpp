#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>  
#include "Shapes.h"


Shape* create(std::ifstream &input);
void print_input(const std::vector<Shape*> &shapes);
void populate_vector(std::vector<Shape*> &shapes);
void intersect(LineSegment* l1, LineSegment* l2);
void intersect(Circle* c1, Circle* c2);
void intersect(LineSegment* l, Circle* circ);
void print(const std::vector<std::pair<double,double>> &v);
void getIntersectionPoints(const std::vector<Shape*> &shapes, std::vector<std::pair<double,double>> &points);
std::vector<std::pair<double,double>> convex_hull(std::vector<std::pair<double,double>> points);
double cross(const std::pair<double,double> &O, const std::pair<double,double> &A, const std::pair<double,double> &B);
double area_hull(std::vector<std::pair<double,double>> &points);


int main(){
    int total_shapes;
    std::cin >> total_shapes;
    if(std::cin.fail() || total_shapes < 0){
        std::cerr<<"Error reading input!"<<std::endl;
        exit(1);
    }
    std::vector<Shape*> shapes(total_shapes); //creating vector size of total_shapes)
    populate_vector(shapes);
    // print_input(shapes);
    std::vector<std::pair<double,double>> points; //creating all intersection points

    getIntersectionPoints(shapes, points);
    std::vector<std::pair<double,double>> hull = convex_hull(points);
    print(points);
    print(hull);
    if(hull.size()>0)
        std::cout<<area_hull(hull)<<std::endl;
    else    
        std::cout<<0<<std::endl;


    return 0;
}

Shape* create() {
    Shape *s;
    char type;
    std::cin >> type;
    if (type == 'C' ){
        int radius, center_x, center_y;
        std::cin >> radius >> center_x >> center_y;
        s = new Circle(radius, center_x, center_y);
    }
    else if (type == 'L'){
        int start_x, end_x, start_y, end_y;
        std::cin >> start_x >> end_x >> start_y >> end_y;
        s = new LineSegment(start_x, end_x, start_y, end_y);
    }
    else {
        std::cerr<<"Error reading shapes, unknown shape!"<<std::endl; 
        exit(1);
    } 

    if(std::cin.fail()){
        std::cerr<<"Error reading input!"<<std::endl;
        exit(1);
    }
    return s;
}

void print_input(const std::vector<Shape*> &shapes) {
    for (Shape *s : shapes) {
        s -> print();
    }
    std::cout << std::endl;
}

void populate_vector(std::vector<Shape*> &shapes) {
    for (int i = 0; i < shapes.size(); i++){
        shapes[i] = create();
    }
}

void getIntersectionPoints(const std::vector<Shape*> &shapes, std::vector<std::pair<double,double>> &points) {
    std::vector<std::pair<double,double>> temp;
    for(int i=0; i<shapes.size()-1;i++){
        for(int j=i+1; j<shapes.size();j++){
            if(typeid(*shapes[i]).name() == typeid(Circle).name() && typeid(*shapes[j]).name() == typeid(Circle).name()){
                temp = shapes[i]->intersect(shapes[j]);
                points.insert(points.end(), temp.begin(), temp.end());
            }
        }
    }

    temp.clear();

    for(int i=0; i<shapes.size()-1;i++){
        for(int j=i+1; j<shapes.size();j++){
            if(typeid(*shapes[i]).name() == typeid(LineSegment).name() && typeid(*shapes[j]).name() == typeid(LineSegment).name()){
                temp = shapes[i]->intersect(shapes[j]);
                points.insert(points.end(), temp.begin(), temp.end());
            }
        }
    }

    temp.clear();

    for(int i=0; i<shapes.size();i++){
        for(int j=0; j<shapes.size();j++){
            if (i==j)
                continue;
            if(typeid(*shapes[i]).name() == typeid(LineSegment).name() && typeid(*shapes[j]).name() == typeid(Circle).name()){
                temp = shapes[i]->intersect(shapes[j]);
                points.insert(points.end(), temp.begin(), temp.end());
            }
        }
    }
}

void print(const std::vector<std::pair<double,double>>& v){
    std::cout << v.size() << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    for (int i=0; i<v.size();i++){
        std::cout << v[i].first << " " <<v[i].second << std::endl;
    }
}

///convex_hull
///ref : https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
std::vector<std::pair<double,double>> convex_hull(std::vector<std::pair<double,double>> points)
{
	int n = points.size(), k = 0;
	if (n <= 3) return points;
	std::vector<std::pair<double,double>> hull(2*n);

	// Sort points
	std::sort(points.begin(), points.end());

	// Lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(hull[k-2], hull[k-1], points[i]) <= 0) k--;
		hull[k++] = points[i];
	}

	// Upper hull
	for (int i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && cross(hull[k-2], hull[k-1], points[i-1]) <= 0) k--;
		hull[k++] = points[i-1];
	}

	hull.resize(k-1);

    return hull;
}

double cross(const std::pair<double,double> &O, const std::pair<double,double> &A, const std::pair<double,double> &B){
	return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

//aplying showlace formula with ordered points cw / acw
double area_hull(std::vector<std::pair<double,double>> &points)
{
    double result = 0.0;
    int n = points.size();
    int j = n - 1;
    for (int i = 0; i < n; i++){
            result += (points[j].first + points[i].first) * (points[j].second - points[i].second);
            j = i;
    }
    return (result < 0) ? result *= -1 * 0.5 : result * 0.5;
}


// Shape* create(std::ifstream &input) {
//     Shape *s;
//     char type;
//     input >> type;
//     if (type == 'C' ){
//         int radius, center_x, center_y;
//         input >> radius >> center_x >> center_y;
//         s = new Circle(radius, center_x, center_y);
//     }
//     else if (type == 'L'){
//         int start_x, end_x, start_y, end_y;
//         input >> start_x >> end_x >> start_y >> end_y;
//         s = new LineSegment(start_x, end_x, start_y, end_y);
//     }
//     else {
//         std::cerr<<"Error reading shapes, unknown shape!"<<std::endl; 
//         exit(1);
//     } 
//     return s;
// }


