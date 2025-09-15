#include "Interectable.h"


Interectable::Interectable(){
    
}

void Interectable::SpawnObject(Map& map){
    srand(time(NULL));
    while(true){
        Coordinates tmpl_position;
        tmpl_position.SetX(rand() % map.Size().GetX());
        tmpl_position.SetY(rand() % map.Size().GetY());
        if(map.GetElement(tmpl_position) == ' ') {
            pos = tmpl_position;
            break;
        }
    }
}

void Interectable::Open(){
    std::cout << "Open!" << std::endl;
}
