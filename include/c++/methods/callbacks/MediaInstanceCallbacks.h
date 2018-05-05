namespace modio
{
struct AddModLogoCall
{
    const std::function<void(const modio::Response &)> callback;
};

struct AddModImagesCall
{
    const std::function<void(const modio::Response &)> callback;
};

struct AddModYoutubeLinksCall
{
    const std::function<void(const modio::Response &)> callback;
};

struct AddModSketchfabLinksCall
{
    const std::function<void(const modio::Response &)> callback;
};

extern std::map<u32, AddModLogoCall *> add_mod_logo_calls;
extern std::map<u32, AddModImagesCall *> add_mod_images_calls;
extern std::map<u32, AddModYoutubeLinksCall *> add_mod_youtube_links_calls;
extern std::map<u32, AddModSketchfabLinksCall *> add_mod_sketchfab_links_calls;

void onAddModLogo(void *object, ModioResponse modio_response);
void onAddModImages(void *object, ModioResponse modio_response);
void onAddModYoutubeLinks(void *object, ModioResponse modio_response);
void onAddModSketchfabLinks(void *object, ModioResponse modio_response);
}
