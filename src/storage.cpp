#include "storage.h"

#include <utility>

void Storage::Set(std::string key, std::string value) {
    data_[std::move(key)] = std::move(value);
}

std::optional<std::string> Storage::Get(const std::string& key) const {
    const auto it = data_.find(key);
    if (it == data_.end()) {
        return std::nullopt;
    }
    return it->second;
}

bool Storage::Del(const std::string& key) {
    return data_.erase(key) > 0;
}