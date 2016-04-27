#include "World.h"
#include <vector>
#include <iostream>
#include <sstream>

World::World()
{
    //ctor
}

World::~World()
{
    //dtor
}

int World::str2int(std::string number){
    int num;
    std::stringstream convert(number);
    convert>>num;
    return num;
}

void World::addZip(std::string zipID,std::string stateName,std::string cityName,std::string latVal,std::string lngVal){
    zip *newZip = new zip;
    newZip->code = zipID;
    newZip->lat = latVal;
    newZip->lng = lngVal;
    int index = -1;
    bool stateFound = false;
    for(int i = 0;i<regions.size();i++){
        if(regions[i]->name==stateName){
            index = i;
            stateFound = true;
            break;
        }
    }
    if(stateFound==true){
        bool cityFound = false;
        state *newState = regions[index];
        for(int i = 0;i<newState->cities.size();i++){
            if(newState->cities[i]->name==cityName){
                index = i;
                cityFound = true;
                break;
            }
        }
        if(cityFound==true){
            city *newCity = newState->cities[index];
            newCity->codes.push_back(newZip);
        }
        else{
            city *newCity = new city;
            newCity->name = cityName;
            newCity->codes.push_back(newZip);
            newState->cities.push_back(newCity);
        }
    }
    else if(stateFound==false){
        state *newState = new state;
        city  *newCity = new city;
        newState->name = stateName;
        newCity->name = cityName;
        newCity->codes.push_back(newZip);
        newState->cities.push_back(newCity);
        regions.push_back(newState);

    }
}

void World::printAll(){
    std::string stateName;
    std::string cityName;
    std::string zipID;
    std::string latVal;
    std::string lngVal;
    for(int i = 0;i<regions.size();i++){
        stateName = regions[i]->name;
        for(int j = 0;j<regions[i]->cities.size();j++){
            cityName = regions[i]->cities[j]->name;
            for(int k = 0;k<regions[i]->cities[j]->codes.size();k++){
                zipID = regions[i]->cities[j]->codes[k]->code;
                latVal = regions[i]->cities[j]->codes[k]->lat;
                lngVal = regions[i]->cities[j]->codes[k]->lng;
                std::cout<<zipID<<": "<<cityName<<", "<<stateName<<" Lat:"<<latVal<<" Long:"<<lngVal<<std::endl;
            }
        }
    }
}

void World::printCityName(std::string cityName, std::string stateName){
    int index = -1;
    bool stateFound = false;
    bool cityFound = false;
    for(int i = 0;i<regions.size();i++){
        if(regions[i]->name==stateName){
            index = i;
            stateFound = true;
            break;
        }
    }
    if(stateFound==true){
        state *stateCurrent = regions[index];
        for(int i = 0;i<stateCurrent->cities.size();i++){
            if(stateCurrent->cities[i]->name==cityName){
                index = i;
                cityFound = true;
                break;
            }
        }
        if(cityFound==true){
            std::cout<<cityName<<" Zip Code(s):"<<std::endl;
            for(int i = 0;i<stateCurrent->cities[index]->codes.size();i++){
                std::cout<<stateCurrent->cities[index]->codes[i]->code<<std::endl;
            }
        }
        else{
            std::cout<<"City not found."<<std::endl;
        }
    }
    else{
        std::cout<<"State not found."<<std::endl;
    }
}

void World::printZip(std::string zipID){
    bool zipFound = false;
    int stateI;
    int cityI;
    for(int i = 0;i<regions.size();i++){
        for(int j = 0;j<regions[i]->cities.size();j++){
            for(int k = 0;k<regions[i]->cities[j]->codes.size();k++){
                if(regions[i]->cities[j]->codes[k]->code==zipID){
                    stateI = i;
                    cityI = j;
                    zipFound = true;
                    break;
                }
            }
        }
    }
    if(zipFound==true){
        std::cout<<"Zip Code: "<<zipID<<" City: "<<regions[stateI]->cities[cityI]->name<<", "<<regions[stateI]->name<<std::endl;
    }
    else{
        std::cout<<"Zip Code not found."<<std::endl;
    }
}

void World::printState(std::string stateName){
    int index = -1;
    bool stateFound = false;
    for(int i = 0;i<regions.size();i++){
        if(regions[i]->name==stateName){
            index = i;
            stateFound = true;
            break;
        }
    }
    if(stateFound==true){
        for(int i = 0;i<regions[index]->cities.size();i++){
            std::cout<<regions[index]->cities[i]->name<<" Zip Code(s):"<<std::endl;
            for(int j = 0;j<regions[index]->cities[i]->codes.size();j++){
                std::cout<<"  "<<regions[index]->cities[i]->codes[j]->code<<std::endl;
            }
        }
    }
    else{
        std::cout<<"State not found."<<std::endl;
    }
}

void World::delZip(std::string zipID){
    bool zipFound = false;
    int stateI;
    int cityI;
    int zipI;
    for(int i = 0;i<regions.size();i++){
        for(int j = 0;j<regions[i]->cities.size();j++){
            for(int k = 0;k<regions[i]->cities[j]->codes.size();k++){
                if(regions[i]->cities[j]->codes[k]->code==zipID){
                    stateI = i;
                    cityI = j;
                    zipI = k;
                    zipFound = true;
                    break;
                }
            }
        }
    }
    if(zipFound==true){
        zip *temp = regions[stateI]->cities[cityI]->codes[zipI];
    }
    else{
        std::cout<<"Zip Code not found."<<std::endl;
    }
}

void World::delCity(std::string cityName, std::string stateName){
    int index = -1;
    bool stateFound = false;
    bool cityFound = false;
    for(int i = 0;i<regions.size();i++){
        if(regions[i]->name==stateName){
            index = i;
            stateFound = true;
            break;
        }
    }
    if(stateFound==true){
        state *stateCurrent = regions[index];
        for(int i = 0;i<stateCurrent->cities.size();i++){
            if(stateCurrent->cities[i]->name==cityName){
                index = i;
                cityFound = true;
                break;
            }
        }
        if(cityFound==true){
            stateCurrent->cities[index]->codes.clear();
        }
        else{
            std::cout<<"City not found."<<std::endl;
        }
    }
    else{
        std::cout<<"State not found."<<std::endl;
    }
}

void World::delState(std::string stateName){
    int index = -1;
    bool stateFound = false;
    for(int i = 0;i<regions.size();i++){
        if(regions[i]->name==stateName){
            index = i;
            stateFound = true;
            break;
        }
    }
    if(stateFound==true){
        regions[index]->cities.clear();
    }
    else{
        std::cout<<"State not found."<<std::endl;
    }
}

void World::modcity(std::string stateName,std::string cityName, std::string newCityName){
    city *newCity = new city;
    newCity->name = newCityName;
    int index = -1;
    bool stateFound = false;
    bool cityFound = false;
    for(int i = 0;i<regions.size();i++){
        if(regions[i]->name==stateName){
            index = i;
            stateFound = true;
            break;
        }
    }
    if(stateFound==true){
        state *stateCurrent = regions[index];
        for(int i = 0;i<stateCurrent->cities.size();i++){
            if(stateCurrent->cities[i]->name==cityName){
                index = i;
                cityFound = true;
                break;
            }
        }
        if(cityFound==true){
            newCity->codes = stateCurrent->cities[index]->codes;
            stateCurrent->cities[index] = newCity;
        }
        else{
            std::cout<<"City not found."<<std::endl;
        }
    }
    else{
        std::cout<<"State not found."<<std::endl;
    }
}

void World::modzip(std::string zipID,std::string newZipID){
    zip *newZip = new zip;
    newZip->code = newZipID;
    bool zipFound = false;
    int stateI;
    int cityI;
    int zipI;
    for(int i = 0;i<regions.size();i++){
        for(int j = 0;j<regions[i]->cities.size();j++){
            for(int k = 0;k<regions[i]->cities[j]->codes.size();k++){
                if(regions[i]->cities[j]->codes[k]->code==zipID){
                    stateI = i;
                    cityI = j;
                    zipI = k;
                    zipFound = true;
                    break;
                }
            }
        }
    }
    if(zipFound==true){
        newZip->lat = regions[stateI]->cities[cityI]->codes[zipI]->lat;
        newZip->lng = regions[stateI]->cities[cityI]->codes[zipI]->lng;
        regions[stateI]->cities[cityI]->codes[zipI] = newZip;
    }
    else{
        std::cout<<"Zip Code not found."<<std::endl;
    }
}

void World::delAll(){
    regions.clear();
}

