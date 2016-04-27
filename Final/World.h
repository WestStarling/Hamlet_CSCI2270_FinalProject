#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>

struct zip{
    std::string code;
    std::string lat;
    std::string lng;
};

struct city{
    std::string name;
    std::vector<zip *> codes;
};

struct state{
    std::string name;
    std::vector<city *> cities;
};


class World
{
    public:
        World();
        ~World();
        void printAll();
        void printCityName(std::string city,std::string state);
        void printZip(std::string zip);
        void printState(std::string state);
        void delAll();
        void delCity(std::string city, std::string state);
        void delZip(std::string zip);
        void delState(std::string state);
        void addZip(std::string zip,std::string state,std::string city,std::string lat,std::string lng);
        void modzip(std::string zip,std::string newZip);
        void modcity(std::string state,std::string city,std::string newCity);
        int str2int(std::string number);

    protected:
    private:
        std::vector<state *> regions;
};

#endif // WORLD_H
