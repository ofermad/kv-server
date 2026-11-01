#pragma once

#include <optional>
#include <string>
#include <unordered_map>

class Storage {
    public:
        void Set(std::string key, std::string value);
        std::optional<std::string> Get(const std::string& key) const;
        bool Del(const std::string& key);

    private:
        std::unordered_map<std::string, std::string> data_;
};