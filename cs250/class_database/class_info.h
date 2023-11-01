#define MAX_DEPARTMENT_LENGTH 8
#define MAX_COURSE_NUMBER_LENGTH 8
#define MAX_COURSE_LOCATION_LENGTH 32

typedef struct class_info {
	char department[MAX_DEPARTMENT_LENGTH];
	char number[MAX_COURSE_NUMBER_LENGTH];
	char location[MAX_COURSE_LOCATION_LENGTH];
} class_info_t;
