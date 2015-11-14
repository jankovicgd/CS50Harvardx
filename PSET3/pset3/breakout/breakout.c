//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// height and width of paddle
#define PHEIGHT 10
#define PWIDTH 80

// height and width of brick
#define BHEIGHT 10
#define BWIDTH 35

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // scoreboard text;
    char text[2];
    
    // broken bricks
    int brokenbricks = 0;
    
    // velocity of ball
    double VELOCITYX = drand48()*0.05;
    double VELOCITYY = 0.1;
   
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle)/2;
                setLocation(paddle, x , HEIGHT - PHEIGHT * 5);
            }
        }
        move(ball, VELOCITYX, VELOCITYY);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            VELOCITYX = -VELOCITYX;
        }

        // bounce off left edge of window
        if (getX(ball) <= 0)
        {
            VELOCITYX = -VELOCITYX;
        }
        
        // bounce the ball of bottom edge
        if (getY(ball) + getWidth(ball) >= getHeight(window))
        {
            drawAt(window, ball, WIDTH/2 - RADIUS/2 , HEIGHT/2 - RADIUS/2);
            pause(1000);
            lives --;
        }
        
        // bounce off top edge of window
        if (getY(ball) <= 0)
        {
            VELOCITYY = -VELOCITYY;
        }
        
        // bounce ball of paddle and bricks
        GObject object = detectCollision(window, ball);
        if (detectCollision(window, ball) != NULL)
        {
            if (strcmp(getType(object), "GRect") == 0)
            {
                VELOCITYY = -VELOCITYY;
                
                
                if (object != paddle)
                {
                    removeGWindow(window, object);
                    brokenbricks ++;
                    bricks --;
                    sprintf(text, "%i", brokenbricks);
                    setLabel(label, text);
                }
            }
        }
    }
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect(2.5 + j * 40, 50 + i * 15, BWIDTH, BHEIGHT);
            add(window, brick);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH/2 - RADIUS/2 , HEIGHT/2 - RADIUS/2, RADIUS, RADIUS);
    add(window, ball);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(WIDTH / 2 - PWIDTH/2, HEIGHT - PHEIGHT * 5, PWIDTH, PHEIGHT);
    add(window, paddle);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    add(window, label);
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
