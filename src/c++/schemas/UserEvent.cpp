#include "c++/schemas/UserEvent.h"
#include "c/ModioC.h"                      // for ModioUserEvent
#include "dependencies/nlohmann/json.hpp"  // for json

namespace modio
{
void UserEvent::initialize(ModioUserEvent modio_event)
{
  id = modio_event.id;
  game_id = modio_event.game_id;
  mod_id = modio_event.mod_id;
  user_id = modio_event.user_id;
  event_type = modio_event.event_type;
  date_added = modio_event.date_added;
}

nlohmann::json toJson(UserEvent &event)
{
  nlohmann::json event_json;

  event_json["id"] = event.id;
  event_json["game_id"] = event.game_id;
  event_json["mod_id"] = event.mod_id;
  event_json["user_id"] = event.user_id;
  event_json["event_type"] = event.event_type;
  event_json["date_added"] = event.date_added;

  return event_json;
}
} // namespace modio
