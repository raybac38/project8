
enum EventType
{
    Update,
    Exit
};

// Initialise l'event manager
void EventManagerInit(void);
// Ferme l'event manager
void EventManagerExit(void);

// Ajout d'une tach dans la file
void EventManagerAddTask(void (*f) (void));
// Ajout d'une tach dans la file de fermeture
void EventManagerAddExitTask(void (*f) (void));

// Execution de la routine
void EventManagerRuntime();
