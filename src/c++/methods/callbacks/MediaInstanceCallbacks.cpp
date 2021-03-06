#include "c++/methods/callbacks/MediaInstanceCallbacks.h"
#include "c++/schemas/Response.h"

namespace modio
{
std::map<u32, GenericCall *> add_mod_logo_calls;
std::map<u32, GenericCall *> add_mod_images_calls;
std::map<u32, GenericCall *> add_mod_youtube_links_calls;
std::map<u32, GenericCall *> add_mod_sketchfab_links_calls;
std::map<u32, GenericCall *> delete_mod_images_calls;
std::map<u32, GenericCall *> delete_mod_youtube_links_calls;
std::map<u32, GenericCall *> delete_mod_sketchfab_links_calls;

void onAddModLogo(void *object, ModioResponse modio_response)
{
  u32 call_id = (u32)((uintptr_t)object);

  modio::Response response;
  response.initialize(modio_response);

  add_mod_logo_calls[call_id]->callback(response);

  delete add_mod_logo_calls[call_id];
  add_mod_logo_calls.erase(call_id);
}

void onAddModImages(void *object, ModioResponse modio_response)
{
  u32 call_id = (u32)((uintptr_t)object);

  modio::Response response;
  response.initialize(modio_response);

  add_mod_images_calls[call_id]->callback(response);

  delete add_mod_images_calls[call_id];
  add_mod_images_calls.erase(call_id);
}

void onAddModYoutubeLinks(void *object, ModioResponse modio_response)
{
  u32 call_id = (u32)((uintptr_t)object);

  modio::Response response;
  response.initialize(modio_response);

  add_mod_youtube_links_calls[call_id]->callback(response);

  delete add_mod_youtube_links_calls[call_id];
  add_mod_youtube_links_calls.erase(call_id);
}

void onAddModSketchfabLinks(void *object, ModioResponse modio_response)
{
  u32 call_id = (u32)((uintptr_t)object);

  modio::Response response;
  response.initialize(modio_response);

  add_mod_sketchfab_links_calls[call_id]->callback(response);

  delete add_mod_sketchfab_links_calls[call_id];
  add_mod_sketchfab_links_calls.erase(call_id);
}

void onDeleteModImages(void *object, ModioResponse modio_response)
{
  u32 call_id = (u32)((uintptr_t)object);

  modio::Response response;
  response.initialize(modio_response);

  delete_mod_images_calls[call_id]->callback(response);

  delete delete_mod_images_calls[call_id];
  delete_mod_images_calls.erase(call_id);
}

void onDeleteModYoutubeLinks(void *object, ModioResponse modio_response)
{
  u32 call_id = (u32)((uintptr_t)object);

  modio::Response response;
  response.initialize(modio_response);

  delete_mod_youtube_links_calls[call_id]->callback(response);

  delete delete_mod_youtube_links_calls[call_id];
  delete_mod_youtube_links_calls.erase(call_id);
}

void onDeleteModSketchfabLinks(void *object, ModioResponse modio_response)
{
  u32 call_id = (u32)((uintptr_t)object);

  modio::Response response;
  response.initialize(modio_response);

  delete_mod_sketchfab_links_calls[call_id]->callback(response);

  delete delete_mod_sketchfab_links_calls[call_id];
  delete_mod_sketchfab_links_calls.erase(call_id);
}

void clearMediaRequestCalls()
{
  for (auto add_mod_logo_call : add_mod_logo_calls)
    delete add_mod_logo_call.second;
  add_mod_logo_calls.clear();

  for (auto add_mod_images_call : add_mod_images_calls)
    delete add_mod_images_call.second;
  add_mod_images_calls.clear();

  for (auto add_mod_youtube_links_call : add_mod_youtube_links_calls)
    delete add_mod_youtube_links_call.second;
  add_mod_youtube_links_calls.clear();

  for (auto add_mod_sketchfab_links_call : add_mod_sketchfab_links_calls)
    delete add_mod_sketchfab_links_call.second;
  add_mod_sketchfab_links_calls.clear();

  for (auto delete_mod_images_call : delete_mod_images_calls)
    delete delete_mod_images_call.second;
  delete_mod_images_calls.clear();

  for (auto delete_mod_youtube_links_call : delete_mod_youtube_links_calls)
    delete delete_mod_youtube_links_call.second;
  delete_mod_youtube_links_calls.clear();

  for (auto delete_mod_sketchfab_links_call : delete_mod_sketchfab_links_calls)
    delete delete_mod_sketchfab_links_call.second;
  delete_mod_sketchfab_links_calls.clear();
}
} // namespace modio
