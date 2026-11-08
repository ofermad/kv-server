#include "command.h"

#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>

namespace {
    std::vector<std::string> Split(std::string_view line) {
        std::istringstream stream{std::string(line)};
        std::vector<std::string> tokens;

        std::string word;

        while (stream >> word) {
            tokens.push_back(word);
        }

        return tokens;
    }
}


ParseResult ParseCommand(std::string_view line) {
    std::vector<std::string> tokens = Split(line);

    if (tokens.empty()) {
        return { std::nullopt, "empty string"};
    }

    std::string command_name = tokens[0];

    std::transform(command_name.begin(), command_name.end(), command_name.begin(), [](unsigned char c) { return static_cast<char>(std::toupper(c)); });

    if (command_name == "SET") {
        if (tokens.size() != 3) {
            return { std::nullopt, "wrong number of arguments for SET" };
        }

        return ParseResult{ Command{ Command::Type::Set, tokens[1], tokens[2] }, "" };
    }

    if (command_name == "GET") {
        if (tokens.size() != 2) {
            return { std::nullopt, "wrong number of arguments for GET" };
        }

        return ParseResult{ Command{ Command::Type::Get, tokens[1], "" }, "" };
    }

    if (command_name == "DEL") {
        if (tokens.size() != 2) {
            return { std::nullopt, "wrong number of arguments for DEL" };
        }

        return ParseResult{ Command{ Command::Type::Del, tokens[1], "" }, "" };
    }

    return { std::nullopt, "unknown command: " + tokens[0] };
}