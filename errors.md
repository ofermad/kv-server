## Ошибки

## nullptr вместо std::nullopt · 2026-11-01
**1. В src/storage.cpp функция std::optional<std::string> Storage::Get return был nullptr, поменял на std::nullopt. Так как nullptr превращается в const char\* и появляется std::string - неопределенное поведение.**  
**Правильно:**
```cpp
if (it == data_.end()) {
    return std::nullopt;
}
```
