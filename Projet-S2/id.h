#ifndef OBSTACLEID_H
#define OBSTACLEID_H

class ObstacleID
{
public:
	ObstacleID();
	ObstacleID(int id, bool isTaken);
	~ObstacleID();

	bool isTaken() { return _isTaken; }
	int get_id() { return _id; }
	void set_id(int id);
	void set_taken(bool taken);

private:
	int _id;
	bool _isTaken;
};

#endif