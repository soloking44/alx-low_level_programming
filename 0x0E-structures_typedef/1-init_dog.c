#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - a function that initialize a variable of type struct dog
 *
 * @d: the struct pointer.
 * @name: pointer to the Dog's name
 * @age: pointer to the Dog's age
 * @owner: pointer to the dog's owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
