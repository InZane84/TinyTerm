#ifndef TINYTERM_H
#define TINYTERM_H

#include "engine.h"
#include "entity_store.h"
#include <cstdarg>

class TinyTerm : public Engine::Engine {

public:
    TinyTerm(bool debug_mode) : Engine::Engine() { m_debug_mode = debug_mode; }

    // Members:
    bool m_debug_mode;

    EntityStore::Player m_player = EntityStore::Player("player", std::pair<int, int> { 12, 20 });
    EntityStore::Grass m_grass = EntityStore::Grass("grass", std::pair{ 10, 10 });

    std::pair<int, int> m_main_window_size, m_text_window_size, m_debug_window_size;

    WINDOW *p_m_main_window, *p_m_text_window, *p_m_debug_window;

    // Life Cycles:
    void on_create() override;

    void on_update() override;

    // Utilities:
    void initialize_windows();

    void print_debug(const std::vector<std::string> &args, int column, int line);

    void debug_player_position();
};

#endif
