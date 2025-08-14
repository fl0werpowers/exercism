#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
	robot_status_t robot;

	robot.direction = direction;
	robot.position = (robot_position_t) {.x = x, .y = y };
	return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
	int idx;

	idx = 0;
	while (commands[idx])
	{
		switch (commands[idx])
		{
			case 'L': robot->direction = 
				robot->direction == DIRECTION_NORTH 
				? DIRECTION_WEST : robot->direction - 1; break;
			case 'R': robot->direction =
				robot->direction == DIRECTION_WEST
				? DIRECTION_NORTH : robot->direction + 1; break;
			case 'A': {
				switch (robot->direction)
				{
					case DIRECTION_NORTH: robot->position.y += 1; break;
					case DIRECTION_SOUTH: robot->position.y -= 1; break;
					case DIRECTION_EAST: robot->position.x += 1; break;
					case DIRECTION_WEST: robot->position.x -= 1; break;
					default: break;
				}
			}
			default: break;
		}
		idx++;
	}
}
