#ifndef OBSTACLEID_H
#define OBSTACLEID_H

class ObstacleID
{
public:
	/**
	 * @brief      Unused constructor
	 */
	ObstacleID();

	/**
	 * @brief      Create an obstacle object with....
	 *
	 * @param[in]  id       ID of the obstacle (easier to detect the object later)
	 * @param[in]  isTaken  Current state of the obstacle
	 */
	ObstacleID(int id, bool isTaken);

	/**
	 * @brief      Deconstructor
	 */
	~ObstacleID();

	/**
	 * @brief      Look to see if the object is taken
	 *
	 * @return     True or false if taken or not
	 */
	bool isTaken() { return _isTaken; }

	/**
	 * @brief      Get the current id of the obstacle
	 *
	 * @return     Return the global class id
	 */
	int get_id() { return _id; }

	/**
	 * @brief      Set the a id
	 *
	 * @param[in]  id    Return the set id
	 */
	void set_id(int id);

	/**
	 * @brief      Set the current id to taken or not
	 *
	 * @param[in]  taken  Return the state of the taken id
	 */
	void set_taken(bool taken);

private:
	int _id;
	bool _isTaken;
};

#endif