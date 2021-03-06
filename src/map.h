#pragma once

#include <vector>

#include "cell.h"
#include "environment.h"
class cell_t; // FORWARD DECLARE CELL

class map_t
{
public:
    map_t(std::shared_ptr<config_t> config);
    map_t();

    // std::shared_ptr<map_t> generate_map_f();
    std::unique_ptr<map_t> generate_map_f();
    void render_map_f(SDL_Renderer *renderer);

    void calculate_cells_f();
    void print_config_f();

    std::shared_ptr<std::map<cords_t, environment_t>> env_map_;
    std::shared_ptr<std::map<cords_t, cell_t>> cell_map_;

private:
    std::shared_ptr<std::map<cords_t, environment_t>> generate_env_f();
    std::shared_ptr<std::map<cords_t, cell_t>> generate_cells_f();

    void render_env_f(SDL_Renderer *renderer);
    void render_cells_f(SDL_Renderer *renderer);

    std::shared_ptr<config_t> config_;
};

inline bool operator < (const cords_t &l, const cords_t &r)
{
    return (l.x_ < r.x_ || (l.x_ == r.x_ && l.y_ < r.y_));
}