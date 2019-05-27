#include <stdbool.h>
#include "c/ModioC.h"
#include <stdio.h>

void onAddModImages(void *object, ModioResponse response)
{
  bool *wait = object;
  printf("Add mod images response: %i\n", response.code);
  if (response.code == 201)
  {
    printf("Mod images added successfully!\n");
  }
  *wait = false;
}

int main(void)
{
  modioInit(MODIO_ENVIRONMENT_TEST, 7, "e91c01b8882f4affeddd56c96111977b", NULL);

  bool wait = true;

  // Let's start by requesting a single mod
  printf("Please enter the mod id: \n");
  u32 mod_id;
  scanf("%i", &mod_id);

  char const *images_array[1];
  images_array[0] = "../ModExample/logo.png";

  printf("Getting mod...\n");
  modioAddModImages(&wait, mod_id, images_array, 1, &onAddModImages);

  while (wait)
  {
    modioProcess();
  }

  modioShutdown();

  printf("Process finished\n");

  return 0;
}
