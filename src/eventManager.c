#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 255

typedef void (*function)(void);

static function * QUEUE;
static function * first_task;
static function * last_task;
static function * EXIT_QUEUE;
static function * last_exit_queue;

static bool runtime = true;
static int number_of_task = 0;
static int number_of_exit_task = 0;

//  Gestionnaire de liste pour event manager

//Précondition : la file n'est pas pleine
void list_append(function f)
{
    if(last_task + 1 > QUEUE + QUEUE_SIZE)
    {
        last_task = QUEUE;
    }
    *(last_task)++ = f;
}

///

void EventManagerAddTask(void (* f)(void))
{
    printf("Function added\n");
    if(number_of_task > QUEUE_SIZE)
    {
        //Overflow
        printf("Error : to much task waiting\n");
        exit(EXIT_FAILURE);
    }
	number_of_task++;
    list_append((function)f);
}
void EventManagerAddExitTask(void (* f)(void))
{
    if(number_of_exit_task > QUEUE_SIZE)
    {
        //Overflow
        printf("Error : to much task waiting\n");
        exit(EXIT_FAILURE);
    }
    *(last_exit_queue)++ = (function)f;
}

void EventManagerRuntime()
{
    while(runtime)
    {
        (*first_task)();
        first_task++;
        if(first_task + 1 > QUEUE + QUEUE_SIZE)
        {
            first_task = QUEUE;
        }
	number_of_task--;
    }
}

void EventManagerInit()
{
    QUEUE = malloc(sizeof(function) * QUEUE_SIZE);
    EXIT_QUEUE = malloc(sizeof(function) * QUEUE_SIZE);

    last_exit_queue = EXIT_QUEUE;
    last_task = QUEUE;
    first_task = QUEUE;
}

void EventManagerExit()
{
    runtime = false;
    free(QUEUE);
    free(EXIT_QUEUE);
}
