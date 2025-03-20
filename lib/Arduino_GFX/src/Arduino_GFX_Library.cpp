#include "Arduino_GFX_Library.h"

Arduino_DataBus *create_default_Arduino_DataBus()
{
  return NULL;
}

Arduino_GFX *create_default_Arduino_GFX()
{
  Arduino_DataBus *bus = create_default_Arduino_DataBus();
  return NULL;
}
