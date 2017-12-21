#ifndef MODIO_MODIORATINGSUMMARY_H
#define MODIO_MODIORATINGSUMMARY_H

#include "dependencies/json/json.hpp"
#include "Utility.h"
;
using json = nlohmann::json;

extern "C"
{
  struct ModioRatingSummary
  {
    u32 total_ratings;
    u32 positive_ratings;
    u32 negative_ratings;
    u32 percentage_positive;
    double weighted_aggregate;
    char* display_text;
  };

  void modioInitRatingSummary(ModioRatingSummary* ratings, json ratings_json);
  void modioFreeRatingSummary(ModioRatingSummary* ratings);
}

#endif