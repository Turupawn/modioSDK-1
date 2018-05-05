#include "c/methods/callbacks/MediaCallbacks.h"

std::map< u32, AddModLogoParams* > add_mod_logo_callbacks;
std::map< u32, AddModImagesParams* > add_mod_images_callbacks;
std::map< u32, AddModYoutubeLinksParams* > add_mod_youtube_links_callbacks;
std::map< u32, AddModSketchfabLinksParams* > add_mod_sketchfab_links_callbacks;

void modioOnAddModLogo(u32 call_number, u32 response_code, json response_json)
{
  ModioResponse response;
  modioInitResponse(&response, response_json);
  response.code = response_code;

  add_mod_logo_callbacks[call_number]->callback(add_mod_logo_callbacks[call_number]->object, response);
  delete add_mod_logo_callbacks[call_number];
  add_mod_logo_callbacks.erase(call_number);

  modioFreeResponse(&response);
}

void modioOnAddModImages(u32 call_number, u32 response_code, json response_json)
{
  ModioResponse response;
  modioInitResponse(&response, response_json);
  response.code = response_code;

  add_mod_images_callbacks[call_number]->callback(add_mod_images_callbacks[call_number]->object, response);
  delete add_mod_images_callbacks[call_number];
  add_mod_images_callbacks.erase(call_number);

  modioFreeResponse(&response);
}

void modioOnAddModYoutubeLinks(u32 call_number, u32 response_code, json response_json)
{
  ModioResponse response;
  modioInitResponse(&response, response_json);
  response.code = response_code;

  add_mod_youtube_links_callbacks[call_number]->callback(add_mod_youtube_links_callbacks[call_number]->object, response);
  delete add_mod_youtube_links_callbacks[call_number];
  add_mod_youtube_links_callbacks.erase(call_number);

  modioFreeResponse(&response);
}

void modioOnAddModSketchfabLinks(u32 call_number, u32 response_code, json response_json)
{
  ModioResponse response;
  modioInitResponse(&response, response_json);
  response.code = response_code;

  add_mod_sketchfab_links_callbacks[call_number]->callback(add_mod_sketchfab_links_callbacks[call_number]->object, response);
  delete add_mod_sketchfab_links_callbacks[call_number];
  add_mod_sketchfab_links_callbacks.erase(call_number);

  modioFreeResponse(&response);
}
