#include "c/schemas/ModioLogo.h"
#include "Utility.h"                // for hasKey
#include "c/ModioC.h"               // for ModioDownload

extern "C"
{
  void modioInitLogo(ModioLogo* logo, nlohmann::json logo_json)
  {
    logo->filename = NULL;
    if(modio::hasKey(logo_json, "filename"))
    {
      std::string filename_str = logo_json["filename"];
      logo->filename = new char[filename_str.size() + 1];
      strcpy(logo->filename, filename_str.c_str());
    }

    logo->original = NULL;
    if(modio::hasKey(logo_json, "original"))
    {
      std::string original_str = logo_json["original"];
      logo->original = new char[original_str.size() + 1];
      strcpy(logo->original, original_str.c_str());
    }

    logo->thumb_320x180 = NULL;
    if(modio::hasKey(logo_json, "thumb_320x180"))
    {
      std::string thumb_320x180_str = logo_json["thumb_320x180"];
      logo->thumb_320x180 = new char[thumb_320x180_str.size() + 1];
      strcpy(logo->thumb_320x180, thumb_320x180_str.c_str());
    }

    logo->thumb_640x360 = NULL;
    if(modio::hasKey(logo_json, "thumb_640x360"))
    {
      std::string thumb_640x360_str = logo_json["thumb_640x360"];
      logo->thumb_640x360 = new char[thumb_640x360_str.size() + 1];
      strcpy(logo->thumb_640x360, thumb_640x360_str.c_str());
    }

    logo->thumb_1280x720 = NULL;
    if(modio::hasKey(logo_json, "thumb_1280x720"))
    {
      std::string thumb_1280x720_str = logo_json["thumb_1280x720"];
      logo->thumb_1280x720 = new char[thumb_1280x720_str.size() + 1];
      strcpy(logo->thumb_1280x720, thumb_1280x720_str.c_str());
    }
  }

  void modioInitLogoCpp(ModioLogo* modio_logo, modio::Logo* logo)
  {
    modio_logo->filename = new char[logo->filename.size() + 1];
    strcpy(modio_logo->filename, logo->filename.c_str());

    modio_logo->original = new char[logo->original.size() + 1];
    strcpy(modio_logo->original, logo->original.c_str());

    modio_logo->thumb_320x180 = new char[logo->thumb_320x180.size() + 1];
    strcpy(modio_logo->thumb_320x180, logo->thumb_320x180.c_str());

    modio_logo->thumb_640x360 = new char[logo->thumb_640x360.size() + 1];
    strcpy(modio_logo->thumb_640x360, logo->thumb_640x360.c_str());

    modio_logo->thumb_1280x720 = new char[logo->thumb_1280x720.size() + 1];
    strcpy(modio_logo->thumb_1280x720, logo->thumb_1280x720.c_str());
  }

  void modioFreeLogo(ModioLogo* logo)
  {
    if(logo)
    {
      if(logo->filename)
        delete[] logo->filename;
      if(logo->original)
        delete[] logo->original;
      if(logo->thumb_320x180)
        delete[] logo->thumb_320x180;
      if(logo->thumb_640x360)
        delete[] logo->thumb_640x360;
      if(logo->thumb_1280x720)
        delete[] logo->thumb_1280x720;
    }
  }
}
