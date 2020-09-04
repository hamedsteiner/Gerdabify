
#ifndef QUEUEPLACE_H
#define QUEUEPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
//#include "list_user.h"
//#include "database.h"
#include "place.h"
#include "queue.h"

using namespace std;

class QueuePlace :public Place
{
public:
	QueuePlace();
	void set_queue(Queue* _pointed_queue){ pointed_queue= _pointed_queue;}
	Queue* get_queue(){return pointed_queue;}
	string getName();

	string getCompleteName();

protected:
	Queue* pointed_queue;

};



#endif //QUEUEPLACE_H