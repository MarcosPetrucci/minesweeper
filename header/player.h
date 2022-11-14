#ifndef player_H
#define player_H

class player
{
private:
    bool is_alive;
    int remaining_flags;
public:
    player(int qtt_mines);
    ~player();
    void kill_player();
    void flag_positioned();
    void take_flag_back();
};

#endif