## Ошибки

В src/storage.cpp функция std::optional<std::string> Storage::Get return был nullptr, поменял на std::nullopt. Так как nullptr превращается в const char* и появляется std::string.