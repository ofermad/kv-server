## Ошибки

## nullptr вместо std::nullopt · 2026-11-01
**1. В src/storage.cpp функция std::optional<std::string> Storage::Get return был nullptr, поменял на std::nullopt. Так как nullptr превращается в const char\* и появляется std::string - неопределенное поведение.**  
**Правильно:**
```cpp
if (it == data_.end()) {
    return std::nullopt;
}
```

## Парсер команд · 2026-11-08
**1. У GET и DEL проверка tokens.size() != 3, нужно != 2 (скопировал ветку SET). 2. Функция называлась ParserCommand в заголовке и ParseCommand в cpp. 3. std::toupper вернул int без static_cast<char>. 4. Тесты ошибок не проверяли отсутствие command.**