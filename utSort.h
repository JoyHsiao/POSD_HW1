#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

//#define DEBUG1
//#define DEBUG2
//#define DEBUG3
//#define DEBUG4
//#define DEBUG5

std::list<Shape *> shape_list;
const double epsilon = 0.000001;

void input_shape(){    
    std::list<Shape *>::iterator i;
    vertex x;
    vertex y;
    vertex z;
    Circle *cir = new Circle(0.0,0.0,8.0);    
    x.x=0.0;
    x.y=0.0;
    y.x=0.0;
    y.y=3.0;
    z.x=3.0;
    z.y=9.0;
    Triangle *tri = new Triangle(x,y,z);
    Rectangle *rec = new Rectangle(0.0,0.0,12.0,12.0);
    shape_list.push_back(cir);
    shape_list.push_back(tri);
    shape_list.push_back(rec);
}

TEST (Sort, sortByIncreasingPerimeter) {
    input_shape();
    std::vector<double> perimeter;    
    
#ifdef DEBUG1
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->perimeter()<<std::endl;
    }

    for(int i=0; i<perimeter.size();i++){
        std::cout<<"perimeter: "<<perimeter[i]<<std::endl;
    }
    
    std::cout<<"!!!!!! run sortByIncreasingPerimeter !!!!!!!"<<std::endl;
#endif

    Sort::sortByIncreasingPerimeter(&shape_list);
    for(Shape * shape_p: shape_list){
        perimeter.push_back(shape_p->perimeter());
#ifdef DEBUG1
        std::cout<<"input_shape: "<<shape_p->perimeter()<<std::endl;
#endif
    }

#ifdef DEBUG1
    std::cout<<"=== run sortByIncreasingPerimeter ==="<<std::endl;
    for(int i=0; i<perimeter.size();i++){
        std::cout<<"perimeter"<<i<<": "<<perimeter[i]<<std::endl;
    }
    
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->perimeter()<<std::endl;
    }
#endif

    for(int i=0; i<perimeter.size()-1;i++){
        int j=i+1;
#ifdef DEBUG1
        std::cout<<"i: "<<i<<std::endl;
        std::cout<<"perimeter["<< i <<"]: "<<perimeter[i]<<"perimeter[" << j <<"]: "<< perimeter[j]<<std::endl;
#endif
        ASSERT_LE(perimeter[i], perimeter[j]);
    }

    //ASSERT_NEAR((2 * M_PI * 8.0), cir.perimeter(), epsilon);
    //ASSERT_NEAR((7.0*2+7.0*2), rec.perimeter(), epsilon);
    //ASSERT_NEAR((distanceOfVertexs(x.x, x.y) + distanceOfVertexs(y.x, y.y) + distanceOfVertexs(z.x, z.y)), tri.perimeter(), epsilon);
    shape_list.clear();
}

TEST (Sort, sortByDecreasingPerimeter) {
    input_shape();
    std::vector<double> perimeter;    
    
#ifdef DEBUG2
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->perimeter()<<std::endl;
    }

    for(int i=0; i<perimeter.size();i++){
        std::cout<<"perimeter: "<<perimeter[i]<<std::endl;
    }
    
    std::cout<<"!!!!!! run sortByDecreasingPerimeter !!!!!!!"<<std::endl;
#endif

    Sort::sortByDecreasingPerimeter(&shape_list);
    for(Shape * shape_p: shape_list){
        perimeter.push_back(shape_p->perimeter());
#ifdef DEBUG2
        std::cout<<"input_shape: "<<shape_p->perimeter()<<std::endl;
#endif
    }

#ifdef DEBUG2
    std::cout<<"=== run sortByDecreasingPerimeter ==="<<std::endl;
    for(int i=0; i<perimeter.size();i++){
        std::cout<<"perimeter"<<i<<": "<<perimeter[i]<<std::endl;
    }
    
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->perimeter()<<std::endl;
    }
#endif

    for(int i=0; i<perimeter.size()-1;i++){
        int j=i+1;
#ifdef DEBUG2
        std::cout<<"i: "<<i<<std::endl;
        std::cout<<"perimeter["<< i <<"]: "<<perimeter[i]<<"perimeter[" << j <<"]: "<< perimeter[j]<<std::endl;
#endif
        ASSERT_GE(perimeter[i], perimeter[j]);
    }

    shape_list.clear();
}

TEST (Sort, sortByIncreasingArea) {
    input_shape();
    std::vector<double> area;    
    
#ifdef DEBUG3
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->area()<<std::endl;
    }

    for(int i=0; i<area.size();i++){
        std::cout<<"area: "<<area[i]<<std::endl;
    }
    
    std::cout<<"!!!!!! run sortByIncreasingArea !!!!!!!"<<std::endl;
#endif

    Sort::sortByIncreasingArea(&shape_list);
    for(Shape * shape_p: shape_list){
        area.push_back(shape_p->area());
#ifdef DEBUG3
        std::cout<<"input_shape: "<<shape_p->area()<<std::endl;
#endif
    }

#ifdef DEBUG3
    std::cout<<"=== run sortByIncreasingArea ==="<<std::endl;
    for(int i=0; i<area.size();i++){
        std::cout<<"area"<<i<<": "<<area[i]<<std::endl;
    }
    
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->area()<<std::endl;
    }
#endif

    for(int i=0; i<area.size()-1;i++){
        int j=i+1;
#ifdef DEBUG3
        std::cout<<"i: "<<i<<std::endl;
        std::cout<<"area["<< i <<"]: "<<area[i]<<"area[" << j <<"]: "<< area[j]<<std::endl;
#endif
        ASSERT_LE(area[i], area[j]);
    }

    shape_list.clear();
}

TEST (Sort, sortByDecreasingArea) {
    input_shape();
    std::vector<double> area;    
    
#ifdef DEBUG4
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->area()<<std::endl;
    }

    for(int i=0; i<area.size();i++){
        std::cout<<"area: "<<area[i]<<std::endl;
    }
    
    std::cout<<"!!!!!! run sortByDecreasingArea !!!!!!!"<<std::endl;
#endif

    Sort::sortByDecreasingArea(&shape_list);
    for(Shape * shape_p: shape_list){
        area.push_back(shape_p->area());
#ifdef DEBUG4
        std::cout<<"input_shape: "<<shape_p->area()<<std::endl;
#endif
    }

#ifdef DEBUG4
    std::cout<<"=== run sortByDecreasingArea ==="<<std::endl;
    for(int i=0; i<area.size();i++){
        std::cout<<"area"<<i<<": "<<area[i]<<std::endl;
    }
    
    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->area()<<std::endl;
    }
#endif

    for(int i=0; i<area.size()-1;i++){
        int j=i+1;
#ifdef DEBUG4
        std::cout<<"i: "<<i<<std::endl;
        std::cout<<"area["<< i <<"]: "<<area[i]<<"area[" << j <<"]: "<< area[j]<<std::endl;
#endif
        ASSERT_GE(area[i], area[j]);
    }

    shape_list.clear();
}

TEST (Sort, sortByIncreasingCompactness) {
    input_shape();
    std::vector<double> area, perimeter;    
    
    Sort::sortByIncreasingCompactness(&shape_list);
    for(Shape * shape_p: shape_list){
        area.push_back((4*M_PI*shape_p->area())/pow(shape_p->perimeter(),2));
    }

#ifdef DEBUG5
    std::cout<<"=== run sortByDecreasingArea ==="<<std::endl;

    for(Shape * shape_p: shape_list){
        std::cout<<"input_shape_a: "<< shape_p->area()<<std::endl;
    }
#endif

    for(int i=0; i<area.size()-1;i++){
        int j=i+1;
        ASSERT_LE(area[i], area[j]);
    }

    shape_list.clear();
}

#endif
