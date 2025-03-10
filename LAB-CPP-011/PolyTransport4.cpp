#include <iostream>
using namespace std;

class Transportation
{
public:
     virtual double fare() = 0;
};

class Taxi : public Transportation
{
    private:
        double totalFare = 35;
        double distance = 0;

    public:
        double fare() {
           totalFare = totalFare + (distance * 2);
           return totalFare; 
        }

        void setDistance(double distance) {
            this->distance = distance;
        }
};

class BmtaBus : public Transportation
{
    private:
        double fareRate = 6.5;

    public:
        double fare() {
            return fareRate;
        }
    

};

class BTS : public Transportation
{
    private:
        double totalFare = 15;
        int totalStation = 0;
    
    public:
        double fare() {
            return 15 + (5 * totalStation);
        }
        
        void setStation(int station) {
            this->totalStation = station;
        }
    
};

class Passenger
{
    private:
        double totalFare = 0; 
    public:
        void addTransportation(Transportation* transport) {
            totalFare += transport->fare();
        }

        double getTotalFare() {
            return totalFare;
        }
};

int main()
{
    Passenger passenger;
    while(1) {
        char transportType;
        cin >> transportType;
        if (transportType == 'A') {
            Taxi *taxi = new Taxi();
            double distance;
            cin >> distance;
            //
            taxi->setDistance(distance);
            passenger.addTransportation(taxi);
            //
            
        } else if (transportType == 'B') {
            BmtaBus *bus = new BmtaBus();
            //
            passenger.addTransportation(bus);
            //
            
        } else if (transportType == 'C') {
            BTS *bts = new BTS();
            int station;
            cin >> station;
            //
            bts->setStation(station);
            passenger.addTransportation(bts);
            //
            
        } else {
            break;
        }
    }
    cout << "Total Fare: " << passenger.getTotalFare() << endl;
}