#ifndef _mymap_H_
#define _mymap_H_
#include<string>
#include "room.h"
#include <vector>
#include <string>
#include "room.h"
using namespace std;
class mymap{
    friend class hero;
public:
    mymap(int difficult);
    void roominfo(int roomnum);
    int check_mon(int roomnum);
    int check_room_status(int roomnum);
    int roomnumber() const;
    string getstair();
    void findp();
    room* getroom(int roomnum) const;
    int getprinroom() const;

    ~mymap();
private:
    vector<room *> rooms;
    int room_num;
    int princes;
    vector<int> stair;
    int stair_num;
};
#endif