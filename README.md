# MyCat
Написанный **мною** (уже прорыв) кое-как аналог cat из unix-like систем на C++

## Использование
```
mycat [-n] [-s] [-h] файл...
```
- `-n` нумеровать строки
- `-s` вывести общее число строк в конце
- `-h` показать справку

Флаги можно комбинировать, файлов можно указывать несколько. \
Чтения из stdin пока нет!!!

<img width="800" height="400" alt="usage example" src="https://github.com/user-attachments/assets/85ea14f2-c58a-4ef9-b80c-95c6564c6c4e" />

## Сборка
### Unix-подобные системы (Linux, BSD, macOS)
```bash
g++ -Wall -Wextra -Wpedantic -std=c++20 mycat.cpp -o mycat
```

### Windows (MSVC)
Запускай из Developer Command Prompt for VS:
```powershell
cl /EHsc /W4 /std:c++20 /O2 mycat.cpp
```
