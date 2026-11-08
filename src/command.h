#pragma once

#include <string>
#include <string_view>
#include <optional>

struct Command {
    enum class Type {Set, Get, Del};

    Type type;
    std::string key;
    std::string value;
};

struct ParseResult {
    std::optional<Command> command;
    std::string error;
};

ParseResult ParseCommand(std::string_view line);