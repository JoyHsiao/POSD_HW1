#include "include/Sort.h"

//#define DEBUG

bool Peri_Increas(Shape const *a,Shape const *b)
{
    #ifdef DEBUG
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout<<" a:"<< a->perimeter() << " b:" << b->perimeter() <<std::endl;
    std::cout<< "Peri_Increas" << a->perimeter()<< std::endl;
    #endif
    return a->perimeter() < b->perimeter();
}

bool Peri_Decreas(Shape const *a,Shape const *b)
{
    return a->perimeter() > b->perimeter();
}

bool Area_Increas(Shape const *a,Shape const *b)
{
    return a->area() < b->area();
}

bool Area_Decreas(Shape const *a,Shape const *b)
{
    return a->area() > b->area();
}

bool Increas_Com(Shape const *a,Shape const *b)
{
    return a->perimeter() < b->perimeter();
}

void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList){
    shapeList->sort(Peri_Increas);
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList){
    shapeList->sort(Peri_Decreas);
}

void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList){
    shapeList->sort(Area_Increas);
}

void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList){
    shapeList->sort(Area_Decreas);
}

void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList){
    shapeList->sort(Increas_Com);
}
