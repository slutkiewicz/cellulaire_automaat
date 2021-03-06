#pragma once

#include "render_object.h"
#include "utills.h"

class environment_t : public render_object_t
{

public:
    void draw_f(SDL_Renderer *renderer);
    environment_t(std::shared_ptr<config_t> config, cords_t cordinates) : render_object_t(config, cordinates){};
    ENV state_ = ENV::SAND;
};