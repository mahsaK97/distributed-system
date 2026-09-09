#pragma once

class VirtualClock
{
public:
    VirtualClock();


    void tick();
    int now () const;
    void reset();

private:
    int currentTiime;
};
