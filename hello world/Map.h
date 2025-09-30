#include <vector>
#include <string>
#include "Coordinates.h"
#include "Interectable.h"
#include "math.h"
#include "CrossplatformFuncs.h"

#pragma once

class Entity;

class Map {
private:
    int width;
    int height;
    int fillPercent;
    std::vector<Interectable*> objects;
    std::vector<Entity*> entities;
    std::vector<std::vector<std::string>> map;
    CrossplatformFuns cf;
public:
    Map();
    
    void PrintMap();
    Coordinates Size();
    std::string GetElement(Coordinates coordinates);
    void SetElement(Coordinates coordinates, std::string object);
    void SpawnObject(Interectable* object);
    void SpawnObject(Entity* object);
    void SpawnObject(Entity* object, Coordinates position);
    void DeleteObject(Interectable* object);
    void DeleteObject(Entity* object);
    Interectable* GetNearstInterectableObject(Coordinates position);
    Entity* GetNearstEntityObject(Coordinates position);
    Entity* GetObjectA(Coordinates position);
    void GenerateMap();
    int GetNeighbourCount(unsigned int x, unsigned int y);
    void SmoothMap();
    void FillOuterWalls();
    void Debug();
    Coordinates GetPlayerPosition();
    float GetDistanceToPlayer(Entity* entity);
    float GetDirectionToPlayer(Entity* entity);
    
    std::vector<Interectable*> GetInterectable();
    std::vector<Entity*> GetEntity();
    std::vector<std::vector<std::string>> GetMap();
    
    void SetMap(std::vector<std::vector<std::string>> map);
    void AddEntity(Entity* entity);
    void AddInterectable(Interectable* inter);
    Entity* GetPlayer();
    
    //test
    void PrintLine(Entity* entity);
};
