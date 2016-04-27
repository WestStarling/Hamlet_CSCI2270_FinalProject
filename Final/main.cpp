#include <iostream>
#include <fstream>
#include <sstream>
#include "World.h"

using namespace std;

int main()
{
    World USA;
    ifstream zipcodes;
    zipcodes.open("cities.csv");
    string line;
    getline(zipcodes,line);
    string data;
    string zip;
    string state;
    string city;
    string lat;
    string lng;
    while(getline(zipcodes,line)){
        stringstream info(line);
        getline(info,data,',');
        zip = data;
        getline(info,data,',');
        state = data;
        getline(info,data,',');
        city = data;
        getline(info,data,',');
        lat = data;
        getline(info,data,',');
        lng = data;
        USA.addZip(zip,state,city,lat,lng);
    }
    int option = 0;
    while(option!=11){
        cout<<"======= Menu ======="<<endl;
        cout<<"1. Print all Zip Codes"<<endl;
        cout<<"2. Print all Zip Codes for a city"<<endl;
        cout<<"3. Find a City by Zip Code"<<endl;
        cout<<"4. Print all Zip Codes in a state"<<endl;
        cout<<"5. Delete a Zip Code"<<endl;
        cout<<"6. Delete a City's Zip Code(s)"<<endl;
        cout<<"7. Delete a State's Zip Code(s)"<<endl;
        cout<<"8. Delete all Zip Codes"<<endl;
        cout<<"9. Add a Zip Code"<<endl;
        cout<<"10. Modify"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"===================="<<endl;
        cout<<"Choice:"<<endl;
        cin>>option;
        cin.ignore();

        if(option==1){
            USA.printAll();
        }
        else if(option==2){
            string cityName;
            string stateName;
            cout<<"City:"<<endl;
            getline(cin,cityName);
            cout<<"State:"<<endl;
            getline(cin,stateName);
            USA.printCityName(cityName,stateName);
        }
        else if(option==3){
            string zipID;
            cout<<"Zip Code:"<<endl;
            getline(cin,zipID);
            USA.printZip(zipID);
        }
        else if(option==4){
            string stateName;
            cout<<"State:"<<endl;
            getline(cin,stateName);
            USA.printState(stateName);
        }
        else if(option==5){
            string zipID;
            cout<<"Zip Code:"<<endl;
            getline(cin,zipID);
            USA.delZip(zipID);
        }
        else if(option==6){
            string cityName;
            string stateName;
            cout<<"City:"<<endl;
            getline(cin,cityName);
            cout<<"State:"<<endl;
            getline(cin,stateName);
            USA.delCity(cityName, stateName);
        }
        else if(option==7){
            string stateName;
            cout<<"State:"<<endl;
            getline(cin,stateName);
            USA.delState(stateName);
        }
        else if(option==8){
            USA.delAll();
        }
        else if(option==9){
            string zipID;
            string stateName;
            string cityName;
            string latVal;
            string lngVal;
            cout<<"City:"<<endl;
            getline(cin,cityName);
            cout<<"State:"<<endl;
            getline(cin,stateName);
            cout<<"Zip Code:"<<endl;
            getline(cin,zipID);
            cout<<"Latitude:"<<endl;
            getline(cin,latVal);
            cout<<"Longitude:"<<endl;
            getline(cin,lngVal);
            USA.addZip(zipID,stateName,cityName,latVal,lngVal);
        }
        else if(option==10){
            int optionM = 0;
            cout<<"====Modify Menu===="<<endl;
            cout<<"1. Change a Zip Code"<<endl;
            cout<<"2. Change a City name"<<endl;
            cin>>optionM;
            cin.ignore();
            if(optionM==1){
                string zipID;
                string newZipID;
                cout<<"Zip Code to change:"<<endl;
                getline(cin,zipID);
                cout<<"New Zip Code:"<<endl;
                getline(cin,newZipID);
                USA.modzip(zipID,newZipID);
            }
            else if(optionM==2){
                string cityName;
                string stateName;
                string newCityName;
                cout<<"City to Change:"<<endl;
                getline(cin,cityName);
                cout<<"New City name:"<<endl;
                getline(cin,newCityName);
                cout<<"State:"<<endl;
                getline(cin,stateName);
                USA.modcity(stateName,cityName,newCityName);
            }
            else if(optionM>2 or optionM<1){
                cout<<"Please choose a valid option."<<endl;
            }
        }
        else if(option>11 or option<1){
            cout<<"Please choose a valid option."<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
