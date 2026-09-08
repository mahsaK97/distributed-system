#pragma once

#include <string>


struct LogEntry
{
    int index;
    int term;
    std::string command;
};
