/* ====================================
 File name: exerc_3_1.c
 Date: 2021-02-04
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: []
 ====================================== */

#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 100 // Maximum grid size for the map

// Define variables
char welcomeMessage[] = "\n\n------------------------------\n  ~~~~ Welcome to Robot ~~~~\n------------------------------\n\nPlease enter a command: \nt > Turn\nm > Move\nq > Quit program\nh > Help\n\n";

// Cardinal directions
enum DIRECTION
{
    N = 0, // North
    S = 180, // South
    E = 90, // East
    W = 270 // West
};

// Define Robot structure
typedef struct ROBOT
{
    int xPos;
    int yPos;
    enum DIRECTION dir;
} ROBOT;

/* Declare methods */
/* Movement */
void move(struct ROBOT *); // Move the robot one space
void turn(struct ROBOT *); // Turn the robot 90 degrees clockwise

/* Utils */
void getLocation(struct ROBOT *);            // Get current x and y positions for robot
// int getPosX(struct ROBOT robot);                 // Get just the x position of the robot
// int getPosY(struct ROBOT robot);                 // Get just the y position of the robot
// enum DIRECTION getDirection(struct ROBOT robot); // Get direction the robot is facing
void handleCommand(const char command, struct ROBOT *);
void clear_stdin();

/* Init */
struct ROBOT initRobot(); // Initialize Robot with coords [x, y]

/* Main */
int main(void)
{
    printf(welcomeMessage);
    struct ROBOT *p_robot, robot; // Declare robot and pointer for robot
    robot = initRobot(); // Init robot
    p_robot = &robot; // Assign robot pointer
    printf("\nMy position: [%d, %d], facing %d degrees\n", p_robot->xPos, p_robot->yPos, (int) p_robot->dir);
    char input;
    while (1)
    {
        printf("\n>> ");
        scanf("%c", &input);
        clear_stdin();
        // Pass inputs to handler
        handleCommand(input, &robot);
    }
    return 0;
}

// Define methods

// Courtesy of exerc_2_8
void clear_stdin()
{
  while (getchar() != '\n')
  {
    ;
  }
}

// Initialize robot
struct ROBOT initRobot() {
    // Declare a generic robot
    struct ROBOT robot = {
        .xPos = 0,
        .yPos = 0,
        .dir = N
    };
    printf("Please enter the starting x coordinate for the Robot (0-99)\n>> ");
    scanf("%d", &robot.xPos);
    // Get user inputs, if they're too large make them MAP_SIZE
    if (robot.xPos > MAP_SIZE) {
        robot.xPos = MAP_SIZE;
    // or 0 for invalid inputs 
    } else if (robot.xPos < 0) {
        robot.xPos = 0;
    }
    clear_stdin();
    printf("Please enter the starting y coordinate for the Robot (0-99)\n>> ");
    scanf("%d", &robot.yPos);
    if (robot.yPos > MAP_SIZE) {
        robot.yPos = MAP_SIZE;
    } else if (robot.yPos < 0) {
        robot.yPos = 0;
    }
    clear_stdin();
    return robot;
}

// Handles robot direction
void turn(struct ROBOT *robot) {
    // Get the current direction, add 90, mod 360 to clamp between 0-359.
    robot->dir = (robot->dir + 90) % 360;
    printf("I'm facing %d degrees", (int) robot->dir);
}

// Handles robot movement
void move(struct ROBOT *robot) {
    // printf("I'm in the move function, location [%d, %d]\n", robot->xPos, robot->yPos);
    switch(robot->dir) {
        case N: // North -> Go up
            if (robot->yPos < MAP_SIZE) {
                robot->yPos++;
            } else {
                printf("I'm at a wall!\n");
            }
        break;

        case S: // South -> Go down
            if (robot->yPos > 0) {
                robot->yPos--;
            } else {
                printf("I'm at a wall!\n");
            }
        break;

        case E: // East -> Go right
            if (robot->xPos < MAP_SIZE) {
                robot->xPos++;
            } else {
                printf("I'm at a wall!\n");
            }
        break;

        case W: // West -> Go left
            if (robot->xPos > 0) {
                robot->xPos--;
            } else {
                printf("I'm at a wall!\n");
            }
        break;

        default: // Somehow discovered a new cardinal direction
            printf("Something went wrong here.\n");
            break;
    }
    printf("My location: [%d, %d]", robot->xPos, robot->yPos);
}

// Handle user inputs
void handleCommand(const char command, struct ROBOT *robot)
// TODO: Needed to pass robot pointer here to pass along to move() and turn(), may update.
{
    switch (command)
    {
    case 't': // Turn that bad boy like a pancake
        turn(robot); 
        break;

    case 'm': // Robot go vroom vroom
        move(robot); 
        break;

    case 'q': // Robot got boring
        printf("d[ o_0 ]b Beep boop\n");
        free(robot);
        exit(0);
        break;

    case 'h': // If remembering commands is difficult
        printf(welcomeMessage);
        break;

    default:
        printf("Invalid command.\n");
    }
}