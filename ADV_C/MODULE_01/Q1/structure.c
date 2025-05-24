#include <stdio.h>
#include <string.h>

#define MAX_TASKS 3
#define MAX_LEN 50
#define DAYS_IN_WEEK 7

// Structure for a day
typedef struct {
    char dayName[MAX_LEN];
    char tasks[MAX_TASKS][MAX_LEN];
    int taskCount;
} Day;

// Function prototypes
void initializeWeek(Day week[]);
int findDayIndex(Day week[], const char *name);
void addTasks(Day week[]);
void displayTasks(Day week[]);

int main() {
    Day week[DAYS_IN_WEEK];
    int choice;

    initializeWeek(week);

    do {
        printf("\n1. Add tasks to a day\n2. Display all tasks\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline after scanf

        switch (choice) {
            case 1:
                addTasks(week);
                break;
            case 2:
                displayTasks(week);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}

// Initialize week with day names
void initializeWeek(Day week[]) {
    const char *names[DAYS_IN_WEEK] = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };

    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        strcpy(week[i].dayName, names[i]);
        week[i].taskCount = 0;
    }
}

// Find day index by name
int findDayIndex(Day week[], const char *name) {
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        if (strcasecmp(week[i].dayName, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Add tasks to a given day
void addTasks(Day week[]) {
    char dayInput[MAX_LEN];
    int idx;

    printf("Enter day name: ");
    fgets(dayInput, MAX_LEN, stdin);
    dayInput[strcspn(dayInput, "\n")] = 0;  // Remove newline

    idx = findDayIndex(week, dayInput);
    if (idx == -1) {
        printf("Invalid day name.\n");
        return;
    }

    Day *d = &week[idx];
    if (d->taskCount >= MAX_TASKS) {
        printf("Maximum tasks already added for %s.\n", d->dayName);
        return;
    }

    int tasksToAdd = MAX_TASKS - d->taskCount;
    printf("You can add up to %d more task(s) for %s.\n", tasksToAdd, d->dayName);

    for (int i = 0; i < tasksToAdd; ++i) {
        printf("Enter task %d (or type 'done' to stop): ", d->taskCount + 1);
        fgets(d->tasks[d->taskCount], MAX_LEN, stdin);
        d->tasks[d->taskCount][strcspn(d->tasks[d->taskCount], "\n")] = 0;

        if (strcmp(d->tasks[d->taskCount], "done") == 0)
            break;

        d->taskCount++;
    }
}

// Display all tasks grouped by day
void displayTasks(Day week[]) {
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        printf("\n%s:\n", week[i].dayName);
        if (week[i].taskCount == 0) {
            printf("  No tasks added.\n");
        } else {
            for (int j = 0; j < week[i].taskCount; ++j) {
                printf("  - %s\n", week[i].tasks[j]);
            }
        }
    }
}
